#include "MainScreen.h"

MainScreen::MainScreen(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScreenClass())
{
    ui->setupUi(this);
}

MainScreen::~MainScreen()
{
    delete ui;
}
