#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    aptmirror = new AptMirror(this);
    fileName = "";
    ruta = "";
    nthread = "20";
    limitrate = "100";
    mirrorchanged = false;
    tabdisable = false;
    confd = new ConfigDialog(this);
    confd->setWindowTitle(QString::fromUtf8("Sheldon::Configuración"));
    infd = new InfoDialog(this);
    infd->setWindowTitle(QString::fromUtf8("Sheldon::Acerca de..."));
    helpd = new HelpDialog(this);
    helpd->setWindowTitle(QString::fromUtf8("Sheldon::Ayuda"));
    connect(&terminal, SIGNAL(readyReadStandardOutput()),this, SLOT(readFromStdout()));
    connect(&terminal,SIGNAL(readyReadStandardError()),this,SLOT(readFromStderror()));
    connect(&terminal,SIGNAL(error(QProcess::ProcessError)),this,SLOT(onError(QProcess::ProcessError)));
    connect(&terminal,SIGNAL(started()),this,SLOT(onStarted()));
    connect(&terminal,SIGNAL(finished(int,QProcess::ExitStatus)),this,SLOT(onFinished(int,QProcess::ExitStatus)));
    connect(ui->mirrortodownload,SIGNAL(textChanged()),this,SLOT(onMirrorChange()));
    ui->tabWidget->setCurrentIndex(0);
    ui->tabWidget->setTabEnabled(1,false);
    ui->mirrortodownload->hide();
    ui->label_2->hide();
    ui->label_4->setText("Seleccione la carpeta donde va a almacenar el/los repositorio(s)...");
    ui->btnApply->setEnabled(false);
    ui->mirrortodownload->setEnabled(false);
    ui->pathtosave->setReadOnly(true);
    this->setFixedSize(705,470);
}

MainWindow::~MainWindow()
{
    delete ui;
    if(terminal.state() == QProcess::Running)
    {
        terminal.kill();
        QString pkillall = "killall";
        QStringList parameters;
        parameters<<"-r"<<"wget";
        killall.start(pkillall,parameters);
    }

}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
void MainWindow::openmirriorlistfromfile()
{
    QString sruta = "/etc/apt/sources.list";
    QFile file(sruta);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("Sheldon"),
                             tr("No se puede leer el archivo %1:\n%2.\n.")
                             .arg(sruta)
                             .arg(file.errorString()));
        return;
    }
    QTextStream in(&file);
    QString line = "";
    line = in.readAll();
    QStringList linelist = line.split("\n");
    for (int i = 0; i < linelist.size(); i++)
    {
        ui->mirrortodownload->append(linelist.at(i));
    }
}

bool MainWindow::openmirriorlistSettings(QString path)
{
    QFile file(path + "/mirror.list");
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        return false;
    }

    QTextStream in(&file);
    QRegExp rent("set\\s+nthreads\\s+(\\d+)");
    QRegExp relr("set\\s+limit_rate\\s+(\\d+)[bkmgt]");
    QRegExp redeb("^deb");
    int index = 0;

    while(!in.atEnd())
    {
        QString line = in.readLine();
        if((index = rent.indexIn(line)) != -1)
        {
            nthread = rent.cap(1);
        }
        else if((index = relr.indexIn(line)) != -1)
        {
            limitrate = relr.cap(1);
        }
        else if((index = redeb.indexIn(line)) != -1)
        {
            ui->mirrortodownload->append(line);
        }

    }
    return true;
}

void MainWindow::readFromStdout()\
{
    /*
     *HACER ALGO CON ESTO
     *863.5 MiB will be downloaded into archive.

    QString str(m_process.readAllStandardOutput().constData());

    QRegExp rx("(\\d+\\.\\d+ [kMG]B).{,3}(\\d+\\.\\d+ [kMG]B).{,2}(\\d+\\.\\d+ [kMG]B/s).{,2}(\\d{1,2}:\\d{1,2}:\\d{1,2})");
    if (rx.indexIn(str) != -1)
    {
        QStringList data    = rx.capturedTexts();
        m_downloadedSize    = data.at(1);
        m_totalSize         = data.at(2);
        m_connSpeed         = data.at(3);
        m_timeRemaining     = data.at(4);

        emit downloadInfoChanged(m_url);
    }
}
     */
    ui->output->append(terminal.readAll());
}
void MainWindow::readFromStderror()
{
    ui->output->append(terminal.readAllStandardError());
}

void MainWindow::on_btnBrowse_clicked()
{
    QString setpath = QFileDialog::getExistingDirectory(this,"Guardar en:",".");
    if(setpath != "")
    {
        ui->pathtosave->setText(setpath);
        if(!mirrorchanged)
        {
            ui->label_4->hide();
            ui->mirrortodownload->show();
            ui->label_2->show();
            ui->mirrortodownload->setEnabled(true);
            ui->btnApply->setEnabled(true);
            if(!openmirriorlistSettings(setpath))
            {
                openmirriorlistfromfile();
            }
        }
    }
}

