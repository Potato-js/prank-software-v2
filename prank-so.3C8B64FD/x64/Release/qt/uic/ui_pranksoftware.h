/********************************************************************************
** Form generated from reading UI file 'pranksoftware.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRANKSOFTWARE_H
#define UI_PRANKSOFTWARE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pranksoftwareClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *pranksoftwareClass)
    {
        if (pranksoftwareClass->objectName().isEmpty())
            pranksoftwareClass->setObjectName("pranksoftwareClass");
        pranksoftwareClass->resize(600, 400);
        menuBar = new QMenuBar(pranksoftwareClass);
        menuBar->setObjectName("menuBar");
        pranksoftwareClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(pranksoftwareClass);
        mainToolBar->setObjectName("mainToolBar");
        pranksoftwareClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(pranksoftwareClass);
        centralWidget->setObjectName("centralWidget");
        pranksoftwareClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(pranksoftwareClass);
        statusBar->setObjectName("statusBar");
        pranksoftwareClass->setStatusBar(statusBar);

        retranslateUi(pranksoftwareClass);

        QMetaObject::connectSlotsByName(pranksoftwareClass);
    } // setupUi

    void retranslateUi(QMainWindow *pranksoftwareClass)
    {
        pranksoftwareClass->setWindowTitle(QCoreApplication::translate("pranksoftwareClass", "pranksoftware", nullptr));
    } // retranslateUi

};

namespace Ui {
    class pranksoftwareClass: public Ui_pranksoftwareClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRANKSOFTWARE_H
