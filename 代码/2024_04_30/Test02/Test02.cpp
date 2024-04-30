#include "Test02.h"

Test02::Test02(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Test02Class())
{
    ui->setupUi(this);
    _a = new AlarmDatabase;
}

Test02::~Test02()
{
    delete ui;
}

void Test02::myShow()
{
    _a->show();
}
