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

void MainWindow::on_ReadJSON_clicked()
{
    QFile file("test.json");
    if(!file.open(QIODevice::ReadOnly)){
        return;
    }
    QByteArray data = file.readAll();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(data);
    QJsonObject jsonObject = jsonDoc.object();
    if(jsonObject["Info"].isArray())
    {
        QJsonArray jsonArray = jsonObject["Info"].toArray();
        for(int i = 0; i < jsonArray.size(); ++i)
        {
            QJsonObject subject = jsonArray[i].toObject();
            qDebug() << subject.value("age").toInt();
            qDebug() << subject.value("name").toString();
            qDebug() << subject["time"].toString();
        }
    }


}

void MainWindow::on_WriteJSON_clicked()
{
    QFile file("test.json");
    if(!file.open(QIODevice::WriteOnly)){
        return;
    }
    QJsonArray jsonArray;
    for(int i = 0; i < 3; ++i)
    {
        QJsonObject jsonObject;
        jsonObject.insert("name", QString::number(i+1));
        jsonObject.insert("age", i+18);
        jsonObject.insert("time", QDateTime::currentDateTime().toString());
        jsonArray.append(jsonObject);
    }
    QJsonObject jsonObject;
    jsonObject["Info"] = jsonArray;
    QJsonDocument jsonDoc(jsonObject);

    file.write(jsonDoc.toJson());
    file.close();
}

