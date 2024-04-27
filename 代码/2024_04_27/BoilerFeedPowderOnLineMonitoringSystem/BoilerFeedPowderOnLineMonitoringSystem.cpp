#include "BoilerFeedPowderOnLineMonitoringSystem.h"

BoilerFeedPowderOnLineMonitoringSystem::BoilerFeedPowderOnLineMonitoringSystem(QWidget* parent)
	: QMainWindow(parent)
	, ui(new Ui::BoilerFeedPowderOnLineMonitoringSystemClass())
	, _configure(new Configure(nullptr))
	, _welcome_screen(nullptr)
	, _give_an_alarm(nullptr)
	, _my_time(nullptr)
	, _verify_password(nullptr)
	, _spout(nullptr)
	, _word_of_command(nullptr)
	, _rod_type_wind_powder_diagram(nullptr)
	, _tangential_circle_diagram_of_primary_wind(nullptr)
	, _trend_chart(nullptr)
	, _historical_trend_chart(nullptr)
	, _channel_database(nullptr)
	, _alarm_database(nullptr)
{

	ui->setupUi(this);
	std::cout << "BoilerFeedPowderOnLineMonitoringSystem()" << std::endl;
	init();
}

BoilerFeedPowderOnLineMonitoringSystem::~BoilerFeedPowderOnLineMonitoringSystem()
{
	delete _configure;
	std::cout << "~BoilerFeedPowderOnLineMonitoringSystem()" << std::endl;
}

void BoilerFeedPowderOnLineMonitoringSystem::init()
{
	this->setWindowTitle("��¯�ͷ����߼��ϵͳ");
	initWelcomeScreen();   // ��ӭ����
	initSystemSetting();   // ϵͳ����
	initStatusView();      // ״̬�鿴
	initDataProcessing();  // ���ݴ���
	initAssist();          // ����
	initThread();          // ����������ͨ���̵߳õ�������
	startThread();         // �����߳�
}

void BoilerFeedPowderOnLineMonitoringSystem::initThread()
{
	qRegisterMetaType<Task>("Task");
	connect(&_my_thread, &MyThread::produceDataSignals, &_result_data, &ResultData::distributeData);
}

void BoilerFeedPowderOnLineMonitoringSystem::initSystemSetting()
{
	initGiveAnAlarm();    // ������
	initMyTime();         // �޶�ʱ��
	initSpout();          // ������
	initQuit();           // �˳��ź�
	initBackrestCanal();  // �޸Ŀ�����
	initWordOfCommand();  // �޸Ŀ���
}

void BoilerFeedPowderOnLineMonitoringSystem::initStatusView()
{
	initRodTypeWindPowderDiagram();
	initTangentialCircleDiagramOfPrimaryWind();
	initTrendChart();
	initHistoricalTrendChart();
}

void BoilerFeedPowderOnLineMonitoringSystem::initDataProcessing()
{
	initAlarmDatabase();
	initChannelDatabase();
}

void BoilerFeedPowderOnLineMonitoringSystem::initAssist()
{
}

void BoilerFeedPowderOnLineMonitoringSystem::closeEvent(QCloseEvent* event)
{
	_my_thread.quitThread();
	_my_thread.wait();

	// �û�ӭ�����˳�
	_welcome_screen->close();
	// �˳�����
	delete _give_an_alarm;
	delete _my_time;
	delete _verify_password;
	delete _spout;
	delete _backrest_canal;
	delete _word_of_command;
	delete _rod_type_wind_powder_diagram;
	delete _tangential_circle_diagram_of_primary_wind;
	delete _trend_chart;
	delete _historical_trend_chart;
	delete _channel_database;
	delete _alarm_database;
	this->close();
}

