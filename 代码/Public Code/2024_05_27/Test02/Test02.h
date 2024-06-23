#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Test02.h"

class Test02 : public QMainWindow
{
    Q_OBJECT

public:
    Test02(QWidget *parent = nullptr);
    ~Test02();
    void f();

private:
    Ui::Test02Class ui;
};
