/********************************************************************************
** Form generated from reading UI file 'tangentialcirclediagramofprimarywind.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TANGENTIALCIRCLEDIAGRAMOFPRIMARYWIND_H
#define UI_TANGENTIALCIRCLEDIAGRAMOFPRIMARYWIND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TangentialCircleDiagramOfPrimaryWindClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TangentialCircleDiagramOfPrimaryWindClass)
    {
        if (TangentialCircleDiagramOfPrimaryWindClass->objectName().isEmpty())
            TangentialCircleDiagramOfPrimaryWindClass->setObjectName(QString::fromUtf8("TangentialCircleDiagramOfPrimaryWindClass"));
        TangentialCircleDiagramOfPrimaryWindClass->resize(600, 400);
        menuBar = new QMenuBar(TangentialCircleDiagramOfPrimaryWindClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        TangentialCircleDiagramOfPrimaryWindClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TangentialCircleDiagramOfPrimaryWindClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        TangentialCircleDiagramOfPrimaryWindClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(TangentialCircleDiagramOfPrimaryWindClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        TangentialCircleDiagramOfPrimaryWindClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(TangentialCircleDiagramOfPrimaryWindClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        TangentialCircleDiagramOfPrimaryWindClass->setStatusBar(statusBar);

        retranslateUi(TangentialCircleDiagramOfPrimaryWindClass);

        QMetaObject::connectSlotsByName(TangentialCircleDiagramOfPrimaryWindClass);
    } // setupUi

    void retranslateUi(QMainWindow *TangentialCircleDiagramOfPrimaryWindClass)
    {
        TangentialCircleDiagramOfPrimaryWindClass->setWindowTitle(QCoreApplication::translate("TangentialCircleDiagramOfPrimaryWindClass", "TangentialCircleDiagramOfPrimaryWind", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TangentialCircleDiagramOfPrimaryWindClass: public Ui_TangentialCircleDiagramOfPrimaryWindClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TANGENTIALCIRCLEDIAGRAMOFPRIMARYWIND_H
