#ifndef APTMIRROR_H
#define APTMIRROR_H
#include <QString>
#include <QFile>
#include <QMessageBox>
#include <fstream>


class AptMirror: public QObject
{
    Q_OBJECT
public:
    AptMirror(QObject *parent = 0);
    void setRuta(QString ruta);
    void setNthread(QString nthread);
    void setLimitrate(QString limitrate);
    void makeFile();
    void writeFile(std::string filename, std::string document);
    void setRepos(QString repos);
    QString getRepos();
    QString getFileName();
    void setUse_proxy(const QString &value);
    void setHttp_proxy(const QString &value);
    void setProxy_user(const QString &value);
    void setProxy_password(const QString &value);

private:
    QString fileName;
    QString base_path;
    QString mirror_path;
    QString skel_path;
    QString var_path;
    QString setnthreads;
    QString tilde;
    QString setlimitrate;
    QString ruta;
    QString nthread;
    QString limitrate;
    QString repos;
    QString documento;
    QString use_proxy;
    QString http_proxy;
    QString proxy_user;
    QString proxy_password;
    QString setuse_proxy;
    QString sethttp_proxy;
    QString setproxy_user;
    QString setproxy_password;


};

#endif // APTMIRROR_H
