#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QValidator>
#include <QRegularExpression>
#include<QString>
#include <QDebug>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    QString mask=" ";

private slots:
    void on_pushButton_clicked();



private:
    Ui::Dialog *ui;

};

#endif // DIALOG_H
