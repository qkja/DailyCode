#pragma once

#include <QtWidgets/QWidget>
#include "ui_Test02.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Test02Class; };
QT_END_NAMESPACE

class Test02 : public QWidget
{
    Q_OBJECT

public:
    Test02(QWidget *parent = nullptr);
    ~Test02();

private:
    Ui::Test02Class *ui;
};
