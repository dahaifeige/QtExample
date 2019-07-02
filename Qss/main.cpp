#include "mainwindow.h"
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QFile file(":/test.qss");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString qss(file.readAll());
    a.setStyleSheet(qss);

    return a.exec();
}
