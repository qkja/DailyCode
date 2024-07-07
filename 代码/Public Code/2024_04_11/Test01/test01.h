#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_test01.h"
#include "childwin_widget.h"
#include <qpushbutton.h>
QT_BEGIN_NAMESPACE
namespace Ui { class Test01Class; };
QT_END_NAMESPACE
#include "mywidget.h"

class Test01 : public QMainWindow
{
    Q_OBJECT

public:
    Test01(QWidget *parent = nullptr);
    ~Test01();
private:
    QPushButton* NewBtn;
    ChildWin_Widget* childWin;
    MyWidget* myChildWin;

private slots:

    void NewBtnClick();
private:
    Ui::Test01Class *ui;
};
