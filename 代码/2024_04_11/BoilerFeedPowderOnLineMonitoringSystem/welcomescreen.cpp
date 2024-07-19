#include "welcomescreen.h"
WelcomeScreen::WelcomeScreen(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::WelcomeScreenClass())
	, _doubleClickTimer(new QTimer(this))
	, _clickCount(0)
{
	std::cout << "WelcomeScreen()" << std::endl;
	ui->setupUi(this);

	this->setWindowTitle("欢迎界面");
	_doubleClickTimer->setInterval(QApplication::doubleClickInterval());
	connect(_doubleClickTimer, &QTimer::timeout, this, &WelcomeScreen::resetClickCount);
	connect(ui->welcome_pushButton, &QPushButton::clicked, this, &WelcomeScreen::onButtonDoubleClicked);

}

WelcomeScreen::~WelcomeScreen()
{
	std::cout << "~WelcomeScreen()" << std::endl;

	delete ui;
}


void WelcomeScreen::onButtonDoubleClicked()
{
	_clickCount++;

	// 如果是双击，切换页面
	if (_clickCount == 2)
	{
		fromWelToMianScreen();
		resetClickCount();
	}
	_doubleClickTimer->start();
}

void WelcomeScreen::fromWelToMianScreen()
{
	qDebug() << "欢迎界面->主界面";

	this->hide();
	this->_main_screen->show();
}
void WelcomeScreen::resetClickCount()
{
	_clickCount = 0;
	_doubleClickTimer->stop();
}