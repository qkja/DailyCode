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
	this->setWindowTitle("��¯�ͷ����߼��ϵͳ");

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
	// �˳�
	connect(ui->quit_action, &QAction::triggered, [=]()
        {
		    emit quitSignals();
		});

	// �趨������
	connect(ui->give_an_alarm_action, &QAction::triggered, [=]()
        {
		    this->hide();
		    this->_system_setting->_give_an_alarm->show();
		});
    connect(this->_system_setting->_give_an_alarm, &GiveAnAlarm::fromGiveAnAlarmToMainScreenSignals, [=]()
        {
            // ������һ������ؼ����ر�,�����Ƿ���Ҫ��һЩ����
            qDebug() << "���������Ѿ�ȡ��";
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
				}); 
		});

    connect(this->_system_setting->_backrest_canal, &BackrestCanal::fromBackrestCanalToMainScreenSignals, [=]()
        {
            qDebug() << "�趨ϵ�������Ľ����Ѿ�ȡ��";
            this->_system_setting->_backrest_canal->hide();
            this->show(); 
        });

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
                });
        });
    connect(this->_system_setting->_spout, &Spout::fromSpoutToMianScreenSignals, [=]()
        {
            qDebug() << "�趨�����������Ѿ�ȡ��";
            this->_system_setting->_spout->hide();
            this->show(); 
        });

    // �޸Ŀ���
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

    // �޸�ʱ��
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
    // ���ͷ��ͼ
    connect(ui->rod_type_wind_powder_diagram_action, &QAction::triggered, [=]()
        {
            this->hide();
            this->_status_view->_rod_type_wind_powder_diagram->show(); 
        });
    // һ�η���Բͼ��ʾ
    connect(ui->tangential_circle_diagram_of_primary_wind_action, &QAction::triggered, [=]()
        {
            this->hide();
            this->_status_view->_tangential_circle_diagram_of_primary_wind->show();
        });
    // ����ͼ
    connect(ui->trend_chart_action, &QAction::triggered, [=]()
        {
            this->hide();
            this->_status_view->_trend_chart->show(); 
        });

    // ��ʷ����ͼ
    connect(ui->historical_trend_chart_action, &QAction::triggered, [=]()
        {
            this->hide();
            this->_status_view->_historical_trend_chart->show(); 
        });
}

void MainScreen::DataProcessingConnect()
{
    // ��������
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
