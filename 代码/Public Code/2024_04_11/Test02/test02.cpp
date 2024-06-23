#include "test02.h"

Test02::Test02(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Test02Class())
{
    ui->setupUi(this);
}

Test02::~Test02()
{
    delete ui;
}
