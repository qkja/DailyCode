#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_test02.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Test02Class; };
QT_END_NAMESPACE

class Test02 : public QMainWindow
{
    Q_OBJECT

public:
    Test02(QWidget *parent = nullptr);
    ~Test02();

private:
    Ui::Test02Class *ui;
};
