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
	this->setWindowTitle("锅炉送粉在线监测系统");
	initWelcomeScreen();   // 欢迎窗口
	initSystemSetting();   // 系统设置
	initStatusView();      // 状态查看
	initDataProcessing();  // 数据处理
	initAssist();          // 帮助
	initThread();          // 设置下我们通过线程得到的数据
	startThread();         // 启动线程
}

void BoilerFeedPowderOnLineMonitoringSystem::initThread()
{
	qRegisterMetaType<Task>("Task");
	connect(&_my_thread, &MyThread::produceDataSignals, &_result_data, &ResultData::distributeData);
}

void BoilerFeedPowderOnLineMonitoringSystem::initSystemSetting()
{
	initGiveAnAlarm();    // 报警限
	initMyTime();         // 修订时间
	initSpout();          // 喷口面积
	initQuit();           // 退出信号
	initBackrestCanal();  // 修改靠背管
	initWordOfCommand();  // 修改口令
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

	// 让欢迎窗口退出
	_welcome_screen->close();
	// 退出窗口
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
// 报警数据
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
			this->show(); // 主窗口显示
			_alarm_database->hide();
			});
		});
}
// 通道数据
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
			this->show(); // 主窗口显示
			_channel_database->hide();
			});
		});
}
// 棒型风粉图显示
void BoilerFeedPowderOnLineMonitoringSystem::initRodTypeWindPowderDiagram()
{
	connect(ui->action_rod_type_wind_powder_diagram, &QAction::triggered, [=]() {
		if (nullptr == _rod_type_wind_powder_diagram)
			_rod_type_wind_powder_diagram = new RodTypeWindPowderDiagram(nullptr, &_result_data);
		
		emit _my_thread.saveCoefficientSignals(_configure->getAllCoefficient());  // 防止系数已经更新了
		
		this->hide();
		_rod_type_wind_powder_diagram->show();

		connect(_rod_type_wind_powder_diagram, &RodTypeWindPowderDiagram::rodTypeWindPowderDiagramCloseSignals, [=]() {
			this->show(); // 主窗口显示
			_rod_type_wind_powder_diagram->hide();
			});
		//关闭即销毁
		});
}
// 一次风切圆图
void BoilerFeedPowderOnLineMonitoringSystem::initTangentialCircleDiagramOfPrimaryWind()
{
	connect(ui->action_tangential_circle_diagram_of_primary_wind, &QAction::triggered, [=]() {
		if(nullptr == _tangential_circle_diagram_of_primary_wind)
			_tangential_circle_diagram_of_primary_wind = new TangentialCircleDiagramOfPrimaryWind;
		
		this->hide();
		_tangential_circle_diagram_of_primary_wind->show();
		connect(_tangential_circle_diagram_of_primary_wind, &TangentialCircleDiagramOfPrimaryWind::tangentialCircleDiagramOfPrimaryWindCloseSignals, [=]() {
			this->show(); // 主窗口显示
			_tangential_circle_diagram_of_primary_wind->hide();
			});
		});
}
// 趋势图
void BoilerFeedPowderOnLineMonitoringSystem::initTrendChart()
{
	connect(ui->action_trend_chart, &QAction::triggered, [=]() {
		if(nullptr == _trend_chart)
			_trend_chart = new TrendChart(nullptr, &_result_data);
		emit _my_thread.saveCoefficientSignals(_configure->getAllCoefficient());  // 防止系数已经更新了

		this->hide();
		_trend_chart->show();
		connect(_trend_chart, &TrendChart::trendChartCloseSignals, [=]() {
			this->show(); // 主窗口显示
			_trend_chart->hide();
			});
		});
}
// 历史图
void BoilerFeedPowderOnLineMonitoringSystem::initHistoricalTrendChart()
{
	connect(ui->action_historical_trend_chart, &QAction::triggered, [=]() {
		if(_historical_trend_chart == nullptr)
			_historical_trend_chart = new HistoricalTrendChart(nullptr, &_result_data);
		emit _my_thread.saveCoefficientSignals(_configure->getAllCoefficient());  // 防止系数已经更新了

		this->hide();
		_historical_trend_chart->show();
		connect(_historical_trend_chart, &HistoricalTrendChart::historicalTrendChartSignals, [=]() {
			this->show(); // 主窗口显示
			_historical_trend_chart->hide();
			});
		});
}
// 修订报警限
void BoilerFeedPowderOnLineMonitoringSystem::initGiveAnAlarm()
{
	connect(ui->action_give_an_alarm, &QAction::triggered, [=]() {
		if (nullptr == _give_an_alarm)
			_give_an_alarm = new GiveAnAlarm(nullptr, _configure);

		_configure->setAlarmLimitRange(); // 发送范围
		_configure->setAlarmLimitValue(); // 发送确定值

		this->hide();
		_give_an_alarm->show();

		//仅仅时为了查看报警限
		connect(_give_an_alarm, &GiveAnAlarm::fromGiveAnAlarmToMainScreenSignals, [=]() {
			_give_an_alarm->close();
			});

		// 叉掉时只需要退出就可以了
		connect(_give_an_alarm, &GiveAnAlarm::giveAnAlarmCloseSignals, [=]() {
			_give_an_alarm->hide();  // 这里只需要隐藏就可以了
			this->show(); // 主窗口显示
			});
		});
}
// 修订时间
void BoilerFeedPowderOnLineMonitoringSystem::initMyTime()
{
	connect(ui->action_mytime, &QAction::triggered, [=]() {
		if (nullptr == _my_time)
			_my_time = new MyTime();

		this->hide();
		_my_time->show();

		// 返回主窗口
		connect(_my_time, &MyTime::fromMyTimeToMianScreenSignals, [=]()
			{
				_my_time->close();
			});

		connect(_my_time, &MyTime::myTimeCloseSignals, [=]() {
			_my_time->hide();
			this->show(); // 主窗口显示
			});
		});
}
// 修订喷口面积
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

// 修改靠背管的系数
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
// 修改口令
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
// 欢迎界面
void BoilerFeedPowderOnLineMonitoringSystem::initWelcomeScreen()
{
	if (_welcome_screen == nullptr)
		_welcome_screen = new WelcomeScreen(nullptr);

	connect(_welcome_screen, &WelcomeScreen::welcomeScreenCloseSignals, [=]() {
		_my_thread.quitThread();
		_my_thread.wait();
		_welcome_screen = nullptr;
		});
	//设置子窗体属性：关闭即销毁
	_welcome_screen->setAttribute(Qt::WA_DeleteOnClose);
	_welcome_screen->show();

	// 欢迎界面到 主界面
	connect(_welcome_screen, &WelcomeScreen::fromWelToMianScreenSignals, [=]() {
		this->show();
		_welcome_screen->hide();
		});
}
// 退出程序
void BoilerFeedPowderOnLineMonitoringSystem::initQuit()
{
	connect(ui->action_quit, &QAction::triggered, [=]()
		{
			this->close();
		});
}