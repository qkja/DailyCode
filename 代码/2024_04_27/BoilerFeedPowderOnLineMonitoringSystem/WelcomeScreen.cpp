#include "WelcomeScreen.h"

WelcomeScreen::WelcomeScreen(QWidget* parent)
	: QWidget(parent)
	, ui(new Ui::WelcomeScreenClass())
	, _doubleClickTimer(new QTimer(this))
	, _clickCount(0)
{
	ui->setupUi(this);
	ui->setupUi(this);
	std::cout << "WelcomeScreen()" << std::endl;
	this->setWindowTitle(QString("欢迎界面"));
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

	// 如果 计数器到达2, 就进入主界面
	if (_clickCount == 2)
	{
		resetClickCount();
		emit fromWelToMianScreenSignals();
	}
	_doubleClickTimer->start();
}

void WelcomeScreen::resetClickCount()
{
	_clickCount = 0;
	_doubleClickTimer->stop();
}

void WelcomeScreen::closeEvent(QCloseEvent*)
{
	//重写关闭按钮事件
	//发出关闭信号，父窗体接收信号后显示窗体
	emit welcomeScreenCloseSignals();
}