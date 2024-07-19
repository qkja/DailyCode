/********************************************************************************
** Form generated from reading UI file 'trendlinechart.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRENDLINECHART_H
#define UI_TRENDLINECHART_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TrendLineChartClass
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QComboBox *comboBox;

    void setupUi(QWidget *TrendLineChartClass)
    {
        if (TrendLineChartClass->objectName().isEmpty())
            TrendLineChartClass->setObjectName(QString::fromUtf8("TrendLineChartClass"));
        TrendLineChartClass->resize(1192, 670);
        pushButton = new QPushButton(TrendLineChartClass);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(70, 40, 89, 24));
        pushButton_2 = new QPushButton(TrendLineChartClass);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(100, 90, 89, 24));
        pushButton_3 = new QPushButton(TrendLineChartClass);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(120, 190, 89, 24));
        pushButton_4 = new QPushButton(TrendLineChartClass);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(120, 310, 89, 24));
        comboBox = new QComboBox(TrendLineChartClass);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(390, 140, 89, 23));

        retranslateUi(TrendLineChartClass);

        QMetaObject::connectSlotsByName(TrendLineChartClass);
    } // setupUi

    void retranslateUi(QWidget *TrendLineChartClass)
    {
        TrendLineChartClass->setWindowTitle(QCoreApplication::translate("TrendLineChartClass", "TrendLineChart", nullptr));
        pushButton->setText(QCoreApplication::translate("TrendLineChartClass", "PushButton", nullptr));
        pushButton_2->setText(QCoreApplication::translate("TrendLineChartClass", "PushButton", nullptr));
        pushButton_3->setText(QCoreApplication::translate("TrendLineChartClass", "PushButton", nullptr));
        pushButton_4->setText(QCoreApplication::translate("TrendLineChartClass", "PushButton", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("TrendLineChartClass", "1", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("TrendLineChartClass", "2", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("TrendLineChartClass", "3", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("TrendLineChartClass", "4", nullptr));

    } // retranslateUi

};

namespace Ui {
    class TrendLineChartClass: public Ui_TrendLineChartClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRENDLINECHART_H
