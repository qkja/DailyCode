#include "welcomescreen.h"
#include "qdebug.h"
#include <qpushbutton.h>
#include "configurethread.h"

WelcomeScreen::WelcomeScreen(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::WelcomeScreenClass())
    ,_main_screen(new MainScreen(this))
    ,_doubleClickTimer(new QTimer(this))
    ,_clickCount(0)
{
    ui->setupUi(this);
    qDebug() << "WelcomeScreen()";
    this->setWindowTitle("欢迎界面");
    _doubleClickTimer->setInterval(QApplication::doubleClickInterval());
    connect(_doubleClickTimer, &QTimer::timeout, this,&WelcomeScreen::resetClickCount);
    connect(ui->welcome_pushButton, &QPushButton::clicked, this, &WelcomeScreen::onButtonDoubleClicked);
    connect(this->_main_screen, &MainScreen::quitSignals, [=]()
        {
            _main_screen->hide();
            this->close();
        });


    qRegisterMetaType<Task>("Task");
    connect(&_producerthread, &ProducerThread::produceSignals, this, &WelcomeScreen::processData);
    _producerthread.start();

    qRegisterMetaType<std::unordered_map<std::string, std::string>>("std::unordered_map<std::string, std::string>");
    connect(&_configurethread, &ConfigureThread::configureIsReady, this, &WelcomeScreen::processConfigure);
    _configurethread.start();
}

WelcomeScreen::~WelcomeScreen()
{
    qDebug() << "~WelcomeScreen()";
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

void WelcomeScreen::resetClickCount()
{
    _clickCount = 0;
    _doubleClickTimer->stop();
}

void WelcomeScreen::fromWelToMianScreen()
{
    qDebug() << "欢迎界面->主界面";

    this->hide();
    this->_main_screen->show();
}

void WelcomeScreen::closeEvent(QCloseEvent* event)
{
    emit stopProcessing();
}

void WelcomeScreen::processConfigure(std::unordered_map<std::string, std::string> info_map)
{
    auto iter = info_map.begin();
    while (iter != info_map.end())
    {
        std::cout << iter->first << " : " << iter->second << std::endl;
        iter++;
    }
}

void WelcomeScreen::processData(Task task)
{
    task.show();
}