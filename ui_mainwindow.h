/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionConfigurar;
    QAction *actionAyuda;
    QAction *actionSalir;
    QAction *actionAcerca_de;
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTextEdit *mirrortodownload;
    QLineEdit *pathtosave;
    QLabel *label_2;
    QLabel *label;
    QPushButton *btnBrowse;
    QPushButton *btnApply;
    QLabel *label_4;
    QWidget *tab_2;
    QTextEdit *output;
    QLabel *label_3;
    QPushButton *btnStart;
    QPushButton *btnStop;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(701, 486);
        QIcon icon;
        icon.addFile(QStringLiteral(":/resource/icons/appicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionConfigurar = new QAction(MainWindow);
        actionConfigurar->setObjectName(QStringLiteral("actionConfigurar"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/resource/icons/galternatives.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QStringLiteral(":/resource/icons/galternatives.png"), QSize(), QIcon::Normal, QIcon::On);
        actionConfigurar->setIcon(icon1);
        actionAyuda = new QAction(MainWindow);
        actionAyuda->setObjectName(QStringLiteral("actionAyuda"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/resource/icons/help-contents.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon2.addFile(QStringLiteral(":/resource/icons/help-contents.png"), QSize(), QIcon::Normal, QIcon::On);
        actionAyuda->setIcon(icon2);
        actionSalir = new QAction(MainWindow);
        actionSalir->setObjectName(QStringLiteral("actionSalir"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/resource/icons/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSalir->setIcon(icon3);
        actionAcerca_de = new QAction(MainWindow);
        actionAcerca_de->setObjectName(QStringLiteral("actionAcerca_de"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/resource/icons/info.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAcerca_de->setIcon(icon4);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 651, 421));
        tabWidget->setTabPosition(QTabWidget::South);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        mirrortodownload = new QTextEdit(tab);
        mirrortodownload->setObjectName(QStringLiteral("mirrortodownload"));
        mirrortodownload->setGeometry(QRect(10, 90, 621, 241));
        pathtosave = new QLineEdit(tab);
        pathtosave->setObjectName(QStringLiteral("pathtosave"));
        pathtosave->setGeometry(QRect(10, 30, 321, 27));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 70, 531, 17));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 91, 17));
        btnBrowse = new QPushButton(tab);
        btnBrowse->setObjectName(QStringLiteral("btnBrowse"));
        btnBrowse->setGeometry(QRect(340, 30, 92, 27));
        btnApply = new QPushButton(tab);
        btnApply->setObjectName(QStringLiteral("btnApply"));
        btnApply->setGeometry(QRect(540, 350, 92, 27));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(80, 200, 481, 20));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        output = new QTextEdit(tab_2);
        output->setObjectName(QStringLiteral("output"));
        output->setGeometry(QRect(120, 30, 511, 351));
        QPalette palette;
        QBrush brush(QColor(62, 186, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        QBrush brush2(QColor(118, 118, 117, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        QBrush brush3(QColor(255, 255, 255, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        output->setPalette(palette);
        output->setReadOnly(true);
        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(120, 10, 81, 17));
        btnStart = new QPushButton(tab_2);
        btnStart->setObjectName(QStringLiteral("btnStart"));
        btnStart->setGeometry(QRect(10, 50, 92, 27));
        btnStop = new QPushButton(tab_2);
        btnStop->setObjectName(QStringLiteral("btnStop"));
        btnStop->setGeometry(QRect(10, 100, 92, 27));
        tabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 701, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::RightToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        mainToolBar->addAction(actionConfigurar);
        mainToolBar->addAction(actionAcerca_de);
        mainToolBar->addAction(actionSalir);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Sheldon", 0));
        actionConfigurar->setText(QApplication::translate("MainWindow", "Configurar", 0));
#ifndef QT_NO_TOOLTIP
        actionConfigurar->setToolTip(QApplication::translate("MainWindow", "Configurar", 0));
#endif // QT_NO_TOOLTIP
        actionAyuda->setText(QApplication::translate("MainWindow", "Ayuda", 0));
#ifndef QT_NO_TOOLTIP
        actionAyuda->setToolTip(QApplication::translate("MainWindow", "Ayuda", 0));
#endif // QT_NO_TOOLTIP
        actionSalir->setText(QApplication::translate("MainWindow", "Salir", 0));
#ifndef QT_NO_TOOLTIP
        actionSalir->setToolTip(QApplication::translate("MainWindow", "Salir", 0));
#endif // QT_NO_TOOLTIP
        actionAcerca_de->setText(QApplication::translate("MainWindow", "Acerca de", 0));
#ifndef QT_NO_TOOLTIP
        actionAcerca_de->setToolTip(QApplication::translate("MainWindow", "Acerca de", 0));
#endif // QT_NO_TOOLTIP
        label_2->setText(QApplication::translate("MainWindow", "Mirrors a descargar (Debes especificar la arquitectura, deb-i386, deb-amd64, etc): ", 0));
        label->setText(QApplication::translate("MainWindow", "Guardar en:", 0));
        btnBrowse->setText(QApplication::translate("MainWindow", "Examinar", 0));
        btnApply->setText(QApplication::translate("MainWindow", "Aplicar", 0));
        label_4->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Configurar", 0));
        label_3->setText(QApplication::translate("MainWindow", "Terminal", 0));
        btnStart->setText(QApplication::translate("MainWindow", "Iniciar", 0));
        btnStop->setText(QApplication::translate("MainWindow", "Detener", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Descargar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
