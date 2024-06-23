/********************************************************************************
** Form generated from reading UI file 'spout.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPOUT_H
#define UI_SPOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SpoutClass
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QLineEdit *lineEdit_7;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLineEdit *lineEdit_6;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *lineEdit_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *save_pushButton;
    QPushButton *modify_pushButton;
    QPushButton *quit_pushButton;

    void setupUi(QWidget *SpoutClass)
    {
        if (SpoutClass->objectName().isEmpty())
            SpoutClass->setObjectName(QString::fromUtf8("SpoutClass"));
        SpoutClass->resize(686, 689);
        layoutWidget = new QWidget(SpoutClass);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(90, 30, 501, 591));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
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

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_7->addWidget(label_7);

        lineEdit_7 = new QLineEdit(layoutWidget);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));

        horizontalLayout_7->addWidget(lineEdit_7);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_6->addWidget(label_6);

        lineEdit_6 = new QLineEdit(layoutWidget);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));

        horizontalLayout_6->addWidget(lineEdit_6);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_2 = new QLineEdit(layoutWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout_2->addWidget(lineEdit_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        lineEdit_3 = new QLineEdit(layoutWidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        horizontalLayout_3->addWidget(lineEdit_3);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_5->addWidget(label_5);

        lineEdit_5 = new QLineEdit(layoutWidget);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));

        horizontalLayout_5->addWidget(lineEdit_5);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        lineEdit_4 = new QLineEdit(layoutWidget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        horizontalLayout_4->addWidget(lineEdit_4);


        verticalLayout->addLayout(horizontalLayout_4);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        save_pushButton = new QPushButton(layoutWidget);
        save_pushButton->setObjectName(QString::fromUtf8("save_pushButton"));

        horizontalLayout_8->addWidget(save_pushButton);

        modify_pushButton = new QPushButton(layoutWidget);
        modify_pushButton->setObjectName(QString::fromUtf8("modify_pushButton"));

        horizontalLayout_8->addWidget(modify_pushButton);

        quit_pushButton = new QPushButton(layoutWidget);
        quit_pushButton->setObjectName(QString::fromUtf8("quit_pushButton"));

        horizontalLayout_8->addWidget(quit_pushButton);


        verticalLayout_2->addLayout(horizontalLayout_8);


        retranslateUi(SpoutClass);

        QMetaObject::connectSlotsByName(SpoutClass);
    } // setupUi

    void retranslateUi(QWidget *SpoutClass)
    {
        SpoutClass->setWindowTitle(QCoreApplication::translate("SpoutClass", "Spout", nullptr));
        label->setText(QCoreApplication::translate("SpoutClass", "A\345\261\202\345\226\267\345\217\243\351\235\242\347\247\257:", nullptr));
        label_7->setText(QCoreApplication::translate("SpoutClass", "B\345\261\202\345\226\267\345\217\243\351\235\242\347\247\257:", nullptr));
        label_6->setText(QCoreApplication::translate("SpoutClass", "C\345\261\202\345\226\267\345\217\243\351\235\242\347\247\257:", nullptr));
        label_2->setText(QCoreApplication::translate("SpoutClass", "D\345\261\202\345\226\267\345\217\243\351\235\242\347\247\257:", nullptr));
        label_3->setText(QCoreApplication::translate("SpoutClass", "E\345\261\202\345\226\267\345\217\243\351\235\242\347\247\257:", nullptr));
        label_5->setText(QCoreApplication::translate("SpoutClass", "F\345\261\202\345\226\267\345\217\243\351\235\242\347\247\257:", nullptr));
        label_4->setText(QCoreApplication::translate("SpoutClass", "\347\256\241\351\201\223\351\235\242\347\247\257:  ", nullptr));
        save_pushButton->setText(QCoreApplication::translate("SpoutClass", "\344\277\235\345\255\230", nullptr));
        modify_pushButton->setText(QCoreApplication::translate("SpoutClass", "\344\277\256\346\224\271", nullptr));
        quit_pushButton->setText(QCoreApplication::translate("SpoutClass", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SpoutClass: public Ui_SpoutClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPOUT_H
