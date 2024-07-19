#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Test04.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Test04Class; };
QT_END_NAMESPACE

class Test04 : public QMainWindow
{
    Q_OBJECT

public:
    Test04(QWidget *parent = nullptr);
    ~Test04();

private:
    Ui::Test04Class *ui;
};
