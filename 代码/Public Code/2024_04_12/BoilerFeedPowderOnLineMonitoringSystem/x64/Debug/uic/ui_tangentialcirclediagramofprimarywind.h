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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "primarywindcutcirclediagramview.h"

QT_BEGIN_NAMESPACE

class Ui_TangentialCircleDiagramOfPrimaryWindClass
{
public:
    QWidget *centralWidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    PrimaryWindCutCircleDiagramView *widget1;
    PrimaryWindCutCircleDiagramView *widget_3;
    PrimaryWindCutCircleDiagramView *widget_2;
    QHBoxLayout *horizontalLayout_2;
    PrimaryWindCutCircleDiagramView *widget_4;
    PrimaryWindCutCircleDiagramView *widget_5;
    PrimaryWindCutCircleDiagramView *widget_6;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TangentialCircleDiagramOfPrimaryWindClass)
    {
        if (TangentialCircleDiagramOfPrimaryWindClass->objectName().isEmpty())
            TangentialCircleDiagramOfPrimaryWindClass->setObjectName(QString::fromUtf8("TangentialCircleDiagramOfPrimaryWindClass"));
        TangentialCircleDiagramOfPrimaryWindClass->resize(1366, 595);
        centralWidget = new QWidget(TangentialCircleDiagramOfPrimaryWindClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 10, 1311, 521));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        widget1 = new PrimaryWindCutCircleDiagramView(widget);
        widget1->setObjectName(QString::fromUtf8("widget1"));

        horizontalLayout->addWidget(widget1);

        widget_3 = new PrimaryWindCutCircleDiagramView(widget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));

        horizontalLayout->addWidget(widget_3);

        widget_2 = new PrimaryWindCutCircleDiagramView(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));

        horizontalLayout->addWidget(widget_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        widget_4 = new PrimaryWindCutCircleDiagramView(widget);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));

        horizontalLayout_2->addWidget(widget_4);

        widget_5 = new PrimaryWindCutCircleDiagramView(widget);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));

        horizontalLayout_2->addWidget(widget_5);

        widget_6 = new PrimaryWindCutCircleDiagramView(widget);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));

        horizontalLayout_2->addWidget(widget_6);


        verticalLayout->addLayout(horizontalLayout_2);

        TangentialCircleDiagramOfPrimaryWindClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TangentialCircleDiagramOfPrimaryWindClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1366, 26));
        TangentialCircleDiagramOfPrimaryWindClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TangentialCircleDiagramOfPrimaryWindClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        TangentialCircleDiagramOfPrimaryWindClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
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
