#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFile>
#include<QMessageBox>
#include<QTextStream>
#include<QVector>
#include<QtCore>
#include<QDebug>

nodeptr search( nodeptr hdlist);
void printall ( nodeptr  hdlist);
int totalprice (nodeptr  hdlist);
void readreaderfile( QVector<QString> & readerinput);


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    QFile file2( "C:/Users/jingz/Desktop/RFID_GUI/RFID_Checkout/resource/file/database.txt" );

    if (!file2.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"ERROR","file not open");
     }

 while(!file2.atEnd()){
     QString y =file2.readLine();
     if(y!=" "){
    ui->listWidget_2->addItem(y);}
 }
file2.close();
}

void MainWindow::on_readerfile_clicked()
{
    QFile file( "C:/Users/jingz/Desktop/RFID_GUI/RFID_Checkout/resource/file/GUI/rfid-reader.log" );

    if (!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"ERROR","file not open");
     }

 while(!file.atEnd()){
     QString y =file.readLine();
     if(y[0] == '['&&y[1]!=','){
    ui->listWidget->addItem(y);
     }
 }
file.close();
}
