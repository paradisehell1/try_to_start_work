#ifndef TEXT_DATA_H
#define TEXT_DATA_H

#include <QDialog>
#include <QFile>
#include <QDir>
#include <QString>
#include <QFileinfo>
#include <QTextCodec>
#include <QTextStream>
#include <stdio.h>  // for getchar
#include <QFileInfo>
#include <QDir>
#include <QDebug>
#include<QDirIterator>
#include <fstream>
#include <dialog.h>
namespace Ui {
class Text_data;
}

class Text_data : public QDialog
{
    Q_OBJECT

public:
    explicit Text_data(QWidget *parent = nullptr);
    ~Text_data();
     QString t;

private:
    Ui::Text_data *ui;
    QStringList myList;
    Dialog dialog1;
private slots:

    void on_pushButton_clicked();
};

#endif // TEXT_DATA_H
