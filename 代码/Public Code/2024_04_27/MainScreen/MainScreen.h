#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainScreen.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainScreenClass; };
QT_END_NAMESPACE

class MainScreen : public QMainWindow
{
    Q_OBJECT

public:
    MainScreen(QWidget *parent = nullptr);
    ~MainScreen();

private:
    Ui::MainScreenClass *ui;
};
