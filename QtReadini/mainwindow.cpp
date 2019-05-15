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

void MainWindow::on_writeINIBtn_clicked()
{
    QSettings settings("TestSetting.ini", QSettings::IniFormat);
    settings.beginGroup("BtnConfig");
    settings.setValue("btnWidth", ui->widthLineEdit->text());
    settings.setValue("btnHeight", ui->heightLineEdit->text());
    settings.setValue("btnColor", ui->colorLineEdit->text());
    settings.endGroup();
}

void MainWindow::on_readINIBtn_clicked()
{
    QSettings settings("TestSetting.ini", QSettings::IniFormat);
    int width = settings.value("BtnConfig/btnWidth").toInt();
    ui->displayBtn->setFixedWidth(width);
    int height = settings.value("BtnConfig/btnHeight").toInt();
    ui->displayBtn->setFixedWidth(height);
    QString color = settings.value("BtnConfig/btnColor").toString();
    ui->displayBtn->setStyleSheet(QString("background-color:#%1").arg(color));
}
