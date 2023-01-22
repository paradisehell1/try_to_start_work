#include "saving_way.h"
#include "ui_saving_way.h"

saving_way::saving_way(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::saving_way)
{
    ui->setupUi(this);
}

saving_way::~saving_way()
{
    delete ui;
}

void saving_way::on_pushButton_clicked()
{
    i=1;
    close();
}


void saving_way::on_pushButton_2_clicked()
{
    i=2;
    close();

}


