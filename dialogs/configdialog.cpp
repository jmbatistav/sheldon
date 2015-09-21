#include "configdialog.h"

ConfigDialog::ConfigDialog(QWidget *parent) :
    QDialog(parent)
{
        buttonBox = new QPushButton(this);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(10, 120, 231, 32));
        buttonBox->setText(QString::fromUtf8("Aceptar"));
        spinBox = new QSpinBox(this);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(185, 20, 55, 25));
        spinBox->setMinimum(10);
        spinBox->setMaximum(50);
        spinBox->setValue(20);
        spinBox_2 = new QSpinBox(this);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setGeometry(QRect(185, 60, 55, 25));
        spinBox_2->setMinimum(50);
        spinBox_2->setMaximum(500);
        spinBox_2->setValue(100);
        label = new QLabel(this);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 22, 161, 17));
        label->setText("Descargas simultaneas: ");
        label_2 = new QLabel(this);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 62, 151, 17));
        label_2->setText(QString::fromUtf8("Tama\303\261o m\303\241ximo (Mb): "));


        connect(buttonBox,SIGNAL(clicked()),this,SLOT(aceptarOnclic()));
        this->setFixedSize(251, 160);
}

QString ConfigDialog::getNthread()
{
    return nthre;
}

QString ConfigDialog::getLimitRate()
{
    return limitr;
}

void ConfigDialog::setNthread(QString nt)
{
    spinBox->setValue(nt.toInt());
}

void ConfigDialog::setLimitRate(QString lr)
{
    spinBox_2->setValue(lr.toInt());
}

void ConfigDialog::aceptarOnclic()
{
    nthre = spinBox->text();
    limitr = spinBox_2->text();
    this->close();
}
