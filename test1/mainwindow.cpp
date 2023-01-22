#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    checkCount++;
    dialog.setModal(true);
    dialog.exec();
}


void MainWindow::on_pushButton_2_clicked()
{
    checkCount++;
int j=0;

   path = QFileDialog::getSaveFileName(0,QObject::tr("Укажите выходной файл"),QDir::homePath());
    qDebug()<<path;
    QFileInfo check_file(path);
       // check if file exists and if yes: Is it really a file and no directory?
       if (check_file.exists() && check_file.isFile()) {
           save_way.setModal(true);
           save_way.exec();
           qDebug()<<save_way.i;
           if (save_way.i==1){
               path = QFileDialog::getSaveFileName(0,QObject::tr("Укажите выходной файл"),QDir::homePath());
           }

            count++;
           int pos = path.lastIndexOf(QChar('.'));
                if (pos==0){


                        path=path+".txt";
             qDebug()<<path;
                }

                path=path.left(pos)+"("+QString::number(count )+")"+".txt";
                 qDebug()<<path;
            }
       int pos = path.lastIndexOf(QChar('.'));
            if (pos<110){


                    path=path+".txt";
         qDebug()<<path;
            }


       }







void MainWindow::task()
{
     QString path2 = path;
    QFile file1(path2);
    char *c = reinterpret_cast<char *>(malloc(dialog.mask.length() + 1));
    qstrcpy(c, t.toLatin1());
    char *c1 = reinterpret_cast<char *>(malloc(enc.enc_mask.length() + 1));
    qstrcpy(c1, enc.enc_mask.toLatin1());
    int len=strlen(c);
    for(int i=0;i<len;i++){
        c[i]=c[i]^c1[i];
        qDebug()<<c[i];
    }

    if (file1.open(QIODevice::ReadWrite)) {
            QTextStream stream(&file1);
            stream << c;
        }
}




void MainWindow::on_pushButton_7_clicked()
{
    checkCount++;
    enc.setModal(true);
    enc.exec();
}


void MainWindow::on_pushButton_3_clicked()
{
    do_task();


}



bool MainWindow::check_open(QString dir)
{
    QFile file(dir);
    if(file.isOpen())
    {
    qDebug() << "File is open";
    return false;
    }
    return true;

}

bool MainWindow::IsProcessPresent(wchar_t *szExe)
{
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

        PROCESSENTRY32 pe;
        pe.dwSize = sizeof(PROCESSENTRY32);
        Process32First(hSnapshot, &pe);

        if (!_wcsicmp((wchar_t*)&pe.szExeFile, szExe))
        {
            return true;
        }

        while (Process32Next(hSnapshot, &pe))
        {
            if (!_wcsicmp((wchar_t*)&pe.szExeFile, szExe))
            {
                return true;
            }
        }

        return false;

}





void MainWindow::on_buttonBox_accepted()
{
    checkCount++;
    deleteornot=true;
}
void MainWindow::on_buttonBox_rejected()
{ checkCount++;
    deleteornot=false;
}

void MainWindow::do_task()
{
    qDebug()<<checkCount;
    if (checkCount<5){
        QErrorMessage errorMessage;
        errorMessage.showMessage("enter all fields");
        errorMessage.exec();
        return;
    }
    QString dir="C:/Users/Иван/Documents/test1";

    qDebug()<<dialog.mask;
    QDirIterator it(dir, QStringList() << dialog.mask, QDir::Files, QDirIterator::Subdirectories);
    while (it.hasNext()){
        qDebug() << it.next();
    QFile file(it.filePath());

       file.open(QIODevice::ReadOnly | QIODevice::Text);
       TCHAR szExe[] = L"Notepad.exe";
          while (1)
          {
              if (IsProcessPresent((wchar_t*)&szExe))
              {

                      QErrorMessage errorMessage;
                      errorMessage.showMessage("close the Notepad");
                      errorMessage.exec();
                      return;
              }
              break;
        }

      t = file.readAll();
      file.close();
       if(deleteornot==true){
           file.remove();
       }

       task();
}
    if (deleteornot==false){
    QTimer* timer2=new QTimer(this);
            connect(timer2,SIGNAL(timeout()),this, SLOT(do_task()));

            timer2->start(std::chrono::milliseconds(10000));
    }

}


void MainWindow::on_radioButton_clicked()
{
    checkCount++;
    time_or_single=true;
}



void MainWindow::on_radioButton_2_clicked()
{
    checkCount++;
    time_or_single=false;
}