void MainWindow::on_btnApply_clicked()
{

    ui->output->clear();
    ruta = ui->pathtosave->text();
    aptmirror->setRuta(ruta);
    aptmirror->setLimitrate(limitrate);
    aptmirror->setNthread(nthread);
    aptmirror->setRepos(ui->mirrortodownload->document()->toPlainText());
    if(QMessageBox::information(this,"Sheldon::INFO",
                                "Se descargaran las siguientes URI:\n"+aptmirror->getRepos()+
                                "y se guardaran en "+ruta+"...",
                                QMessageBox::Cancel,QMessageBox::Ok) == QMessageBox::Ok)
    {
        aptmirror->makeFile();
        ui->tabWidget->setTabEnabled(1,true);
        ui->tabWidget->setCurrentIndex(1);
        tabdisable = true;
    }
//        else
//        {
//            writefile.remove(fileName);
//        }
}

void MainWindow::on_btnStart_clicked()
{
    QDir rutaDir(ruta);
    rutaDir.mkdir("skel");
    rutaDir.mkdir("var");

    QFile cppostmirror("/var/spool/apt-mirror/var/postmirror.sh");
    if(!cppostmirror.copy(cppostmirror.fileName(),ruta +"/var/postmirror.sh"))
    {
        ui->btnStart->setEnabled(true);
        return;
    }
    QString paptmirror ="apt-mirror";
    QStringList commandAndParametersaptmirror;
    commandAndParametersaptmirror<<aptmirror->getFileName();
    terminal.start(paptmirror,commandAndParametersaptmirror);

}

void MainWindow::on_btnStop_clicked()
{
    if(terminal.state() == QProcess::Running)
    {
        terminal.terminate();
        QString pkillall = "killall";
        QStringList parameters;
        parameters<<"-r"<<"wget";
        killall.start(pkillall,parameters);
        ui->btnStart->setEnabled(true);
        QMessageBox::information(this,"Sheldon::INFO",QString::fromUtf8("Ha detenido la aplicación y no ha terminado de descargar..."),QMessageBox::Ok);
    }
}

void MainWindow::onError(QProcess::ProcessError error)
{
    if (error == QProcess::FailedToStart) {
            QMessageBox::information(this,"Sheldon::ERROR",QString::fromUtf8("No se ha podido iniciar apt-mirror"),QMessageBox::Ok);
            ui->btnStart->setEnabled(true);
        }

}
void MainWindow::onStarted()
{
    ui->btnStart->setEnabled(false);
    ui->tabWidget->setTabEnabled(0,false);
}
void MainWindow::onFinished(int exitCode, QProcess::ExitStatus exitStatus)
{
    if (exitStatus == QProcess::CrashExit) {
            QMessageBox::information(this,"Sheldon::CRASHINFO",
                                     QString::fromUtf8("Se ha terminado inesperadamente la ejecución de apt-mirror"),QMessageBox::Ok);
        } else if (exitCode != 0) {
            QMessageBox::information(this,"Sheldon::FAILEDINFO",
                                     QString::fromUtf8("Ha fallado la ejecución de apt-mirror"),QMessageBox::Ok);
        } else {
            QMessageBox::information(this,"Sheldon::INFO",
                                     QString::fromUtf8("El proceso ha finalizado, para mas información lea la salida.\n Elimine las carpetas innecesarias /var y /skel creadas en ") + ruta,QMessageBox::Ok);
        }
    ui->btnStart->setEnabled(true);
    ui->tabWidget->setTabEnabled(0,true);
    QDir rmposmirror(ruta + "/var/");
    rmposmirror.remove("apt-mirror.lock");
    rmposmirror.remove("postmirror.sh");
//    switch(exitStatus)
//    {
//    case QProcess::NormalExit:
//        {
//            QMessageBox::information(this,"Sheldon::INFO",QString::fromUtf8("El proceso ha finalizado, para mas información lea la salida.\n Elimine las carpetas innecesarias /var y /skel creadas en ") + ruta,QMessageBox::Ok);
//            break;
//        }
//    default:
//        {
//            break;
//        }
//    }

}
void MainWindow::onMirrorChange()
{
    if(tabdisable)
    {
        ui->tabWidget->setTabEnabled(1,false);
        mirrorchanged = true;
        tabdisable = false;
    }
}

void MainWindow::on_actionConfigurar_triggered()
{
    confd->setNthread(nthread);
    confd->setLimitRate(limitrate);
    confd->exec();
    nthread = confd->getNthread();
    limitrate = confd->getLimitRate();
}

void MainWindow::on_actionSalir_triggered()
{
    this->close();
}

void MainWindow::on_actionAcerca_de_triggered()
{
    infd->exec();
}

void MainWindow::on_actionAyuda_triggered()
{
    helpd->exec();
}
