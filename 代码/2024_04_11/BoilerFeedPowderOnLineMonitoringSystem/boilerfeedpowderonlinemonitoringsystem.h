#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_boilerfeedpowderonlinemonitoringsystem.h"
#include "welcomescreen.h"
#include "producerthread.h"
#include "configurethread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class BoilerFeedPowderOnLineMonitoringSystemClass; };
QT_END_NAMESPACE

class BoilerFeedPowderOnLineMonitoringSystem : public QMainWindow
{
    Q_OBJECT

public:
    BoilerFeedPowderOnLineMonitoringSystem(QWidget *parent = nullptr);
    ~BoilerFeedPowderOnLineMonitoringSystem();
protected slots:
    void processData(Task);
    void processConfigure(std::unordered_map<std::string, std::string>);
private:
    Ui::BoilerFeedPowderOnLineMonitoringSystemClass *ui;
    WelcomeScreen* _welcomeScreen;
    ProducerThread _producerthread;   //  生产线程
    ConfigureThread _configurethread; //  配置线程
};
