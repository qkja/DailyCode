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
	this->setWindowTitle(QString("��ӭ����"));
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

	// ��� ����������2, �ͽ���������
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
	//��д�رհ�ť�¼�
	//�����ر��źţ�����������źź���ʾ����
	emit welcomeScreenCloseSignals();
}