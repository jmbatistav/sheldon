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


};

#endif // APTMIRROR_H
