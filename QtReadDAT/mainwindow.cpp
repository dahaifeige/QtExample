#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_writeBtn_clicked()
{
    QFile file("file.dat");
    if(!file.open(QIODevice::WriteOnly))
    {
        return;
    }
    QDataStream out(&file);
    out << (quint32)0XA0B0C0D0; //MAGIC
    out << (qint32)123; //version

    out.setVersion(QDataStream::Qt_5_8);
    out << QString("the answer is");
    out << (qint32)42;
    file.close();
}

void MainWindow::on_readBtn_clicked()
{
    QFile file("file.dat");
    if(!file.open(QIODevice::ReadOnly))
    {
        return;
    }
    QDataStream in(&file);

    // check magic
    quint32 magic = 0;
    in >> magic;
    if(magic != 0xA0B0C0D0)
    {
        return;
    }

    // check version
    qint32 version = 0;
    in >> version;
    if(version != 123)
    {
        return;
    }

    QString str;
    qint32 a;
    in >> str;
    in >> a;
    qDebug() << str << ":" << a;
    file.close();
}
