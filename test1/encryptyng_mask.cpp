#include "encryptyng_mask.h"
#include "ui_encryptyng_mask.h"

encryptyng_mask::encryptyng_mask(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::encryptyng_mask)
{
    ui->setupUi(this);
}

encryptyng_mask::~encryptyng_mask()
{
    delete ui;
}

void encryptyng_mask::on_pushButton_clicked()
{
    enc_mask=ui->lineEdit->text();
    qDebug()<<enc_mask;
    close();
}

