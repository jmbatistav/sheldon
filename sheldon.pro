# -------------------------------------------------
# Project created by QtCreator 2010-12-13T08:44:22
# -------------------------------------------------
QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sheldon
TEMPLATE = app
DESTDIR = bin
OBJECTS_DIR = debug
MOC_DIR = debug
SOURCES += main.cpp \
    mainwindow.cpp \
    dialogs/configdialog.cpp \
    dialogs/infodialog.cpp \
    dialogs/helpdialog.cpp \
    src/aptmirror.cpp
HEADERS += mainwindow.h \
    dialogs/configdialog.h \
    dialogs/infodialog.h \
    dialogs/helpdialog.h \
    src/aptmirror.h
FORMS += mainwindow.ui
RESOURCES += sheldon.qrc

target.path = /usr/bin
INSTALLS += target