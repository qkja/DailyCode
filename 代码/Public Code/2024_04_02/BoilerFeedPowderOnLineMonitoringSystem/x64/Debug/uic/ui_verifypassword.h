/********************************************************************************
** Form generated from reading UI file 'verifypassword.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VERIFYPASSWORD_H
#define UI_VERIFYPASSWORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VerifyPasswordClass
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *identify_pushButton;
    QPushButton *cancel_pushButton;

    void setupUi(QWidget *VerifyPasswordClass)
    {
        if (VerifyPasswordClass->objectName().isEmpty())
            VerifyPasswordClass->setObjectName(QString::fromUtf8("VerifyPasswordClass"));
        VerifyPasswordClass->resize(600, 400);
        layoutWidget = new QWidget(VerifyPasswordClass);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(90, 70, 371, 211));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        identify_pushButton = new QPushButton(layoutWidget);
        identify_pushButton->setObjectName(QString::fromUtf8("identify_pushButton"));

        horizontalLayout_2->addWidget(identify_pushButton);

        cancel_pushButton = new QPushButton(layoutWidget);
        cancel_pushButton->setObjectName(QString::fromUtf8("cancel_pushButton"));

        horizontalLayout_2->addWidget(cancel_pushButton);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(VerifyPasswordClass);

        QMetaObject::connectSlotsByName(VerifyPasswordClass);
    } // setupUi

    void retranslateUi(QWidget *VerifyPasswordClass)
    {
        VerifyPasswordClass->setWindowTitle(QCoreApplication::translate("VerifyPasswordClass", "VerifyPassword", nullptr));
        label->setText(QCoreApplication::translate("VerifyPasswordClass", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201:", nullptr));
        identify_pushButton->setText(QCoreApplication::translate("VerifyPasswordClass", "\347\241\256\345\256\232", nullptr));
        cancel_pushButton->setText(QCoreApplication::translate("VerifyPasswordClass", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VerifyPasswordClass: public Ui_VerifyPasswordClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VERIFYPASSWORD_H
