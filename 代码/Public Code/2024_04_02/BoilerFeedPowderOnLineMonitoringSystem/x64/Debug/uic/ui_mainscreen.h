/********************************************************************************
** Form generated from reading UI file 'mainscreen.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINSCREEN_H
#define UI_MAINSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainScreenClass
{
public:
    QAction *quit_action;
    QAction *give_an_alarm_action;
    QAction *mytime_action;
    QAction *word_of_command_action;
    QAction *spout_action;
    QAction *backrest_canal_action;
    QAction *rod_type_wind_powder_diagram_action;
    QAction *tangential_circle_diagram_of_primary_wind_action;
    QAction *trend_chart_action;
    QAction *historical_trend_chart_action;
    QAction *alarm_database_action;
    QAction *channel_database_action;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainScreenClass)
    {
        if (MainScreenClass->objectName().isEmpty())
            MainScreenClass->setObjectName(QString::fromUtf8("MainScreenClass"));
        MainScreenClass->resize(1292, 538);
        quit_action = new QAction(MainScreenClass);
        quit_action->setObjectName(QString::fromUtf8("quit_action"));
        give_an_alarm_action = new QAction(MainScreenClass);
        give_an_alarm_action->setObjectName(QString::fromUtf8("give_an_alarm_action"));
        mytime_action = new QAction(MainScreenClass);
        mytime_action->setObjectName(QString::fromUtf8("mytime_action"));
        word_of_command_action = new QAction(MainScreenClass);
        word_of_command_action->setObjectName(QString::fromUtf8("word_of_command_action"));
        spout_action = new QAction(MainScreenClass);
        spout_action->setObjectName(QString::fromUtf8("spout_action"));
        backrest_canal_action = new QAction(MainScreenClass);
        backrest_canal_action->setObjectName(QString::fromUtf8("backrest_canal_action"));
        rod_type_wind_powder_diagram_action = new QAction(MainScreenClass);
        rod_type_wind_powder_diagram_action->setObjectName(QString::fromUtf8("rod_type_wind_powder_diagram_action"));
        tangential_circle_diagram_of_primary_wind_action = new QAction(MainScreenClass);
        tangential_circle_diagram_of_primary_wind_action->setObjectName(QString::fromUtf8("tangential_circle_diagram_of_primary_wind_action"));
        trend_chart_action = new QAction(MainScreenClass);
        trend_chart_action->setObjectName(QString::fromUtf8("trend_chart_action"));
        historical_trend_chart_action = new QAction(MainScreenClass);
        historical_trend_chart_action->setObjectName(QString::fromUtf8("historical_trend_chart_action"));
        alarm_database_action = new QAction(MainScreenClass);
        alarm_database_action->setObjectName(QString::fromUtf8("alarm_database_action"));
        channel_database_action = new QAction(MainScreenClass);
        channel_database_action->setObjectName(QString::fromUtf8("channel_database_action"));
        centralWidget = new QWidget(MainScreenClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        MainScreenClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainScreenClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1292, 26));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        menu_4 = new QMenu(menuBar);
        menu_4->setObjectName(QString::fromUtf8("menu_4"));
        MainScreenClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainScreenClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainScreenClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainScreenClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainScreenClass->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menuBar->addAction(menu_4->menuAction());
        menu->addAction(quit_action);
        menu->addAction(give_an_alarm_action);
        menu->addAction(mytime_action);
        menu->addAction(word_of_command_action);
        menu->addAction(spout_action);
        menu->addAction(backrest_canal_action);
        menu_2->addAction(rod_type_wind_powder_diagram_action);
        menu_2->addAction(tangential_circle_diagram_of_primary_wind_action);
        menu_2->addAction(trend_chart_action);
        menu_2->addAction(historical_trend_chart_action);
        menu_3->addAction(alarm_database_action);
        menu_3->addAction(channel_database_action);

        retranslateUi(MainScreenClass);

        QMetaObject::connectSlotsByName(MainScreenClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainScreenClass)
    {
        MainScreenClass->setWindowTitle(QCoreApplication::translate("MainScreenClass", "MainScreen", nullptr));
        quit_action->setText(QCoreApplication::translate("MainScreenClass", "\351\200\200\345\207\272", nullptr));
        give_an_alarm_action->setText(QCoreApplication::translate("MainScreenClass", "\350\256\276\345\256\232\346\212\245\350\255\246\351\231\220", nullptr));
        mytime_action->setText(QCoreApplication::translate("MainScreenClass", "\344\277\256\350\256\242\346\227\266\351\227\264", nullptr));
        word_of_command_action->setText(QCoreApplication::translate("MainScreenClass", "\344\277\256\346\224\271\345\217\243\344\273\244", nullptr));
        spout_action->setText(QCoreApplication::translate("MainScreenClass", "\350\256\276\345\256\232\345\226\267\345\217\243\351\235\242\347\247\257", nullptr));
        backrest_canal_action->setText(QCoreApplication::translate("MainScreenClass", "\350\203\214\351\235\240\347\256\241\347\263\273\346\225\260\344\277\256\346\255\243", nullptr));
        rod_type_wind_powder_diagram_action->setText(QCoreApplication::translate("MainScreenClass", "\346\243\222\345\275\242\347\205\244\347\262\211\345\233\276", nullptr));
        tangential_circle_diagram_of_primary_wind_action->setText(QCoreApplication::translate("MainScreenClass", "\344\270\200\346\254\241\351\243\216\345\210\207\345\234\206\345\233\276", nullptr));
        trend_chart_action->setText(QCoreApplication::translate("MainScreenClass", "\350\266\213\345\212\277\345\233\276", nullptr));
        historical_trend_chart_action->setText(QCoreApplication::translate("MainScreenClass", "\345\216\206\345\217\262\350\266\213\345\212\277\345\233\276", nullptr));
        alarm_database_action->setText(QCoreApplication::translate("MainScreenClass", "\346\212\245\350\255\246\346\225\260\346\215\256", nullptr));
        channel_database_action->setText(QCoreApplication::translate("MainScreenClass", "\351\200\232\351\201\223\346\225\260\346\215\256", nullptr));
        menu->setTitle(QCoreApplication::translate("MainScreenClass", "\347\263\273\347\273\237\350\256\276\347\275\256", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainScreenClass", "\347\212\266\346\200\201\346\237\245\347\234\213", nullptr));
        menu_3->setTitle(QCoreApplication::translate("MainScreenClass", "\346\225\260\346\215\256\345\244\204\347\220\206", nullptr));
        menu_4->setTitle(QCoreApplication::translate("MainScreenClass", "\345\270\256\345\212\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainScreenClass: public Ui_MainScreenClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINSCREEN_H
