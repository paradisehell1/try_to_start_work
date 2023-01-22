#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <dialog.h>
#include <saving_way.h>
#include <QFileDialog>
#include <QFileInfo>
#include<saving_way.h>
#include <QTimer>
#include <timer.h>
#include <chrono>
#include <QTime>
#include "encryptyng_mask.h"
#include <QtGui>
#include<QErrorMessage>
#include <vector>
#include <text_data.h>
#include<windows.h>
#include<winapifamily.h>
#include <windows.h>
#include <iostream>
#include <tlhelp32.h>
#include <QTextStream>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool check_timer=false;
    bool check_sides=false;
QString path=" ";
QString t;
QFile file;
int count=0;
bool time_or_single=false;
bool deleteornot=false;
int checkCount=0;
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();


    void task();

    void on_pushButton_7_clicked();

    void on_pushButton_3_clicked();
    bool check_open(QString dir);

    bool IsProcessPresent(wchar_t* szExe);

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();
    void do_task();

    void on_radioButton_clicked();
    void on_radioButton_2_clicked();

private:

    Ui::MainWindow *ui;
    Dialog dialog;
    saving_way save_way;
    Timer timer1;
    encryptyng_mask enc;

};
#endif // MAINWINDOW_H
