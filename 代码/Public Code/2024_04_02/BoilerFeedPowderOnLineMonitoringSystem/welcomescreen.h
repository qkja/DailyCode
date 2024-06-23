#pragma once

#include <QtWidgets/QWidget>
#include "ui_welcomescreen.h"
#include <qtimer.h>
#include "mainscreen.h"
#include "Task.hpp"
#include "producerthread.h"
#include "configurethread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class WelcomeScreenClass; };
QT_END_NAMESPACE

class WelcomeScreen : public QWidget
{
    Q_OBJECT

public:
    WelcomeScreen(QWidget *parent = nullptr);
    ~WelcomeScreen();
private:
    void onButtonDoubleClicked();
    void resetClickCount();
    void fromWelToMianScreen();
    void closeEvent(QCloseEvent* event);
signals:
    void stopProcessing();
    
protected slots:
    void processData(Task);
    void processConfigure(std::unordered_map<std::string, std::string>);
private:
    Ui::WelcomeScreenClass *ui;
    MainScreen* _main_screen;
    QTimer* _doubleClickTimer;
    int _clickCount;
    ProducerThread _producerthread;   //  生产线程
    ConfigureThread _configurethread; //  配置线程
};
