#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Test03.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Test03Class; };
QT_END_NAMESPACE

class Test03 : public QMainWindow
{
    Q_OBJECT

public:
    Test03(QWidget *parent = nullptr);
    ~Test03();

private:
    Ui::Test03Class *ui;
};
