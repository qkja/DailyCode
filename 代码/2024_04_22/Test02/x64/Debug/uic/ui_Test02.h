/********************************************************************************
** Form generated from reading UI file 'Test02.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEST02_H
#define UI_TEST02_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Test02Class
{
public:

    void setupUi(QWidget *Test02Class)
    {
        if (Test02Class->objectName().isEmpty())
            Test02Class->setObjectName(QString::fromUtf8("Test02Class"));
        Test02Class->resize(600, 400);

        retranslateUi(Test02Class);

        QMetaObject::connectSlotsByName(Test02Class);
    } // setupUi

    void retranslateUi(QWidget *Test02Class)
    {
        Test02Class->setWindowTitle(QCoreApplication::translate("Test02Class", "Test02", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Test02Class: public Ui_Test02Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST02_H
