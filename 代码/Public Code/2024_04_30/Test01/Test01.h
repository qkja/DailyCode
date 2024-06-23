#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Test01.h"
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")// 该指令仅支持VS环境
#endif
QT_BEGIN_NAMESPACE
namespace Ui { class Test01Class; };
QT_END_NAMESPACE

class Test01 : public QMainWindow
{
    Q_OBJECT

public:
    Test01(QWidget *parent = nullptr);
    ~Test01();
    void init();
    void writeData(int data);
private:
    void createDataTable();
    void showView(int page);
private:
    Ui::Test01Class *ui;
    std::vector<int> _v;
    int _current_page_count;
    int _number_of_total_pages;
};
