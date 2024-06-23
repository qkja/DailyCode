#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_test01.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Test01Class; };
QT_END_NAMESPACE

class Test01 : public QMainWindow
{
    Q_OBJECT

public:
    Test01(QWidget *parent = nullptr);
    ~Test01();

private:
    Ui::Test01Class *ui;
};