void BoilerFeedPowderOnLineMonitoringSystem::startThread()
{
	_my_thread.start();
}
// ��������
void BoilerFeedPowderOnLineMonitoringSystem::initAlarmDatabase()
{
	connect(ui->action_alarm_database, &QAction::triggered, [=]() {
		if(_alarm_database == nullptr)
			_alarm_database = new AlarmDatabase;
		this->hide();


		connect(_alarm_database, &AlarmDatabase::fromAlarmDatabaseToMainScreenSignals, [=]()
			{
				_alarm_database->close();
			});

		_alarm_database->show();
		connect(_alarm_database, &AlarmDatabase::alarmDatabaseCloseSignals, [=]() {
			this->show(); // ��������ʾ
			_alarm_database->hide();
			});
		});
}
// ͨ������
void BoilerFeedPowderOnLineMonitoringSystem::initChannelDatabase()
{
	connect(ui->action_channel_database, &QAction::triggered, [=]() {
		if(_channel_database == nullptr)
			_channel_database = new ChannelDatabase;
		this->hide();
		_channel_database->show();
		connect(_channel_database, &ChannelDatabase::fromChannelDatabaseToMainScreenSignals, [=]()
			{
				_channel_database->close();
			});
		connect(_channel_database, &ChannelDatabase::channelDatabaseCloseSignals, [=]() {
			this->show(); // ��������ʾ
			_channel_database->hide();
			});
		});
}
// ���ͷ��ͼ��ʾ
void BoilerFeedPowderOnLineMonitoringSystem::initRodTypeWindPowderDiagram()
{
	connect(ui->action_rod_type_wind_powder_diagram, &QAction::triggered, [=]() {
		if (nullptr == _rod_type_wind_powder_diagram)
			_rod_type_wind_powder_diagram = new RodTypeWindPowderDiagram(nullptr, &_result_data);
		
		emit _my_thread.saveCoefficientSignals(_configure->getAllCoefficient());  // ��ֹϵ���Ѿ�������
		
		this->hide();
		_rod_type_wind_powder_diagram->show();

		connect(_rod_type_wind_powder_diagram, &RodTypeWindPowderDiagram::rodTypeWindPowderDiagramCloseSignals, [=]() {
			this->show(); // ��������ʾ
			_rod_type_wind_powder_diagram->hide();
			});
		//�رռ�����
		});
}
// һ�η���Բͼ
void BoilerFeedPowderOnLineMonitoringSystem::initTangentialCircleDiagramOfPrimaryWind()
{
	connect(ui->action_tangential_circle_diagram_of_primary_wind, &QAction::triggered, [=]() {
		if(nullptr == _tangential_circle_diagram_of_primary_wind)
			_tangential_circle_diagram_of_primary_wind = new TangentialCircleDiagramOfPrimaryWind;
		
		this->hide();
		_tangential_circle_diagram_of_primary_wind->show();
		connect(_tangential_circle_diagram_of_primary_wind, &TangentialCircleDiagramOfPrimaryWind::tangentialCircleDiagramOfPrimaryWindCloseSignals, [=]() {
			this->show(); // ��������ʾ
			_tangential_circle_diagram_of_primary_wind->hide();
			});
		});
}
// ����ͼ
void BoilerFeedPowderOnLineMonitoringSystem::initTrendChart()
{
	connect(ui->action_trend_chart, &QAction::triggered, [=]() {
		if(nullptr == _trend_chart)
			_trend_chart = new TrendChart(nullptr, &_result_data);
		emit _my_thread.saveCoefficientSignals(_configure->getAllCoefficient());  // ��ֹϵ���Ѿ�������

		this->hide();
		_trend_chart->show();
		connect(_trend_chart, &TrendChart::trendChartCloseSignals, [=]() {
			this->show(); // ��������ʾ
			_trend_chart->hide();
			});
		});
}
// ��ʷͼ
void BoilerFeedPowderOnLineMonitoringSystem::initHistoricalTrendChart()
{
	connect(ui->action_historical_trend_chart, &QAction::triggered, [=]() {
		if(_historical_trend_chart == nullptr)
			_historical_trend_chart = new HistoricalTrendChart(nullptr, &_result_data);
		emit _my_thread.saveCoefficientSignals(_configure->getAllCoefficient());  // ��ֹϵ���Ѿ�������

		this->hide();
		_historical_trend_chart->show();
		connect(_historical_trend_chart, &HistoricalTrendChart::historicalTrendChartSignals, [=]() {
			this->show(); // ��������ʾ
			_historical_trend_chart->hide();
			});
		});
}
// �޶�������
void BoilerFeedPowderOnLineMonitoringSystem::initGiveAnAlarm()
{
	connect(ui->action_give_an_alarm, &QAction::triggered, [=]() {
		if (nullptr == _give_an_alarm)
			_give_an_alarm = new GiveAnAlarm(nullptr, _configure);

		_configure->setAlarmLimitRange(); // ���ͷ�Χ
		_configure->setAlarmLimitValue(); // ����ȷ��ֵ

		this->hide();
		_give_an_alarm->show();

		//����ʱΪ�˲鿴������
		connect(_give_an_alarm, &GiveAnAlarm::fromGiveAnAlarmToMainScreenSignals, [=]() {
			_give_an_alarm->close();
			});

		// ���ʱֻ��Ҫ�˳��Ϳ�����
		connect(_give_an_alarm, &GiveAnAlarm::giveAnAlarmCloseSignals, [=]() {
			_give_an_alarm->hide();  // ����ֻ��Ҫ���ؾͿ�����
			this->show(); // ��������ʾ
			});
		});
}
// �޶�ʱ��
void BoilerFeedPowderOnLineMonitoringSystem::initMyTime()
{
	connect(ui->action_mytime, &QAction::triggered, [=]() {
		if (nullptr == _my_time)
			_my_time = new MyTime();

		this->hide();
		_my_time->show();

		// ����������
		connect(_my_time, &MyTime::fromMyTimeToMianScreenSignals, [=]()
			{
				_my_time->close();
			});

		connect(_my_time, &MyTime::myTimeCloseSignals, [=]() {
			_my_time->hide();
			this->show(); // ��������ʾ
			});
		});
}
// �޶�������
void BoilerFeedPowderOnLineMonitoringSystem::initSpout()
{
	connect(ui->action_spout, &QAction::triggered, [=]() {
		if (nullptr == _verify_password)
		{
			_verify_password = new VerifyPassword(nullptr, _configure);
		}
		_configure->setPassword();
		_verify_password->setOption(1);
		_verify_password->show();
		connect(_verify_password, &VerifyPassword::verifyPasswordCloseSignals, [=]() {
			_verify_password->hide();
			this->show();
			});

		connect(_verify_password, &VerifyPassword::fromVerifyPasswordToSpoutSignalsIsTrue, [=]() {
			_verify_password->hide();
			this->hide();

			if (nullptr == _spout)
				_spout = new Spout(nullptr, _configure);
			_configure->setSpout();
			_spout->show();

			connect(_spout, &Spout::fromSpoutToMianScreenSignals, [=]() {
				_spout->close();
				});

			connect(_spout, &Spout::spoutCloseSignals, [=]() {
				_spout->hide();
				_verify_password->close();
				});
			});

		connect(_verify_password, &VerifyPassword::fromVerifyPasswordSignalsIsFalse, [=]() {
			_verify_password->close();
			});
		});
}

