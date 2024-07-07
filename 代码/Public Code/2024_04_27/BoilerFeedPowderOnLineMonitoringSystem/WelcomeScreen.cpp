#include "WelcomeScreen.h"

WelcomeScreen::WelcomeScreen(QWidget* parent)
	: QWidget(parent)
	, ui(new Ui::WelcomeScreenClass())
	, _doubleClickTimer(new QTimer(this))
	, _clickCount(0)
{
	ui->setupUi(this);
	std::cout << "WelcomeScreen()" << std::endl;
	init();  // 进行相关的初始化
}

WelcomeScreen::~WelcomeScreen()
{
	std::cout << "~WelcomeScreen()" << std::endl;
	delete ui;
}

void WelcomeScreen::init()
{
	// 窗口设置标题
	this->setWindowTitle("欢迎界面");
	// 检测鼠标的双击事件
	_doubleClickTimer->setInterval(QApplication::doubleClickInterval());
	connect(_doubleClickTimer, &QTimer::timeout, this, &WelcomeScreen::resetClickCount);
	connect(ui->welcome_pushButton, &QPushButton::clicked, this, &WelcomeScreen::onButtonDoubleClicked);
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
// 清空计数器
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