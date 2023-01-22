#include "timer.h"
#include "ui_timer.h"

Timer::Timer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Timer)
{
    ui->setupUi(this);
    QRegularExpression RegExp("^[0-9]+$");
    QValidator *Validator = new QRegularExpressionValidator(RegExp, this);
    ui->lineEdit->setValidator(Validator);
}

Timer::~Timer()
{
    delete ui;
}





void Timer::on_pushButton_clicked()
{
   QString time10 =ui->lineEdit->text();
   time=time10.toInt();

    qDebug()<<time;
    close();
}

