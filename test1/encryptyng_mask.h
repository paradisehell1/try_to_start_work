#ifndef ENCRYPTYNG_MASK_H
#define ENCRYPTYNG_MASK_H

#include <QDialog>

namespace Ui {
class encryptyng_mask;
}

class encryptyng_mask : public QDialog
{
    Q_OBJECT

public:
    explicit encryptyng_mask(QWidget *parent = nullptr);
    ~encryptyng_mask();
QString enc_mask="";
private slots:
    void on_pushButton_clicked();

private:
    Ui::encryptyng_mask *ui;
};

#endif // ENCRYPTYNG_MASK_H