// �޸Ŀ����ܵ�ϵ��
void BoilerFeedPowderOnLineMonitoringSystem::initBackrestCanal()
{
	connect(ui->action_backrest_canal, &QAction::triggered, [=]() {
		if (nullptr == _verify_password)
		{
			_verify_password = new VerifyPassword(nullptr, _configure);
		}
		_configure->setPassword();
		_verify_password->setOption(2);

		_verify_password->show();

		connect(_verify_password, &VerifyPassword::verifyPasswordCloseSignals, [=]() {
			_verify_password->hide();
			this->show();
			});

		connect(_verify_password, &VerifyPassword::fromVerifyPasswordToBackrestCanalSignalsIsTrue, [=]() {
			_verify_password->hide();
			this->hide();

			if (nullptr == _backrest_canal)
				_backrest_canal = new BackrestCanal(nullptr, _configure);
			_configure->setBackrest();
			_backrest_canal->show();
			connect(_backrest_canal, &BackrestCanal::fromBackrestCanalToMainScreenSignals, [=]()
				{
					_backrest_canal->close();
				});

			connect(_backrest_canal, &BackrestCanal::backrestCanalCloseSignals, [=]() {
				_backrest_canal->hide();
				_verify_password->close();
				});
			});

		connect(_verify_password, &VerifyPassword::fromVerifyPasswordSignalsIsFalse, [=]() {
			_verify_password->close();
			});
		});
}
// �޸Ŀ���
void BoilerFeedPowderOnLineMonitoringSystem::initWordOfCommand()
{
	connect(ui->action_word_of_command, &QAction::triggered, [=]() {
		if (nullptr == _word_of_command)
			_word_of_command = new WordOfCommand(nullptr, _configure);
		_configure->setPassword();

		this->hide();
		_word_of_command->show();

		connect(_word_of_command, &WordOfCommand::fromWordOfCommandToMainScreenSignals, [=]() {
			_word_of_command->close();
			});
		connect(_word_of_command, &WordOfCommand::wordOfCommandCloseSignals, [=]() {
			this->show();
			_word_of_command->hide();
			});
		});
}
// ��ӭ����
void BoilerFeedPowderOnLineMonitoringSystem::initWelcomeScreen()
{
	if (_welcome_screen == nullptr)
		_welcome_screen = new WelcomeScreen(nullptr);

	connect(_welcome_screen, &WelcomeScreen::welcomeScreenCloseSignals, [=]() {
		_my_thread.quitThread();
		_my_thread.wait();
		_welcome_screen = nullptr;
		});
	//�����Ӵ������ԣ��رռ�����
	_welcome_screen->setAttribute(Qt::WA_DeleteOnClose);
	_welcome_screen->show();

	// ��ӭ���浽 ������
	connect(_welcome_screen, &WelcomeScreen::fromWelToMianScreenSignals, [=]() {
		this->show();
		_welcome_screen->hide();
		});
}
// �˳�����
void BoilerFeedPowderOnLineMonitoringSystem::initQuit()
{
	connect(ui->action_quit, &QAction::triggered, [=]()
		{
			this->close();
		});
}