#include "aptmirror.h"

AptMirror::AptMirror(QObject *parent):
    QObject(parent)
{
    base_path = "";
    mirror_path = "";
    skel_path = "";
    var_path = "";
    setnthreads = "";
    tilde = "";
    setlimitrate = "";
    ruta = "";
    nthread = "";
    limitrate = "";
    repos = "";
    documento = "";
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
    documento = base_path + mirror_path + skel_path + var_path + setnthreads + setlimitrate + tilde + repos;
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
