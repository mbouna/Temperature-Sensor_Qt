#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <string>
#include <QDebug>
#include <QMessageBox>

QSerialPort *serial;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    serial = new QSerialPort(this);
    //ui->textEdit->setText("123");
    //ui->Temperature_lcdNumber->display("-----");
    serial = new QSerialPort(this);
    serial->setPortName("COM1");
    //serial->setBaudRate(QSerialPort::Baud9600);
    //serial->setDataBits(QSerialPort::Data8);
    serial->open(QIODevice::ReadWrite);

    MainWindow::connect(serial, SIGNAL (readyRead()), this, SLOT(readyRead()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::readyRead()
{
   QString ba;
   ba = serial->readAll();
   ui->Tempe_lcdNumber->display(ba);
//ui->textEdit->setText(ba);
}
