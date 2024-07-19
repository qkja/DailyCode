#include "Test04.h"

Test04::Test04(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Test04Class())
{
    ui->setupUi(this);
}

Test04::~Test04()
{
    delete ui;
}
