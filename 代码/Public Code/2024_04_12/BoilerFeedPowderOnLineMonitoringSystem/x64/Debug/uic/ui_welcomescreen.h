/********************************************************************************
** Form generated from reading UI file 'welcomescreen.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WELCOMESCREEN_H
#define UI_WELCOMESCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WelcomeScreenClass
{
public:
    QPushButton *welcome_pushButton;

    void setupUi(QWidget *WelcomeScreenClass)
    {
        if (WelcomeScreenClass->objectName().isEmpty())
            WelcomeScreenClass->setObjectName(QString::fromUtf8("WelcomeScreenClass"));
        WelcomeScreenClass->resize(600, 400);
        welcome_pushButton = new QPushButton(WelcomeScreenClass);
        welcome_pushButton->setObjectName(QString::fromUtf8("welcome_pushButton"));
        welcome_pushButton->setGeometry(QRect(210, 170, 151, 91));

        retranslateUi(WelcomeScreenClass);

        QMetaObject::connectSlotsByName(WelcomeScreenClass);
    } // setupUi

    void retranslateUi(QWidget *WelcomeScreenClass)
    {
        WelcomeScreenClass->setWindowTitle(QCoreApplication::translate("WelcomeScreenClass", "WelcomeScreen", nullptr));
        welcome_pushButton->setText(QCoreApplication::translate("WelcomeScreenClass", "\351\224\205\347\202\211\347\207\203\347\203\247", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WelcomeScreenClass: public Ui_WelcomeScreenClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOMESCREEN_H
