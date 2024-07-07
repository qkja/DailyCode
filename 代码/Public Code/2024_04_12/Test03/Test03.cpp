#include "Test03.h"

Test03::Test03(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Test03Class())
{
    ui->setupUi(this);
}

Test03::~Test03()
{
    delete ui;
}
