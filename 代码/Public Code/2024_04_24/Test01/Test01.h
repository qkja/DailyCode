#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Test01.h"

class Test01 : public QMainWindow
{
    Q_OBJECT

public:
    Test01(QWidget *parent = nullptr);
    ~Test01();

private:
    Ui::Test01Class ui;
};
