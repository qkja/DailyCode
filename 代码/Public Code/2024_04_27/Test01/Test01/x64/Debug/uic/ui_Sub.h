/********************************************************************************
** Form generated from reading UI file 'Sub.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUB_H
#define UI_SUB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SubClass
{
public:
    QLabel *label;

    void setupUi(QWidget *SubClass)
    {
        if (SubClass->objectName().isEmpty())
            SubClass->setObjectName(QString::fromUtf8("SubClass"));
        SubClass->resize(600, 400);
        label = new QLabel(SubClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 150, 251, 101));

        retranslateUi(SubClass);

        QMetaObject::connectSlotsByName(SubClass);
    } // setupUi

    void retranslateUi(QWidget *SubClass)
    {
        SubClass->setWindowTitle(QCoreApplication::translate("SubClass", "Sub", nullptr));
        label->setText(QCoreApplication::translate("SubClass", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SubClass: public Ui_SubClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUB_H
