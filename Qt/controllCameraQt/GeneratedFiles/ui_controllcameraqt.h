/********************************************************************************
** Form generated from reading UI file 'controllcameraqt.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLLCAMERAQT_H
#define UI_CONTROLLCAMERAQT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_controllCameraQtClass
{
public:
    QWidget *centralWidget;
    QProgressBar *progressBar;
    QProgressBar *progressBar_2;
    QProgressBar *progressBar_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *controllCameraQtClass)
    {
        if (controllCameraQtClass->objectName().isEmpty())
            controllCameraQtClass->setObjectName(QStringLiteral("controllCameraQtClass"));
        controllCameraQtClass->resize(450, 547);
        centralWidget = new QWidget(controllCameraQtClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(20, 170, 108, 20));
        progressBar->setValue(24);
        progressBar_2 = new QProgressBar(centralWidget);
        progressBar_2->setObjectName(QStringLiteral("progressBar_2"));
        progressBar_2->setGeometry(QRect(20, 230, 108, 20));
        progressBar_2->setValue(24);
        progressBar_3 = new QProgressBar(centralWidget);
        progressBar_3->setObjectName(QStringLiteral("progressBar_3"));
        progressBar_3->setGeometry(QRect(20, 270, 108, 20));
        progressBar_3->setValue(24);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 210, 81, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 250, 81, 16));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 150, 54, 12));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 20, 75, 23));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(110, 20, 75, 23));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(10, 320, 75, 23));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(140, 320, 75, 23));
        controllCameraQtClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(controllCameraQtClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 450, 23));
        controllCameraQtClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(controllCameraQtClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        controllCameraQtClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(controllCameraQtClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        controllCameraQtClass->setStatusBar(statusBar);

        retranslateUi(controllCameraQtClass);
        QObject::connect(pushButton, SIGNAL(clicked()), controllCameraQtClass, SLOT(Initialize()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), controllCameraQtClass, SLOT(closeClicked()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), controllCameraQtClass, SLOT(pushButton_3()));
        QObject::connect(pushButton_4, SIGNAL(clicked()), controllCameraQtClass, SLOT(pushButton_4()));

        QMetaObject::connectSlotsByName(controllCameraQtClass);
    } // setupUi

    void retranslateUi(QMainWindow *controllCameraQtClass)
    {
        controllCameraQtClass->setWindowTitle(QApplication::translate("controllCameraQtClass", "controllCameraQt", 0));
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        pushButton->setText(QApplication::translate("controllCameraQtClass", "Initialize", 0));
        pushButton_2->setText(QApplication::translate("controllCameraQtClass", "Close", 0));
        pushButton_3->setText(QApplication::translate("controllCameraQtClass", "PushButton", 0));
        pushButton_4->setText(QApplication::translate("controllCameraQtClass", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class controllCameraQtClass: public Ui_controllCameraQtClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLLCAMERAQT_H
