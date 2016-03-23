#include "aptmirror.h"

AptMirror::AptMirror(QObject *parent):
    QObject(parent)
{
/*
set base_path         /var/spool/apt-mirror
set mirror_path       $base_path/mirror
set skel_path         $base_path/skel
set var_path          $base_path/var
set postmirror_script $var_path/postmirror.sh
set defaultarch       i386
set run_postmirror    0
set nthreads          20
set _tilde            0
# Use --unlink with wget (for use with hardlinked directories)
set unlink            1
set use_proxy         off
set http_proxy        127.0.0.1:3128
set proxy_user        user
set proxy_password    password

deb http://debian.uci.cu/debian testing main contrib non-free
*/
}

void AptMirror::setRuta(QString ruta)
{
    this->ruta = ruta;
}

void AptMirror::setNthread(QString nthread)
{
    this->nthread = nthread;
}

void AptMirror::setLimitrate(QString limitrate)
{
    this->limitrate = limitrate;
}

void AptMirror::makeFile()
{
    fileName = ruta +"/mirror.list";
    base_path = "set base_path " + ruta + "\n";
    mirror_path = "set mirror_path $base_path\n";
    skel_path = "set skel_path $base_path/skel\n";
    var_path = "set var_path $base_path/var\n";
    setnthreads = "set nthreads " + nthread +"\n";
    tilde = "set _tilde 0\n";
    setlimitrate = "set limit_rate "+limitrate+"m\n";
    setuse_proxy = "set use_proxy " + use_proxy + "\n";
    sethttp_proxy = "set http_proxy " + http_proxy + "\n";
    setproxy_user = "set proxy_user " + proxy_user + "\n";
    setproxy_password = "set proxy_password " + proxy_password + "\n";

    documento = base_path + mirror_path + skel_path + var_path +
            setnthreads + setlimitrate + tilde +
            setuse_proxy + sethttp_proxy + setproxy_user + setproxy_password +
            repos;
    std::ofstream outfile(fileName.toStdString().c_str());
    outfile.write(documento.toStdString().c_str(), documento.length());
}

void AptMirror::writeFile(std::string filename, std::string document)
{
    std::ofstream outfile(filename.c_str());
    outfile.write(document.c_str(), document.length());
}

void AptMirror::setRepos(QString repos)
{
    this->repos.clear();
    QStringList reposstrip = repos.split("\n");
    for(int i = 0; i < reposstrip.size(); i++)
    {
        if(!reposstrip.at(i).trimmed().contains('#'))
        {
            this->repos.append(reposstrip.at(i).trimmed() + "\n");
        }
    }

}

QString AptMirror::getRepos()
{
    return this->repos;
}

QString AptMirror::getFileName()
{
    return this->fileName;
}

void AptMirror::setUse_proxy(const QString &value)
{
    this->use_proxy = value;
}

void AptMirror::setHttp_proxy(const QString &value)
{
    this->http_proxy = value;
}

void AptMirror::setProxy_user(const QString &value)
{
    this->proxy_user = value;
}

void AptMirror::setProxy_password(const QString &value)
{
    this->proxy_password = value;
}
