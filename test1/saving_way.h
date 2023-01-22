#ifndef SAVING_WAY_H
#define SAVING_WAY_H

#include <QDialog>

namespace Ui {
class saving_way;
}

class saving_way : public QDialog
{
    Q_OBJECT

public:
    explicit saving_way(QWidget *parent = nullptr);
    ~saving_way();
     int i=0;
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::saving_way *ui;
};

#endif // SAVING_WAY_H
