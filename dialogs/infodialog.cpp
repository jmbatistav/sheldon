#include "infodialog.h"

InfoDialog::InfoDialog(QWidget *parent) :
    QDialog(parent)
{
    pushButton = new QPushButton(this);
            pushButton->setObjectName(QString::fromUtf8("pushButton"));
            pushButton->setGeometry(QRect(450, 350, 92, 27));
            plainTextEdit = new QPlainTextEdit(this);
            plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
            plainTextEdit->setReadOnly(true);
            plainTextEdit->setGeometry(QRect(20, 20, 521, 321));
            pushButton->setText(QString::fromUtf8( "Aceptar"));
            plainTextEdit->setPlainText(QString::fromUtf8("Sheldon es una GUI para apt-mirror, una peque\303\261a y eficiente herramienta que te permitir\303\241 descargar una parte o completamente un repositorio Debian GNU/Linux o cualquier distro basada en ella. \n\n"
            "Caracter\303\255sticas fundamentales:\n"
            "* Soporta multiples descargas simultaneamente.\n"
            "* Soporta multiples descargas de diferentes arquitecturas.\n"
            "* Funciona en Debian GNU/Linux y sus derivados.\n"
            "* Compatible con Qt5.\n"
            "\n"
            "Desarrollado por:\n"
            "Jos\303\251 Manuel Batista Viltre <batista87@gmail.com>"));
            connect(pushButton,SIGNAL(clicked()),this,SLOT(aceptarOnclic()));

        this->setFixedSize(560, 398);
}

void InfoDialog::aceptarOnclic()
{
    this->close();
}
