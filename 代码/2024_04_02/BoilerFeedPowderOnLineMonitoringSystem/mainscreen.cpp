#include "mainscreen.h"
#include <qdebug.h>
MainScreen::MainScreen(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainScreenClass())
	, _verify_password(new VerifyPassword(nullptr))
	, _system_setting(new SystemSetting(this))
    , _status_view(new StatusView(this))
    ,_data_processing(new DataProcessing(this))
{
    
	ui->setupUi(this);
	qDebug() << "MainScreen()";
	this->setWindowTitle("锅炉送粉在线监测系统");

	SystemSettingConnect();
	StatusViewConnect();
	DataProcessingConnect();
	AssistConnect();
}

MainScreen::~MainScreen()
{
	qDebug() << "~MainScreen()";
	delete _verify_password;
	delete ui;
}

void MainScreen::SystemSettingConnect()
{
	// 退出
	connect(ui->quit_action, &QAction::triggered, [=]()
        {
		    emit quitSignals();
		});

	// 设定报警限
	connect(ui->give_an_alarm_action, &QAction::triggered, [=]()
        {
		    this->hide();
		    this->_system_setting->_give_an_alarm->show();
		});
    connect(this->_system_setting->_give_an_alarm, &GiveAnAlarm::fromGiveAnAlarmToMainScreenSignals, [=]()
        {
            // 这里少一个如果控件被关闭,我们是否需要做一些动作
            qDebug() << "报警界面已经取消";
            this->_system_setting->_give_an_alarm->hide();
            this->show();
        });


	 // 靠背管系数修正
	connect(ui->backrest_canal_action, &QAction::triggered, [=]()
        {
			this->_verify_password->show();

			connect(this->_verify_password, &VerifyPassword::fromVerifyPasswordSignalsIsTrue, [=]() {
				    qDebug() << "验证界面已经可以了";
				    this->hide();
				    this->_verify_password->hide();
				    this->_system_setting->_backrest_canal->show();
				});
			connect(this->_verify_password, &VerifyPassword::fromVerifyPasswordSignalsIsFalse, [=]() {
				    qDebug() << "验证界面已经取消了";
				    this->_verify_password->hide();
				}); 
		});

    connect(this->_system_setting->_backrest_canal, &BackrestCanal::fromBackrestCanalToMainScreenSignals, [=]()
        {
            qDebug() << "设定系数修正的界面已经取消";
            this->_system_setting->_backrest_canal->hide();
            this->show(); 
        });

    //  设定喷口面积
    connect(ui->spout_action, &QAction::triggered, [=]()
        {
            this->_verify_password->show();
            connect(this->_verify_password, &VerifyPassword::fromVerifyPasswordSignalsIsTrue, [=]() {
                    qDebug() << "验证界面已经可以了";
                    this->hide();
                    this->_verify_password->hide();
                    this->_system_setting->_spout->show();
                });
            connect(this->_verify_password, &VerifyPassword::fromVerifyPasswordSignalsIsFalse, [=]() {
                    qDebug() << "验证界面已经取消了";
                    this->_verify_password->hide();
                });
        });
    connect(this->_system_setting->_spout, &Spout::fromSpoutToMianScreenSignals, [=]()
        {
            qDebug() << "设定喷口面积界面已经取消";
            this->_system_setting->_spout->hide();
            this->show(); 
        });

    // 修改口令
    connect(ui->word_of_command_action, &QAction::triggered, [=]()
        {
            this->hide();
            this->_system_setting->_word_of_command->show();
        });

    connect(this->_system_setting->_word_of_command, &WordOfCommand::fromWordOfCommandToMainScreenSignals, [=]()
        {
            this->_system_setting->_word_of_command->hide();
            this->show(); 
        });

    // 修改时间
    connect(ui->mytime_action, &QAction::triggered, [=]()
        {
            this->hide();
            this->_system_setting->_mytime->show(); 
        });

    connect(this->_system_setting->_mytime, &MyTime::fromMyTimeToMianScreenSignals, [=]()
        {
            this->show();
            this->_system_setting->_mytime->hide(); 
        });

}

void MainScreen::StatusViewConnect()
{
    // 棒型风粉图
    connect(ui->rod_type_wind_powder_diagram_action, &QAction::triggered, [=]()
        {
            this->hide();
            this->_status_view->_rod_type_wind_powder_diagram->show(); 
        });
    // 一次风切圆图显示
    connect(ui->tangential_circle_diagram_of_primary_wind_action, &QAction::triggered, [=]()
        {
            this->hide();
            this->_status_view->_tangential_circle_diagram_of_primary_wind->show();
        });
    // 趋势图
    connect(ui->trend_chart_action, &QAction::triggered, [=]()
        {
            this->hide();
            this->_status_view->_trend_chart->show(); 
        });

    // 历史趋势图
    connect(ui->historical_trend_chart_action, &QAction::triggered, [=]()
        {
            this->hide();
            this->_status_view->_historical_trend_chart->show(); 
        });
}

void MainScreen::DataProcessingConnect()
{
    // 报警数据
    connect(ui->alarm_database_action, &QAction::triggered, [=]()
        {
            this->hide();
            this->_data_processing->_alarm_database->show(); 
        });

    connect(this->_data_processing->_alarm_database, &AlarmDatabase::fromAlarmDatabaseToMainScreenSignals, [=]() 
        {
            this->show();
            this->_data_processing->_alarm_database->hide();
        });


    connect(ui->channel_database_action, &QAction::triggered, [=]()
        {
            this->hide();
            this->_data_processing->_channel_database->show(); 
        });

    connect(this->_data_processing->_channel_database, &ChannelDatabase::fromChannelDatabaseToMainScreenSignals, [=]()
        {
            this->show();
            this->_data_processing->_channel_database->hide();
        });

}

void MainScreen::AssistConnect()
{
}
