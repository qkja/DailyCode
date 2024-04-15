#include "boilerfeedpowderonlinemonitoringsystem.h"

BoilerFeedPowderOnLineMonitoringSystem::BoilerFeedPowderOnLineMonitoringSystem(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::BoilerFeedPowderOnLineMonitoringSystemClass()), _welcomeScreen(new WelcomeScreen(nullptr)), _verify_password(new VerifyPassword(nullptr)), _system_setting(new SystemSetting(nullptr)), _status_view(new StatusView(nullptr)), _data_processing(new DataProcessing(nullptr))
{
    std::cout << "BoilerFeedPowderOnLineMonitoringSystem()" << std::endl;
    ui->setupUi(this);
    _welcomeScreen->show();
    this->setWindowTitle("你好");
    init();
    startThread();
}
void BoilerFeedPowderOnLineMonitoringSystem::init()
{
    SystemSettingConnect();
    StatusViewConnect();
    DataProcessingConnect();
    AssistConnect();
}
void BoilerFeedPowderOnLineMonitoringSystem::startThread()
{
    connect(this, &BoilerFeedPowderOnLineMonitoringSystem::stopThread, &_myThread, &MyThread::stopProcessing);
    connect(this, &BoilerFeedPowderOnLineMonitoringSystem::quitSignals, this, &BoilerFeedPowderOnLineMonitoringSystem::quit);
    connect(_welcomeScreen, &WelcomeScreen::fromWelToMianScreenSignals, this, &BoilerFeedPowderOnLineMonitoringSystem::fromWelToMianScreen);

    qRegisterMetaType<Task>("Task");
    connect(&_myThread, &MyThread::produceSignals, this, &BoilerFeedPowderOnLineMonitoringSystem::processData);
    qRegisterMetaType<std::unordered_map<std::string, std::string>>("std::unordered_map<std::string, std::string>");
    connect(_myThread._configure, &Configure::_configureIsReady, this, &BoilerFeedPowderOnLineMonitoringSystem::processConfigure);
    _myThread.start();
}
void BoilerFeedPowderOnLineMonitoringSystem::closeEvent(QCloseEvent *event)
{
    emit stopThread();
    this->closeEvent(event);
}
BoilerFeedPowderOnLineMonitoringSystem::~BoilerFeedPowderOnLineMonitoringSystem()
{
    std::cout << "~BoilerFeedPowderOnLineMonitoringSystem()" << std::endl;
    delete _welcomeScreen;
    delete _status_view;
    delete ui;
}

void BoilerFeedPowderOnLineMonitoringSystem::quit()
{
    this->hide();
    this->close();
}
void BoilerFeedPowderOnLineMonitoringSystem::processConfigure(std::unordered_map<std::string, std::string> info_map)
{
    auto iter = info_map.begin();
    while (iter != info_map.end())
    {
        std::cout << iter->first << " : " << iter->second << std::endl;
        iter++;
    }
}

void BoilerFeedPowderOnLineMonitoringSystem::processData(Task task)
{
    // task.show();
}

void BoilerFeedPowderOnLineMonitoringSystem::fromWelToMianScreen()
{
    this->show();
    _welcomeScreen->hide();
}

