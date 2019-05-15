#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDomDocument>
#include <QFile>
#include <QTextStream>
#include <QDebug>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    void readXML();
    void writeXML();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
