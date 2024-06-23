#include "WelcomeScreen.h"

WelcomeScreen::WelcomeScreen(QWidget* parent)
	: QWidget(parent)
	, ui(new Ui::WelcomeScreenClass())
	, _doubleClickTimer(new QTimer(this))
	, _clickCount(0)
{
	ui->setupUi(this);
	std::cout << "WelcomeScreen()" << std::endl;
	init();  // ������صĳ�ʼ��
}

WelcomeScreen::~WelcomeScreen()
{
	std::cout << "~WelcomeScreen()" << std::endl;
	delete ui;
}

void WelcomeScreen::init()
{
	// �������ñ���
	this->setWindowTitle("��ӭ����");
	// �������˫���¼�
	_doubleClickTimer->setInterval(QApplication::doubleClickInterval());
	connect(_doubleClickTimer, &QTimer::timeout, this, &WelcomeScreen::resetClickCount);
	connect(ui->welcome_pushButton, &QPushButton::clicked, this, &WelcomeScreen::onButtonDoubleClicked);
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
// ��ռ�����
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