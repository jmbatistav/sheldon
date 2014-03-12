#ifndef INFODIALOG_H
#define INFODIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QPlainTextEdit>

class InfoDialog : public QDialog
{
    Q_OBJECT
public:
    InfoDialog(QWidget *parent = 0);

signals:

public slots:
    void aceptarOnclic();
private:
	QPushButton *pushButton;
        QPlainTextEdit *plainTextEdit;

};

#endif // INFODIALOG_H
