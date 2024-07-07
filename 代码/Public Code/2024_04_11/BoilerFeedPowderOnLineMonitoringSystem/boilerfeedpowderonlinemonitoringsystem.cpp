#include "boilerfeedpowderonlinemonitoringsystem.h"
BoilerFeedPowderOnLineMonitoringSystem::BoilerFeedPowderOnLineMonitoringSystem(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BoilerFeedPowderOnLineMonitoringSystemClass())
    , _welcomeScreen(new WelcomeScreen(nullptr))
{
    ui->setupUi(this);
    std::cout << "BoilerFeedPowderOnLineMonitoringSystem()" << std::endl;
    _welcomeScreen->show();

    qRegisterMetaType<Task>("Task");
    connect(&_producerthread, &ProducerThread::produceSignals, this, &BoilerFeedPowderOnLineMonitoringSystem::processData);
    _producerthread.start();
    qRegisterMetaType<std::unordered_map<std::string, std::string>>("std::unordered_map<std::string, std::string>");
    connect(&_configurethread, &ConfigureThread::configureIsReady, this, &BoilerFeedPowderOnLineMonitoringSystem::processConfigure);
    _configurethread.start();
}

BoilerFeedPowderOnLineMonitoringSystem::~BoilerFeedPowderOnLineMonitoringSystem()
{
    delete _welcomeScreen;
    std::cout << "~BoilerFeedPowderOnLineMonitoringSystem()" << std::endl;
    delete ui;
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
    //task.show();
}
