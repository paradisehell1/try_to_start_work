#ifndef TIMER_H
#define TIMER_H

#include <QDialog>
#include <QString>
#include <QValidator>
#include <QRegularExpression>
namespace Ui {
class Timer;
}

class Timer : public QDialog
{
    Q_OBJECT

public:
    explicit Timer(QWidget *parent = nullptr);
    ~Timer();
    int time=-1;
private slots:


    void on_pushButton_clicked();

private:
    Ui::Timer *ui;
};

#endif // TIMER_H
