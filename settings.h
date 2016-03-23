#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>

namespace Ui {
class Settings;
}

class Settings : public QDialog
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = 0);
    ~Settings();
    QString getNthread();
    void setNthread(QString nt);

    QString getLimitRate();
    void setLimitRate(QString lr);


    QString getHostname() const;
    void setHostname(const QString &value);

    QString getPort() const;
    void setPort(const QString &value);

    QString getUser() const;
    void setUser(const QString &value);

    QString getPass() const;
    void setPass(const QString &value);

    bool getIsProxy() const;
    void setIsProxy(bool value);

    bool getIsAuthenticated() const;
    void setIsAuthenticated(bool value);

private slots:

private:
    Ui::Settings *ui;
};

#endif // SETTINGS_H
