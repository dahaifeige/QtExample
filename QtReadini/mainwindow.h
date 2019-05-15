#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_writeINIBtn_clicked();

    void on_readINIBtn_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
