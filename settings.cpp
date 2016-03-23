#include "settings.h"
#include "ui_settings.h"
#include <QDebug>

Settings::Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
}

Settings::~Settings()
{
    delete ui;
}

QString Settings::getNthread()
{
    return QString::number(ui->nthreSpin->value());
}

QString Settings::getLimitRate()
{
    return QString::number(ui->limitrSpin->value());
}

void Settings::setNthread(QString nt)
{
    ui->nthreSpin->setValue(nt.toInt());
}

void Settings::setLimitRate(QString lr)
{
    ui->limitrSpin->setValue(lr.toInt());
}

QString Settings::getHostname() const
{
    return ui->hostName->text();
}

void Settings::setHostname(const QString &value)
{
    ui->hostName->setText(value);
}

QString Settings::getPort() const
{
    return QString::number(ui->port->value());
}

void Settings::setPort(const QString &value)
{
    ui->port->setValue(value.toInt());
}

QString Settings::getUser() const
{
    return ui->userName->text();
}

void Settings::setUser(const QString &value)
{
    ui->userName->setText(value);
}

QString Settings::getPass() const
{
    return ui->password->text();
}

void Settings::setPass(const QString &value)
{
    ui->password->setText(value);
}

bool Settings::getIsProxy() const
{
    return ui->withProxy->isChecked();
}

void Settings::setIsProxy(bool value)
{
    ui->withProxy->setChecked(value);
}

bool Settings::getIsAuthenticated() const
{
    return ui->withAuthentication->isChecked();
}

void Settings::setIsAuthenticated(bool value)
{
    ui->withAuthentication->setChecked(value);
}