void BoilerFeedPowderOnLineMonitoringSystem::SystemSettingConnect()
{
    // �˳�
    connect(ui->quit_action, &QAction::triggered, [=]()
            { emit quitSignals(); });

    // �趨������
    connect(ui->give_an_alarm_action, &QAction::triggered, [=]()
            {
            this->hide();
            this->_system_setting->_give_an_alarm->show(); });
    connect(this->_system_setting->_give_an_alarm, &GiveAnAlarm::fromGiveAnAlarmToMainScreenSignals, [=]()
            {
            // ������һ������ؼ����ر�,�����Ƿ���Ҫ��һЩ����
            qDebug() << "���������Ѿ�ȡ��";
            this->_system_setting->_give_an_alarm->hide();
            this->show(); });

    // ������ϵ������
    connect(ui->backrest_canal_action, &QAction::triggered, [=]()
            {
            this->_verify_password->show();

            connect(this->_verify_password, &VerifyPassword::fromVerifyPasswordSignalsIsTrue, [=]() {
                qDebug() << "��֤�����Ѿ�������";
                this->hide();
                this->_verify_password->hide();
                this->_system_setting->_backrest_canal->show();
                });
            connect(this->_verify_password, &VerifyPassword::fromVerifyPasswordSignalsIsFalse, [=]() {
                qDebug() << "��֤�����Ѿ�ȡ����";
                this->_verify_password->hide();
                }); });

    connect(this->_system_setting->_backrest_canal, &BackrestCanal::fromBackrestCanalToMainScreenSignals, [=]()
            {
            qDebug() << "�趨ϵ�������Ľ����Ѿ�ȡ��";
            this->_system_setting->_backrest_canal->hide();
            this->show(); });

    //  �趨������
    connect(ui->spout_action, &QAction::triggered, [=]()
            {
            this->_verify_password->show();
            connect(this->_verify_password, &VerifyPassword::fromVerifyPasswordSignalsIsTrue, [=]() {
                qDebug() << "��֤�����Ѿ�������";
                this->hide();
                this->_verify_password->hide();
                this->_system_setting->_spout->show();
                });
            connect(this->_verify_password, &VerifyPassword::fromVerifyPasswordSignalsIsFalse, [=]() {
                qDebug() << "��֤�����Ѿ�ȡ����";
                this->_verify_password->hide();
                }); });
    connect(this->_system_setting->_spout, &Spout::fromSpoutToMianScreenSignals, [=]()
            {
            qDebug() << "�趨�����������Ѿ�ȡ��";
            this->_system_setting->_spout->hide();
            this->show(); });

    // �޸Ŀ���
    connect(ui->word_of_command_action, &QAction::triggered, [=]()
            {
            this->hide();
            this->_system_setting->_word_of_command->show(); });

    connect(this->_system_setting->_word_of_command, &WordOfCommand::fromWordOfCommandToMainScreenSignals, [=]()
            {
            this->_system_setting->_word_of_command->hide();
            this->show(); });

    // �޸�ʱ��
    connect(ui->mytime_action, &QAction::triggered, [=]()
            {
            this->hide();
            this->_system_setting->_mytime->show(); });

    connect(this->_system_setting->_mytime, &MyTime::fromMyTimeToMianScreenSignals, [=]()
            {
            this->show();
            this->_system_setting->_mytime->hide(); });
}

void BoilerFeedPowderOnLineMonitoringSystem::StatusViewConnect()
{
    // ���ͷ��ͼ
    connect(ui->rod_type_wind_powder_diagram_action, &QAction::triggered, [=]()
            {
            this->hide();
            this->_status_view->_rod_type_wind_powder_diagram->show(); });
    // һ�η���Բͼ��ʾ
    connect(ui->tangential_circle_diagram_of_primary_wind_action, &QAction::triggered, [=]()
            {
            this->hide();
            this->_status_view->_tangential_circle_diagram_of_primary_wind->show(); });
    // ����ͼ
    connect(ui->trend_chart_action, &QAction::triggered, [=]()
            {
            this->hide();
            this->_status_view->_trend_chart->show(); });

    // ��ʷ����ͼ
    connect(ui->historical_trend_chart_action, &QAction::triggered, [=]()
            {
            this->hide();
            this->_status_view->_historical_trend_chart->show(); });
}

void BoilerFeedPowderOnLineMonitoringSystem::DataProcessingConnect()
{
    // ��������
    connect(ui->alarm_database_action, &QAction::triggered, [=]()
            {
            this->hide();
            this->_data_processing->_alarm_database->show(); });

    connect(this->_data_processing->_alarm_database, &AlarmDatabase::fromAlarmDatabaseToMainScreenSignals, [=]()
            {
            this->show();
            this->_data_processing->_alarm_database->hide(); });

    connect(ui->channel_database_action, &QAction::triggered, [=]()
            {
            this->hide();
            this->_data_processing->_channel_database->show(); });

    connect(this->_data_processing->_channel_database, &ChannelDatabase::fromChannelDatabaseToMainScreenSignals, [=]()
            {
            this->show();
            this->_data_processing->_channel_database->hide(); });
}

void BoilerFeedPowderOnLineMonitoringSystem::AssistConnect()
{
}
