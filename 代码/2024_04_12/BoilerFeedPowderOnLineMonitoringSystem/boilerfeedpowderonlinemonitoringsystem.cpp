#include "boilerfeedpowderonlinemonitoringsystem.h"

BoilerFeedPowderOnLineMonitoringSystem::BoilerFeedPowderOnLineMonitoringSystem(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BoilerFeedPowderOnLineMonitoringSystemClass())
    , _configure(new Configure(nullptr))
    , _welcomeScreen(new WelcomeScreen(nullptr))
    , _verify_password(new VerifyPassword(nullptr))
    , _system_setting(new SystemSetting(nullptr, _configure))
    , _status_view(new StatusView(nullptr))
    , _data_processing(new DataProcessing(nullptr))
{
    std::cout << "BoilerFeedPowderOnLineMonitoringSystem()" << std::endl;
    ui->setupUi(this);
    this->init();       // 处理写杂事,例如图像的标题等
    this->myConnect();  // 链接信号与槽
    _myThread.start();  // 启动线程

}
void BoilerFeedPowderOnLineMonitoringSystem::init()
{
    _welcomeScreen->show();
    this->setWindowTitle(QString("sss"));
}

void BoilerFeedPowderOnLineMonitoringSystem::myConnect()
{
    SystemSettingConnect();
    StatusViewConnect();
    DataProcessingConnect();
    AssistConnect();
    // 主线程发出信号,生产线程处理后结束子线程
    connect(this, &BoilerFeedPowderOnLineMonitoringSystem::stopThread, &_myThread, &MyThread::stopProcessing);
    // 主线程退出, 先发一个信号,重写我们的退出函数
    connect(this, &BoilerFeedPowderOnLineMonitoringSystem::quitSignals, this, &BoilerFeedPowderOnLineMonitoringSystem::quit);
    // 欢迎界面到 主界面
    connect(_welcomeScreen, &WelcomeScreen::fromWelToMianScreenSignals, this, &BoilerFeedPowderOnLineMonitoringSystem::fromWelToMianScreen);
    qRegisterMetaType<Task>("Task");
    connect(&_myThread, &MyThread::produceSignals, this, &BoilerFeedPowderOnLineMonitoringSystem::processData);
}
void BoilerFeedPowderOnLineMonitoringSystem::quit()
{
    this->hide();
    this->close();
}

void BoilerFeedPowderOnLineMonitoringSystem::closeEvent(QCloseEvent* event)
{

    emit stopThread();
    _myThread.wait();
    this->closeEvent(event);
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
    // 退出
    connect(ui->quit_action, &QAction::triggered, [=]()
            { emit quitSignals(); });

    // 设定报警限
    connect(ui->give_an_alarm_action, &QAction::triggered, [=]()
            {
            this->hide();
            _configure->myEmit(1);
            _configure->myEmit(2);
            this->_system_setting->_give_an_alarm->show(); });
    // 只是查看报警界限
    connect(this->_system_setting->_give_an_alarm, &GiveAnAlarm::fromGiveAnAlarmToMainScreenSignals, [=]()
            {
           
            qDebug() << "";
            this->_system_setting->_give_an_alarm->hide();
            this->show(); });

    // 修改报警界限
    connect(this->_system_setting->_give_an_alarm, &GiveAnAlarm::fromGiveAnAlarmToMainScreenToSaveSignals, [=](std::string s1, std::string s2, std::string s3, std::string s4, std::string s5, std::string s6)
        {

            _configure->_info_map["lower_wind_speed_limit"] = s1;
            _configure->_info_map["upper_wind_speed_limit"] = s2;
            _configure->_info_map["lower_limit_of_pulverized_coal_concentration"] = s3;
            _configure->_info_map["upper_limit_of_pulverized_coal_concentration"] = s4;
            _configure->_info_map["lower_temperature_limit"] = s5;
            _configure->_info_map["upper_temperature_limit"] = s6;
            this->_system_setting->_give_an_alarm->hide();
            this->show(); 
        });
    



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


BoilerFeedPowderOnLineMonitoringSystem::~BoilerFeedPowderOnLineMonitoringSystem()
{
    std::cout << "~BoilerFeedPowderOnLineMonitoringSystem()" << std::endl;
    delete _configure;
    delete _welcomeScreen;
    delete _verify_password;
    delete _system_setting;
    delete _status_view;
    delete _data_processing;

    delete ui;
}