/********************************************************************************
** Form generated from reading UI file 'Test01.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEST01_H
#define UI_TEST01_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Test01Class
{
public:
    QAction *action1;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Test01Class)
    {
        if (Test01Class->objectName().isEmpty())
            Test01Class->setObjectName(QString::fromUtf8("Test01Class"));
        Test01Class->resize(600, 400);
        action1 = new QAction(Test01Class);
        action1->setObjectName(QString::fromUtf8("action1"));
        centralWidget = new QWidget(Test01Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Test01Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Test01Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 25));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        Test01Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Test01Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Test01Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Test01Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Test01Class->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(action1);

        retranslateUi(Test01Class);

        QMetaObject::connectSlotsByName(Test01Class);
    } // setupUi

    void retranslateUi(QMainWindow *Test01Class)
    {
        Test01Class->setWindowTitle(QCoreApplication::translate("Test01Class", "Test01", nullptr));
        action1->setText(QCoreApplication::translate("Test01Class", "1", nullptr));
        menu->setTitle(QCoreApplication::translate("Test01Class", "\346\217\222\345\205\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Test01Class: public Ui_Test01Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST01_H
