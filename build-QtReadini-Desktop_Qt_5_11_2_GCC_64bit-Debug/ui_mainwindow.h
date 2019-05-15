/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *displayBtn;
    QPushButton *readINIBtn;
    QPushButton *writeINIBtn;
    QWidget *widget;
    QFormLayout *formLayout;
    QLabel *label_3;
    QLineEdit *widthLineEdit;
    QLabel *label;
    QLineEdit *heightLineEdit;
    QLabel *label_2;
    QLineEdit *colorLineEdit;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        displayBtn = new QPushButton(centralWidget);
        displayBtn->setObjectName(QStringLiteral("displayBtn"));
        displayBtn->setGeometry(QRect(160, 20, 83, 28));
        readINIBtn = new QPushButton(centralWidget);
        readINIBtn->setObjectName(QStringLiteral("readINIBtn"));
        readINIBtn->setGeometry(QRect(160, 70, 83, 28));
        writeINIBtn = new QPushButton(centralWidget);
        writeINIBtn->setObjectName(QStringLiteral("writeINIBtn"));
        writeINIBtn->setGeometry(QRect(160, 260, 83, 28));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(1, 141, 391, 98));
        formLayout = new QFormLayout(widget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        widthLineEdit = new QLineEdit(widget);
        widthLineEdit->setObjectName(QStringLiteral("widthLineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, widthLineEdit);

        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        heightLineEdit = new QLineEdit(widget);
        heightLineEdit->setObjectName(QStringLiteral("heightLineEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, heightLineEdit);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        colorLineEdit = new QLineEdit(widget);
        colorLineEdit->setObjectName(QStringLiteral("colorLineEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, colorLineEdit);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        displayBtn->setText(QApplication::translate("MainWindow", "DisplayBtn", nullptr));
        readINIBtn->setText(QApplication::translate("MainWindow", "ReadINI", nullptr));
        writeINIBtn->setText(QApplication::translate("MainWindow", "WriteINI", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "BtnWidth:", nullptr));
        label->setText(QApplication::translate("MainWindow", "BtnHeight:", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "BtnBackGroundColor:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
