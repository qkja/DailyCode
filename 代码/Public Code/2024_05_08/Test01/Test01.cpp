#include "Test01.h"

Test01::Test01(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Test01Class())
{
    ui->setupUi(this);
}

Test01::~Test01()
{
    delete ui;
}
