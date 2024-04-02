#pragma once

#include <QtWidgets/QWidget>
#include "ui_welcomescreen.h"
#include "mainscreen.h"
#include <qtimer.h>
#include "Task.hpp"
#include "producerthread.h"
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

QT_BEGIN_NAMESPACE
namespace Ui { class WelcomeScreenClass; };
QT_END_NAMESPACE

extern const QString& SERVER_IP;
extern const quint16 SERVER_PORT;

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
    void processData(Task);
private:
    Ui::WelcomeScreenClass *ui;
    MainScreen* _main_screen;
    QTimer* _doubleClickTimer;
    int _clickCount;
    ProducerThread thread;
};
