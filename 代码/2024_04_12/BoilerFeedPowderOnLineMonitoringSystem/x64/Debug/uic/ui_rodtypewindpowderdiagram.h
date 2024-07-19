/********************************************************************************
** Form generated from reading UI file 'rodtypewindpowderdiagram.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RODTYPEWINDPOWDERDIAGRAM_H
#define UI_RODTYPEWINDPOWDERDIAGRAM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "barchartwidget.h"

QT_BEGIN_NAMESPACE

class Ui_RodTypeWindPowderDiagramClass
{
public:
    QWidget *centralWidget;
    QLabel *label_c;
    QLabel *label_a;
    QLabel *label_temperature;
    QLabel *label_pulverized_coal_concentration;
    QLabel *label_wind_velocity;
    QLabel *label_f;
    QLabel *label_b;
    QLabel *label_d;
    QLabel *label_e;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QWidget *wind_velocity;
    QHBoxLayout *horizontalLayout_13;
    BarChartWidget *wind_velocity_a;
    BarChartWidget *wind_velocity_b;
    BarChartWidget *wind_velocity_c;
    BarChartWidget *wind_velocity_d;
    BarChartWidget *wind_velocity_e;
    BarChartWidget *wind_velocity_f;
    QWidget *pulverized_coal_concentration;
    QHBoxLayout *horizontalLayout_12;
    BarChartWidget *pulverized_coal_concentration_a;
    BarChartWidget *pulverized_coal_concentration_b;
    BarChartWidget *pulverized_coal_concentration_c;
    BarChartWidget *pulverized_coal_concentration_d;
    BarChartWidget *pulverized_coal_concentration_e;
    BarChartWidget *pulverized_coal_concentration_f;
    QWidget *temperature;
    QHBoxLayout *horizontalLayout_14;
    BarChartWidget *temperature_a;
    BarChartWidget *temperature_b;
    BarChartWidget *temperature_c;
    BarChartWidget *temperature_d;
    BarChartWidget *temperature_e;
    BarChartWidget *temperature_f;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *RodTypeWindPowderDiagramClass)
    {
        if (RodTypeWindPowderDiagramClass->objectName().isEmpty())
            RodTypeWindPowderDiagramClass->setObjectName(QString::fromUtf8("RodTypeWindPowderDiagramClass"));
        RodTypeWindPowderDiagramClass->resize(1600, 1169);
        centralWidget = new QWidget(RodTypeWindPowderDiagramClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label_c = new QLabel(centralWidget);
        label_c->setObjectName(QString::fromUtf8("label_c"));
        label_c->setGeometry(QRect(640, 20, 71, 61));
        label_a = new QLabel(centralWidget);
        label_a->setObjectName(QString::fromUtf8("label_a"));
        label_a->setGeometry(QRect(200, 20, 71, 61));
        label_temperature = new QLabel(centralWidget);
        label_temperature->setObjectName(QString::fromUtf8("label_temperature"));
        label_temperature->setGeometry(QRect(20, 590, 71, 61));
        label_pulverized_coal_concentration = new QLabel(centralWidget);
        label_pulverized_coal_concentration->setObjectName(QString::fromUtf8("label_pulverized_coal_concentration"));
        label_pulverized_coal_concentration->setGeometry(QRect(20, 370, 71, 61));
        label_wind_velocity = new QLabel(centralWidget);
        label_wind_velocity->setObjectName(QString::fromUtf8("label_wind_velocity"));
        label_wind_velocity->setGeometry(QRect(20, 140, 71, 61));
        label_f = new QLabel(centralWidget);
        label_f->setObjectName(QString::fromUtf8("label_f"));
        label_f->setGeometry(QRect(1280, 20, 71, 61));
        label_b = new QLabel(centralWidget);
        label_b->setObjectName(QString::fromUtf8("label_b"));
        label_b->setGeometry(QRect(410, 20, 71, 61));
        label_d = new QLabel(centralWidget);
        label_d->setObjectName(QString::fromUtf8("label_d"));
        label_d->setGeometry(QRect(850, 30, 71, 61));
        label_e = new QLabel(centralWidget);
        label_e->setObjectName(QString::fromUtf8("label_e"));
        label_e->setGeometry(QRect(1060, 20, 71, 61));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(180, 120, 1311, 961));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        wind_velocity = new QWidget(widget);
        wind_velocity->setObjectName(QString::fromUtf8("wind_velocity"));
        horizontalLayout_13 = new QHBoxLayout(wind_velocity);
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        wind_velocity_a = new BarChartWidget(wind_velocity);
        wind_velocity_a->setObjectName(QString::fromUtf8("wind_velocity_a"));

        horizontalLayout_13->addWidget(wind_velocity_a);

        wind_velocity_b = new BarChartWidget(wind_velocity);
        wind_velocity_b->setObjectName(QString::fromUtf8("wind_velocity_b"));

        horizontalLayout_13->addWidget(wind_velocity_b);

        wind_velocity_c = new BarChartWidget(wind_velocity);
        wind_velocity_c->setObjectName(QString::fromUtf8("wind_velocity_c"));

        horizontalLayout_13->addWidget(wind_velocity_c);

        wind_velocity_d = new BarChartWidget(wind_velocity);
        wind_velocity_d->setObjectName(QString::fromUtf8("wind_velocity_d"));

        horizontalLayout_13->addWidget(wind_velocity_d);

        wind_velocity_e = new BarChartWidget(wind_velocity);
        wind_velocity_e->setObjectName(QString::fromUtf8("wind_velocity_e"));

        horizontalLayout_13->addWidget(wind_velocity_e);

        wind_velocity_f = new BarChartWidget(wind_velocity);
        wind_velocity_f->setObjectName(QString::fromUtf8("wind_velocity_f"));

        horizontalLayout_13->addWidget(wind_velocity_f);


        verticalLayout->addWidget(wind_velocity);

        pulverized_coal_concentration = new QWidget(widget);
        pulverized_coal_concentration->setObjectName(QString::fromUtf8("pulverized_coal_concentration"));
        horizontalLayout_12 = new QHBoxLayout(pulverized_coal_concentration);
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        pulverized_coal_concentration_a = new BarChartWidget(pulverized_coal_concentration);
        pulverized_coal_concentration_a->setObjectName(QString::fromUtf8("pulverized_coal_concentration_a"));

        horizontalLayout_12->addWidget(pulverized_coal_concentration_a);

        pulverized_coal_concentration_b = new BarChartWidget(pulverized_coal_concentration);
        pulverized_coal_concentration_b->setObjectName(QString::fromUtf8("pulverized_coal_concentration_b"));

        horizontalLayout_12->addWidget(pulverized_coal_concentration_b);

        pulverized_coal_concentration_c = new BarChartWidget(pulverized_coal_concentration);
        pulverized_coal_concentration_c->setObjectName(QString::fromUtf8("pulverized_coal_concentration_c"));

        horizontalLayout_12->addWidget(pulverized_coal_concentration_c);

        pulverized_coal_concentration_d = new BarChartWidget(pulverized_coal_concentration);
        pulverized_coal_concentration_d->setObjectName(QString::fromUtf8("pulverized_coal_concentration_d"));

        horizontalLayout_12->addWidget(pulverized_coal_concentration_d);

        pulverized_coal_concentration_e = new BarChartWidget(pulverized_coal_concentration);
        pulverized_coal_concentration_e->setObjectName(QString::fromUtf8("pulverized_coal_concentration_e"));

        horizontalLayout_12->addWidget(pulverized_coal_concentration_e);

        pulverized_coal_concentration_f = new BarChartWidget(pulverized_coal_concentration);
        pulverized_coal_concentration_f->setObjectName(QString::fromUtf8("pulverized_coal_concentration_f"));

        horizontalLayout_12->addWidget(pulverized_coal_concentration_f);


        verticalLayout->addWidget(pulverized_coal_concentration);

        temperature = new QWidget(widget);
        temperature->setObjectName(QString::fromUtf8("temperature"));
        horizontalLayout_14 = new QHBoxLayout(temperature);
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        temperature_a = new BarChartWidget(temperature);
        temperature_a->setObjectName(QString::fromUtf8("temperature_a"));

        horizontalLayout_14->addWidget(temperature_a);

        temperature_b = new BarChartWidget(temperature);
        temperature_b->setObjectName(QString::fromUtf8("temperature_b"));

        horizontalLayout_14->addWidget(temperature_b);

        temperature_c = new BarChartWidget(temperature);
        temperature_c->setObjectName(QString::fromUtf8("temperature_c"));

        horizontalLayout_14->addWidget(temperature_c);

        temperature_d = new BarChartWidget(temperature);
        temperature_d->setObjectName(QString::fromUtf8("temperature_d"));

        horizontalLayout_14->addWidget(temperature_d);

        temperature_e = new BarChartWidget(temperature);
        temperature_e->setObjectName(QString::fromUtf8("temperature_e"));

        horizontalLayout_14->addWidget(temperature_e);

        temperature_f = new BarChartWidget(temperature);
        temperature_f->setObjectName(QString::fromUtf8("temperature_f"));

        horizontalLayout_14->addWidget(temperature_f);


        verticalLayout->addWidget(temperature);

        RodTypeWindPowderDiagramClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(RodTypeWindPowderDiagramClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1600, 26));
        RodTypeWindPowderDiagramClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(RodTypeWindPowderDiagramClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        RodTypeWindPowderDiagramClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(RodTypeWindPowderDiagramClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        RodTypeWindPowderDiagramClass->setStatusBar(statusBar);

        retranslateUi(RodTypeWindPowderDiagramClass);

        QMetaObject::connectSlotsByName(RodTypeWindPowderDiagramClass);
    } // setupUi

    void retranslateUi(QMainWindow *RodTypeWindPowderDiagramClass)
    {
        RodTypeWindPowderDiagramClass->setWindowTitle(QCoreApplication::translate("RodTypeWindPowderDiagramClass", "RodTypeWindPowderDiagram", nullptr));
        label_c->setText(QCoreApplication::translate("RodTypeWindPowderDiagramClass", "C\345\261\202", nullptr));
        label_a->setText(QCoreApplication::translate("RodTypeWindPowderDiagramClass", "A\345\261\202", nullptr));
        label_temperature->setText(QCoreApplication::translate("RodTypeWindPowderDiagramClass", "\346\270\251\345\272\246", nullptr));
        label_pulverized_coal_concentration->setText(QCoreApplication::translate("RodTypeWindPowderDiagramClass", "\347\205\244\347\262\211\346\265\223\345\272\246", nullptr));
        label_wind_velocity->setText(QCoreApplication::translate("RodTypeWindPowderDiagramClass", "\351\243\216\351\200\237", nullptr));
        label_f->setText(QCoreApplication::translate("RodTypeWindPowderDiagramClass", "F\345\261\202", nullptr));
        label_b->setText(QCoreApplication::translate("RodTypeWindPowderDiagramClass", "B\345\261\202", nullptr));
        label_d->setText(QCoreApplication::translate("RodTypeWindPowderDiagramClass", "D\345\261\202", nullptr));
        label_e->setText(QCoreApplication::translate("RodTypeWindPowderDiagramClass", "E\345\261\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RodTypeWindPowderDiagramClass: public Ui_RodTypeWindPowderDiagramClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RODTYPEWINDPOWDERDIAGRAM_H
