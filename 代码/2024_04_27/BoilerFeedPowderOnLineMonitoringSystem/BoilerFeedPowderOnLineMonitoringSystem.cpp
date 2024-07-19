#include "BoilerFeedPowderOnLineMonitoringSystem.h"
//实例化类中的各个成员的时候, 每个成员的父类这里设置为nullptr
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
	// 删除配置文件
	delete _configure;
	std::cout << "~BoilerFeedPowderOnLineMonitoringSystem()" << std::endl;
}

void BoilerFeedPowderOnLineMonitoringSystem::init()
{
	this->setWindowTitle("锅炉送粉在线监测系统");
	// 实例化我们的各个功能
	// 系统设置
	_give_an_alarm = new GiveAnAlarm(nullptr, _configure);
	_word_of_command = new WordOfCommand(nullptr, _configure);
	_my_time = new MyTime();
	_verify_password = new VerifyPassword(nullptr, _configure);
	_spout = new Spout(nullptr, _configure);
	_backrest_canal = new BackrestCanal(nullptr, _configure);

	// 四个图像,这里只需要县开辟两个
	//_rod_type_wind_powder_diagram = new RodTypeWindPowderDiagram(nullptr, &_result_data);
	//_tangential_circle_diagram_of_primary_wind = new TangentialCircleDiagramOfPrimaryWind;
	_trend_chart = new TrendChart(nullptr, &_result_data);
	_historical_trend_chart = new HistoricalTrendChart(nullptr, &_result_data);
	// 报警数据和通道数据
	_alarm_database = new AlarmDatabase(nullptr, &_result_data);
	_channel_database = new ChannelDatabase(nullptr, &_result_data);

	// 将系数发给我们工作的线程
	emit _my_thread.saveCoefficientSignals(_configure->getAllCoefficient());  // 防止系数已经更新了

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
	qRegisterMetaType<std::vector<struct Result>>("std::vector<struct Result>");
	// 这里将解析后的数据发送到_result_data中
	connect(&_my_thread, &MyThread::produceAllDataSignals, &_result_data, &ResultData::distributeAllData);
	// 报警数据
	qRegisterMetaType<std::vector<struct AlertData>>("std::vector<struct AlertData>");
	connect(&_my_thread, &MyThread::produceAlarmDataSignals, &_result_data, &ResultData::distributeAlarmData);

	// 通道数据
	qRegisterMetaType<std::vector<struct ChannelData>>("std::vector<struct ChannelData>");
	connect(&_my_thread, &MyThread::produceChannelDataSignals, &_result_data, &ResultData::distributeChannelData);
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
	// 退出子线程
	_my_thread.quitThread();
	_my_thread.wait();

	// 让欢迎窗口退出
	if (_welcome_screen)
		_welcome_screen->close();
	// 退出窗口时,避免资源泄露,释放掉资源
	if (_give_an_alarm)
		delete _give_an_alarm;
	if (_my_time)
		delete _my_time;
	if (_verify_password)
		delete _verify_password;
	if (_spout)
		delete _spout;
	if (_backrest_canal)
		delete _backrest_canal;
	if (_word_of_command)
		delete _word_of_command;
	if (_rod_type_wind_powder_diagram)
		delete _rod_type_wind_powder_diagram;
	if (_tangential_circle_diagram_of_primary_wind)
		delete _tangential_circle_diagram_of_primary_wind;
	if (_trend_chart)
		delete _trend_chart;
	if (_historical_trend_chart)
		delete _historical_trend_chart;
	if (_channel_database)
		delete _channel_database;
	if (_alarm_database)
		delete _alarm_database;
	// 关闭窗口
	this->close();
}

void BoilerFeedPowderOnLineMonitoringSystem::startThread()
{
	// 启动子线程
	_my_thread.start();
}

// 报警数据
void BoilerFeedPowderOnLineMonitoringSystem::initAlarmDatabase()
{
	connect(ui->action_alarm_database, &QAction::triggered, [=]() {
		if (_alarm_database == nullptr)  // 实例化资源
			_alarm_database = new AlarmDatabase;

		// 信号与槽函数
		connect(_alarm_database, &AlarmDatabase::fromAlarmDatabaseToMainScreenSignals, [=]()
			{
				_alarm_database->close();
			});
		connect(_alarm_database, &AlarmDatabase::alarmDatabaseCloseSignals, [=]() {
			this->show(); // 主窗口显示
			_alarm_database->hide();
			});

		this->hide();  // 隐藏主窗口
		_alarm_database->show();// 显示报警数据窗口
		});
}
// 通道数据
void BoilerFeedPowderOnLineMonitoringSystem::initChannelDatabase()
{
	connect(ui->action_channel_database, &QAction::triggered, [=]() {
		if (nullptr == _channel_database) // 实例化资源
			_channel_database = new ChannelDatabase;

		// 信号和槽函数
		connect(_channel_database, &ChannelDatabase::fromChannelDatabaseToMainScreenSignals, [=]()
			{
				_channel_database->close();
			});
		connect(_channel_database, &ChannelDatabase::channelDatabaseCloseSignals, [=]() {
			this->show(); // 主窗口显示
			_channel_database->hide();
			});

		this->hide();// 隐藏主窗口
		_channel_database->show();// 显示报警数据窗口
		});
}
// 棒型风粉图显示
void BoilerFeedPowderOnLineMonitoringSystem::initRodTypeWindPowderDiagram()
{
	connect(ui->action_rod_type_wind_powder_diagram, &QAction::triggered, [=]() {
		if (nullptr == _rod_type_wind_powder_diagram) // 实例化资源
			_rod_type_wind_powder_diagram = new RodTypeWindPowderDiagram(nullptr, &_result_data);

		// 更新参数, 避免前面修改了报警限
		emit _my_thread.saveCoefficientSignals(_configure->getAllCoefficient());  // 防止系数已经更新了
		// 信号和槽, 窗口退出后,怎么做
		connect(_rod_type_wind_powder_diagram, &RodTypeWindPowderDiagram::rodTypeWindPowderDiagramCloseSignals, [=]() {
			this->show(); // 主窗口显示
			_rod_type_wind_powder_diagram->hide();
			});

		this->hide();// 关闭主窗口
		_rod_type_wind_powder_diagram->show(); // 显示该窗口
		});
}

