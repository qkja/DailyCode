/********************************************************************************
** Form generated from reading UI file 'wordofcommand.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WORDOFCOMMAND_H
#define UI_WORDOFCOMMAND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WordOfCommandClass
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *old_password;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *new_password;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *identify_pushButton;
    QPushButton *cancel_pushButton;

    void setupUi(QWidget *WordOfCommandClass)
    {
        if (WordOfCommandClass->objectName().isEmpty())
            WordOfCommandClass->setObjectName(QString::fromUtf8("WordOfCommandClass"));
        WordOfCommandClass->resize(600, 400);
        layoutWidget = new QWidget(WordOfCommandClass);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(130, 90, 281, 101));
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

        old_password = new QLineEdit(layoutWidget);
        old_password->setObjectName(QString::fromUtf8("old_password"));

        horizontalLayout->addWidget(old_password);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        new_password = new QLineEdit(layoutWidget);
        new_password->setObjectName(QString::fromUtf8("new_password"));

        horizontalLayout_2->addWidget(new_password);


        verticalLayout->addLayout(horizontalLayout_2);

        layoutWidget_2 = new QWidget(WordOfCommandClass);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(120, 250, 301, 91));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        identify_pushButton = new QPushButton(layoutWidget_2);
        identify_pushButton->setObjectName(QString::fromUtf8("identify_pushButton"));

        horizontalLayout_3->addWidget(identify_pushButton);

        cancel_pushButton = new QPushButton(layoutWidget_2);
        cancel_pushButton->setObjectName(QString::fromUtf8("cancel_pushButton"));

        horizontalLayout_3->addWidget(cancel_pushButton);


        retranslateUi(WordOfCommandClass);

        QMetaObject::connectSlotsByName(WordOfCommandClass);
    } // setupUi

    void retranslateUi(QWidget *WordOfCommandClass)
    {
        WordOfCommandClass->setWindowTitle(QCoreApplication::translate("WordOfCommandClass", "WordOfCommand", nullptr));
        label->setText(QCoreApplication::translate("WordOfCommandClass", "\346\227\247\345\217\243\344\273\244", nullptr));
        label_2->setText(QCoreApplication::translate("WordOfCommandClass", "\346\226\260\345\217\243\344\273\244", nullptr));
        identify_pushButton->setText(QCoreApplication::translate("WordOfCommandClass", "\347\241\256\345\256\232", nullptr));
        cancel_pushButton->setText(QCoreApplication::translate("WordOfCommandClass", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WordOfCommandClass: public Ui_WordOfCommandClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORDOFCOMMAND_H
