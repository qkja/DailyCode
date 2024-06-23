/********************************************************************************
** Form generated from reading UI file 'boilerfeedpowderonlinemonitoringsystem.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOILERFEEDPOWDERONLINEMONITORINGSYSTEM_H
#define UI_BOILERFEEDPOWDERONLINEMONITORINGSYSTEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BoilerFeedPowderOnLineMonitoringSystemClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *BoilerFeedPowderOnLineMonitoringSystemClass)
    {
        if (BoilerFeedPowderOnLineMonitoringSystemClass->objectName().isEmpty())
            BoilerFeedPowderOnLineMonitoringSystemClass->setObjectName(QString::fromUtf8("BoilerFeedPowderOnLineMonitoringSystemClass"));
        BoilerFeedPowderOnLineMonitoringSystemClass->resize(600, 400);
        menuBar = new QMenuBar(BoilerFeedPowderOnLineMonitoringSystemClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        BoilerFeedPowderOnLineMonitoringSystemClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(BoilerFeedPowderOnLineMonitoringSystemClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        BoilerFeedPowderOnLineMonitoringSystemClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(BoilerFeedPowderOnLineMonitoringSystemClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        BoilerFeedPowderOnLineMonitoringSystemClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(BoilerFeedPowderOnLineMonitoringSystemClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        BoilerFeedPowderOnLineMonitoringSystemClass->setStatusBar(statusBar);

        retranslateUi(BoilerFeedPowderOnLineMonitoringSystemClass);

        QMetaObject::connectSlotsByName(BoilerFeedPowderOnLineMonitoringSystemClass);
    } // setupUi

    void retranslateUi(QMainWindow *BoilerFeedPowderOnLineMonitoringSystemClass)
    {
        BoilerFeedPowderOnLineMonitoringSystemClass->setWindowTitle(QCoreApplication::translate("BoilerFeedPowderOnLineMonitoringSystemClass", "BoilerFeedPowderOnLineMonitoringSystem", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BoilerFeedPowderOnLineMonitoringSystemClass: public Ui_BoilerFeedPowderOnLineMonitoringSystemClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOILERFEEDPOWDERONLINEMONITORINGSYSTEM_H