// 一次风切圆图
void BoilerFeedPowderOnLineMonitoringSystem::initTangentialCircleDiagramOfPrimaryWind()
{
	connect(ui->action_tangential_circle_diagram_of_primary_wind, &QAction::triggered, [=]() {
		if (nullptr == _tangential_circle_diagram_of_primary_wind) // 实例化资源
			_tangential_circle_diagram_of_primary_wind = new TangentialCircleDiagramOfPrimaryWind;
		// 更新参数
		emit _my_thread.saveCoefficientSignals(_configure->getAllCoefficient());  // 防止系数已经更新了

		connect(_tangential_circle_diagram_of_primary_wind, &TangentialCircleDiagramOfPrimaryWind::tangentialCircleDiagramOfPrimaryWindCloseSignals, [=]() {
			this->show(); // 主窗口显示
			_tangential_circle_diagram_of_primary_wind->hide();
			});

		this->hide();// 关闭主窗口
		_tangential_circle_diagram_of_primary_wind->show();// 显示该窗口
		});
}

// 趋势图
void BoilerFeedPowderOnLineMonitoringSystem::initTrendChart()
{
	connect(ui->action_trend_chart, &QAction::triggered, [=]() {
		if (nullptr == _trend_chart)
			_trend_chart = new TrendChart(nullptr, &_result_data);
		// 更新参数
		emit _my_thread.saveCoefficientSignals(_configure->getAllCoefficient());  // 防止系数已经更新了

		connect(_trend_chart, &TrendChart::trendChartCloseSignals, [=]() {
			this->show(); // 主窗口显示
			_trend_chart->hide();
			});
		this->hide();// 关闭主窗口
		_trend_chart->show();// 显示该窗口
		});
}

// 历史图
void BoilerFeedPowderOnLineMonitoringSystem::initHistoricalTrendChart()
{
	connect(ui->action_historical_trend_chart, &QAction::triggered, [=]() {
		if (nullptr == _historical_trend_chart) // 实例化资源
			_historical_trend_chart = new HistoricalTrendChart(nullptr, &_result_data);
		emit _my_thread.saveCoefficientSignals(_configure->getAllCoefficient());  // 防止系数已经更新了

		connect(_historical_trend_chart, &HistoricalTrendChart::historicalTrendChartSignals, [=]() {
			this->show(); // 主窗口显示
			_historical_trend_chart->hide();
			});

		this->hide();
		_historical_trend_chart->show();
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
			// 这里可以更新下参数,如果我们已经修改了呢
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
			_verify_password = new VerifyPassword(nullptr, _configure);

		_configure->setPassword();  // 设置密码
		_verify_password->setOption(1);
		_verify_password->show();

		connect(_verify_password, &VerifyPassword::verifyPasswordCloseSignals, [=]() {
			//直接关闭密码验证界面
			_verify_password->hide();
			this->show();
			});

		connect(_verify_password, &VerifyPassword::fromVerifyPasswordToSpoutSignalsIsTrue, [=]() {
			// 密码验证成功
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
			_verify_password = new VerifyPassword(nullptr, _configure);

		// 设置密码
		_configure->setPassword();
		_verify_password->setOption(2);
		// 密码验证窗口显示
		_verify_password->show();

		connect(_verify_password, &VerifyPassword::verifyPasswordCloseSignals, [=]() {
			_verify_password->hide();
			this->show();
			});

		connect(_verify_password, &VerifyPassword::fromVerifyPasswordToBackrestCanalSignalsIsTrue, [=]() {
			// 密码验证成功
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
	if (nullptr == _welcome_screen)
		_welcome_screen = new WelcomeScreen(nullptr);

	// welcomeScreenCloseSignals 是自定义的信号
	connect(_welcome_screen, &WelcomeScreen::welcomeScreenCloseSignals, [=]() {
		// 关闭另外一个线程
		_my_thread.quitThread();
		_my_thread.wait();
		_welcome_screen = nullptr;

		// 一般而言,我们欢迎界面只出现一次,一旦我们选择叉掉这个界面,可以认为是整个程序都要退出
		this->close();
		});

	//设置子窗体属性：关闭即销毁
	_welcome_screen->setAttribute(Qt::WA_DeleteOnClose);

	// 显示欢迎界面
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