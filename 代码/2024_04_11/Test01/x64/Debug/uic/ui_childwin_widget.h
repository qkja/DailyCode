/********************************************************************************
** Form generated from reading UI file 'childwin_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHILDWIN_WIDGET_H
#define UI_CHILDWIN_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChildWin_WidgetClass
{
public:

    void setupUi(QWidget *ChildWin_WidgetClass)
    {
        if (ChildWin_WidgetClass->objectName().isEmpty())
            ChildWin_WidgetClass->setObjectName(QString::fromUtf8("ChildWin_WidgetClass"));
        ChildWin_WidgetClass->resize(600, 400);

        retranslateUi(ChildWin_WidgetClass);

        QMetaObject::connectSlotsByName(ChildWin_WidgetClass);
    } // setupUi

    void retranslateUi(QWidget *ChildWin_WidgetClass)
    {
        ChildWin_WidgetClass->setWindowTitle(QCoreApplication::translate("ChildWin_WidgetClass", "ChildWin_Widget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChildWin_WidgetClass: public Ui_ChildWin_WidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHILDWIN_WIDGET_H
