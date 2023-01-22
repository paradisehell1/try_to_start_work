#include "text_data.h"
#include "ui_text_data.h"
#define CRT_SECURE_NO_WARNINGS
using namespace std;

Text_data::Text_data(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Text_data)
{
    ui->setupUi(this);
}

Text_data::~Text_data()
{
    delete ui;
}



void Text_data::on_pushButton_clicked()
{
    QString dir="C:/Users/Иван/Documents/test1";
    QString ku="*.txt";
    qDebug()<<dialog1.mask;
    QDirIterator it(dir, QStringList() << ku, QDir::Files, QDirIterator::Subdirectories);
    while (it.hasNext()){
        qDebug() << it.next();
    QFile file(it.filePath());
       file.open(QIODevice::ReadOnly | QIODevice::Text);
      t = file.readAll();
       qDebug()<<t;
}
}

