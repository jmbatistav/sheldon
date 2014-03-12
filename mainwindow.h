#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include <QString>
#include <QStringList>
#include <QTextEdit>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QDir>
#include <QTextStream>

#include "dialogs/configdialog.h"
#include "dialogs/infodialog.h"
#include "dialogs/helpdialog.h"
#include "src/aptmirror.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;
    AptMirror *aptmirror;
    void openmirriorlistfromfile();
    QProcess terminal;
    QProcess killall;
    QString fileName;
    QString ruta;
    QString nthread;
    QString limitrate;
    bool mirrorchanged;
    bool tabdisable;
    ConfigDialog *confd;
    InfoDialog *infd;
    HelpDialog *helpd;

private slots:
    void on_btnStop_clicked();
    void on_btnStart_clicked();
    void on_btnApply_clicked();
    void on_btnBrowse_clicked();
    void readFromStdout();
    void readFromStderror();
    void onError(QProcess::ProcessError error);
    void onStarted();
    void onFinished(int exitCode, QProcess::ExitStatus exitStatus);
    void onMirrorChange();
    void on_actionConfigurar_triggered();
    void on_actionSalir_triggered();
    void on_actionAcerca_de_triggered();
    void on_actionAyuda_triggered();
};

#endif // MAINWINDOW_H
