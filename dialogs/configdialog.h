#ifndef CONFIGDIALOG_H
#define CONFIGDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QSpinBox>
#include <QPushButton>


class ConfigDialog : public QDialog
{
    Q_OBJECT
public:
    ConfigDialog(QWidget *parent = 0);
    QString getNthread(){return nthre;};
    QString getLimitRate(){return limitr;};

signals:

public slots:
void aceptarOnclic();

private:
    QPushButton *buttonBox;
    QSpinBox *spinBox;
    QSpinBox *spinBox_2;
    QLabel *label;
    QLabel *label_2;
    QString nthre;
    QString limitr;

};

#endif // CONFIGDIALOG_H
