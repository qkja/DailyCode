/********************************************************************************
** Form generated from reading UI file 'Test01.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEST01_H
#define UI_TEST01_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Test01Class
{
public:
    QWidget *centralWidget;
    QTableWidget *tableWidget;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *CurPageLable;
    QLabel *label;
    QLabel *TotalPageLable;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QWidget *widget1;
    QVBoxLayout *verticalLayout;
    QPushButton *FirstPageBtn;
    QPushButton *LastPageBtn;
    QPushButton *PrevPageBtn;
    QPushButton *NextPageBtn;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLineEdit *currentRowLineEdit;
    QPushButton *addBtn;
    QPushButton *insertBtn;
    QPushButton *delBtn;
    QLabel *label_5;
    QLineEdit *input;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Test01Class)
    {
        if (Test01Class->objectName().isEmpty())
            Test01Class->setObjectName(QString::fromUtf8("Test01Class"));
        Test01Class->resize(1311, 706);
        centralWidget = new QWidget(Test01Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tableWidget = new QTableWidget(centralWidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(70, 120, 1131, 331));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(120, 510, 611, 61));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        CurPageLable = new QLabel(widget);
        CurPageLable->setObjectName(QString::fromUtf8("CurPageLable"));

        horizontalLayout->addWidget(CurPageLable);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        TotalPageLable = new QLabel(widget);
        TotalPageLable->setObjectName(QString::fromUtf8("TotalPageLable"));

        horizontalLayout->addWidget(TotalPageLable);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        widget1 = new QWidget(centralWidget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(1080, 490, 82, 119));
        verticalLayout = new QVBoxLayout(widget1);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        FirstPageBtn = new QPushButton(widget1);
        FirstPageBtn->setObjectName(QString::fromUtf8("FirstPageBtn"));

        verticalLayout->addWidget(FirstPageBtn);

        LastPageBtn = new QPushButton(widget1);
        LastPageBtn->setObjectName(QString::fromUtf8("LastPageBtn"));

        verticalLayout->addWidget(LastPageBtn);

        PrevPageBtn = new QPushButton(widget1);
        PrevPageBtn->setObjectName(QString::fromUtf8("PrevPageBtn"));

        verticalLayout->addWidget(PrevPageBtn);

        NextPageBtn = new QPushButton(widget1);
        NextPageBtn->setObjectName(QString::fromUtf8("NextPageBtn"));

        verticalLayout->addWidget(NextPageBtn);

        widget2 = new QWidget(centralWidget);
        widget2->setObjectName(QString::fromUtf8("widget2"));
        widget2->setGeometry(QRect(80, 30, 901, 51));
        horizontalLayout_2 = new QHBoxLayout(widget2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(widget2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        currentRowLineEdit = new QLineEdit(widget2);
        currentRowLineEdit->setObjectName(QString::fromUtf8("currentRowLineEdit"));

        horizontalLayout_2->addWidget(currentRowLineEdit);

        addBtn = new QPushButton(widget2);
        addBtn->setObjectName(QString::fromUtf8("addBtn"));

        horizontalLayout_2->addWidget(addBtn);

        insertBtn = new QPushButton(widget2);
        insertBtn->setObjectName(QString::fromUtf8("insertBtn"));

        horizontalLayout_2->addWidget(insertBtn);

        delBtn = new QPushButton(widget2);
        delBtn->setObjectName(QString::fromUtf8("delBtn"));

        horizontalLayout_2->addWidget(delBtn);

        label_5 = new QLabel(widget2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_2->addWidget(label_5);

        input = new QLineEdit(widget2);
        input->setObjectName(QString::fromUtf8("input"));

        horizontalLayout_2->addWidget(input);

        Test01Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Test01Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1311, 25));
        Test01Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Test01Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Test01Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Test01Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Test01Class->setStatusBar(statusBar);

        retranslateUi(Test01Class);

        QMetaObject::connectSlotsByName(Test01Class);
    } // setupUi

    void retranslateUi(QMainWindow *Test01Class)
    {
        Test01Class->setWindowTitle(QCoreApplication::translate("Test01Class", "Test01", nullptr));
        CurPageLable->setText(QCoreApplication::translate("Test01Class", "\347\254\254\345\207\240\351\241\265", nullptr));
        label->setText(QCoreApplication::translate("Test01Class", "/", nullptr));
        TotalPageLable->setText(QCoreApplication::translate("Test01Class", "\345\205\261\345\207\240\351\241\265", nullptr));
        label_2->setText(QCoreApplication::translate("Test01Class", "\350\267\263\350\275\254\345\210\260\347\254\254", nullptr));
        label_3->setText(QCoreApplication::translate("Test01Class", "\351\241\265", nullptr));
        FirstPageBtn->setText(QCoreApplication::translate("Test01Class", "\351\246\226\351\241\265", nullptr));
        LastPageBtn->setText(QCoreApplication::translate("Test01Class", "\345\260\276\351\241\265", nullptr));
        PrevPageBtn->setText(QCoreApplication::translate("Test01Class", "\344\270\212\344\270\200\351\241\265", nullptr));
        NextPageBtn->setText(QCoreApplication::translate("Test01Class", "\344\270\213\344\270\200\351\241\265", nullptr));
        label_4->setText(QCoreApplication::translate("Test01Class", "\345\275\223\345\211\215\350\241\214\345\217\267", nullptr));
        addBtn->setText(QCoreApplication::translate("Test01Class", "\346\267\273\345\212\240\344\270\200\350\241\214", nullptr));
        insertBtn->setText(QCoreApplication::translate("Test01Class", "\346\217\222\345\205\245\344\270\200\350\241\214", nullptr));
        delBtn->setText(QCoreApplication::translate("Test01Class", "\345\210\240\351\231\244\344\270\200\350\241\214", nullptr));
        label_5->setText(QCoreApplication::translate("Test01Class", "\345\256\232\344\275\215\345\210\260\346\214\207\345\256\232\350\241\214", nullptr));
        input->setText(QCoreApplication::translate("Test01Class", "\350\257\267\350\276\223\345\205\245\346\237\245\350\257\242\345\206\205\345\256\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Test01Class: public Ui_Test01Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST01_H
