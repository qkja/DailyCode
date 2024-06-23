#include "BoilerFeedPowderOnLineMonitoringSystem.h"

BoilerFeedPowderOnLineMonitoringSystem::BoilerFeedPowderOnLineMonitoringSystem(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BoilerFeedPowderOnLineMonitoringSystemClass())
{
    ui->setupUi(this);
    std::cout << "BoilerFeedPowderOnLineMonitoringSystem()" << std::endl;
    this->setWindowTitle("��¯�ͷ����߼��ϵͳ");
    init();
}

BoilerFeedPowderOnLineMonitoringSystem::~BoilerFeedPowderOnLineMonitoringSystem()
{
    std::cout << "~BoilerFeedPowderOnLineMonitoringSystem()" << std::endl;
    delete ui;
}

void BoilerFeedPowderOnLineMonitoringSystem::init()
{   

    //������Ϣ
    _configure = new Configure;
    _give_an_alarm = new GiveAnAlarm;
    SystemSettingConnect();
    _welcome_screen = new WelcomeScreen;
    _welcome_screen->show();
    // �ӻ�ӭ������ʾ����ҳ��
    connect(_welcome_screen, &WelcomeScreen::fromWelToMianScreenSignals, [=]() {
        this->show();
        _welcome_screen->hide();
        });
}

void BoilerFeedPowderOnLineMonitoringSystem::SystemSettingConnect()
{
    connect(_give_an_alarm, &QWidget::destroyed, [=]() {
        _give_an_alarm = nullptr;
        this->show();
        
        });
    connect(ui->action_give_an_alarm, &QAction::triggered, [=]() {
        if (nullptr == _give_an_alarm)
            _give_an_alarm = new GiveAnAlarm;
        _give_an_alarm->setAttribute(Qt::WA_DeleteOnClose); // �����ڹر�ʱ�Զ�ɾ������
        this->hide();
        _give_an_alarm->show();
        });
}

