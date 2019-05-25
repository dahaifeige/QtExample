#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(qApp->applicationDisplayName());
    initTray();
    tray_.show();
    tray_.showMessage("TestTray","task is alreay start", QIcon(":/MSI.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    event->ignore();
    hide();
}

void MainWindow::initTray()
{
    connect(&tray_, &QSystemTrayIcon::activated, this, [this](QSystemTrayIcon::ActivationReason reason){
        switch (reason) {
        case QSystemTrayIcon::Trigger:
        case QSystemTrayIcon::DoubleClick:
        case QSystemTrayIcon::MiddleClick:
        {
            if(isHidden()){
                show();
                activateWindow();
            } else {
                hide();
            }

        }
        }
    });
    QMenu* menu = new QMenu(this);
    connect(menu->addAction("exit"), &QAction::trigger, this, [this]{
        QMessageBox about(QMessageBox::NoIcon, windowTitle(), "is exit?", QMessageBox::Ok | QMessageBox ::Cancel, this);
        about.setIconPixmap(QPixmap(":/MSI.png"));
        if(about.exec() == QMessageBox::Cancel)
        {
            return ;
        }
        qApp->quit();
    });
    tray_.setContextMenu(menu);
    tray_.setToolTip(qApp->applicationDisplayName());
    tray_.setIcon(QIcon(":/MSI.png"));
}
