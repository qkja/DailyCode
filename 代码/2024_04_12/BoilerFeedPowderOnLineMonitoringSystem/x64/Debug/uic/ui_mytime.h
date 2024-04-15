/********************************************************************************
** Form generated from reading UI file 'mytime.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYTIME_H
#define UI_MYTIME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyTimeClass
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *identify_pushButton;
    QPushButton *cancel_pushButton;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDateEdit *dateEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QTimeEdit *timeEdit;

    void setupUi(QWidget *MyTimeClass)
    {
        if (MyTimeClass->objectName().isEmpty())
            MyTimeClass->setObjectName(QString::fromUtf8("MyTimeClass"));
        MyTimeClass->resize(461, 332);
        layoutWidget = new QWidget(MyTimeClass);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(120, 240, 211, 41));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        identify_pushButton = new QPushButton(layoutWidget);
        identify_pushButton->setObjectName(QString::fromUtf8("identify_pushButton"));

        horizontalLayout_3->addWidget(identify_pushButton);

        cancel_pushButton = new QPushButton(layoutWidget);
        cancel_pushButton->setObjectName(QString::fromUtf8("cancel_pushButton"));

        horizontalLayout_3->addWidget(cancel_pushButton);

        layoutWidget_2 = new QWidget(MyTimeClass);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(90, 50, 281, 101));
        verticalLayout = new QVBoxLayout(layoutWidget_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(layoutWidget_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        dateEdit = new QDateEdit(layoutWidget_2);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));

        horizontalLayout->addWidget(dateEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        timeEdit = new QTimeEdit(layoutWidget_2);
        timeEdit->setObjectName(QString::fromUtf8("timeEdit"));

        horizontalLayout_2->addWidget(timeEdit);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(MyTimeClass);

        QMetaObject::connectSlotsByName(MyTimeClass);
    } // setupUi

    void retranslateUi(QWidget *MyTimeClass)
    {
        MyTimeClass->setWindowTitle(QCoreApplication::translate("MyTimeClass", "MyTime", nullptr));
        identify_pushButton->setText(QCoreApplication::translate("MyTimeClass", "\347\241\256\345\256\232", nullptr));
        cancel_pushButton->setText(QCoreApplication::translate("MyTimeClass", "\345\217\226\346\266\210", nullptr));
        label->setText(QCoreApplication::translate("MyTimeClass", "\346\227\245\346\234\237:", nullptr));
        label_2->setText(QCoreApplication::translate("MyTimeClass", "\346\227\266\351\227\264: ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyTimeClass: public Ui_MyTimeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYTIME_H
