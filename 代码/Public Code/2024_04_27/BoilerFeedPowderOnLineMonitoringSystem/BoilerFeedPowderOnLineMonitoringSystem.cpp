#include "BoilerFeedPowderOnLineMonitoringSystem.h"
//ʵ�������еĸ�����Ա��ʱ��, ÿ����Ա�ĸ�����������Ϊnullptr
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
	// ɾ�������ļ�
	delete _configure;
	std::cout << "~BoilerFeedPowderOnLineMonitoringSystem()" << std::endl;
}

void BoilerFeedPowderOnLineMonitoringSystem::init()
{
	this->setWindowTitle("��¯�ͷ����߼��ϵͳ");
	// ʵ�������ǵĸ�������
	// ϵͳ����
	_give_an_alarm = new GiveAnAlarm(nullptr, _configure);
	_word_of_command = new WordOfCommand(nullptr, _configure);
	_my_time = new MyTime();
	_verify_password = new VerifyPassword(nullptr, _configure);
	_spout = new Spout(nullptr, _configure);
	_backrest_canal = new BackrestCanal(nullptr, _configure);

	// �ĸ�ͼ��,����ֻ��Ҫ�ؿ�������
	//_rod_type_wind_powder_diagram = new RodTypeWindPowderDiagram(nullptr, &_result_data);
	//_tangential_circle_diagram_of_primary_wind = new TangentialCircleDiagramOfPrimaryWind;
	_trend_chart = new TrendChart(nullptr, &_result_data);
	_historical_trend_chart = new HistoricalTrendChart(nullptr, &_result_data);
	// �������ݺ�ͨ������
	_alarm_database = new AlarmDatabase(nullptr, &_result_data);
	_channel_database = new ChannelDatabase(nullptr, &_result_data);

	// ��ϵ���������ǹ������߳�
	emit _my_thread.saveCoefficientSignals(_configure->getAllCoefficient());  // ��ֹϵ���Ѿ�������

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
	qRegisterMetaType<std::vector<struct Result>>("std::vector<struct Result>");
	// ���ｫ����������ݷ��͵�_result_data��
	connect(&_my_thread, &MyThread::produceAllDataSignals, &_result_data, &ResultData::distributeAllData);
	// ��������
	qRegisterMetaType<std::vector<struct AlertData>>("std::vector<struct AlertData>");
	connect(&_my_thread, &MyThread::produceAlarmDataSignals, &_result_data, &ResultData::distributeAlarmData);

	// ͨ������
	qRegisterMetaType<std::vector<struct ChannelData>>("std::vector<struct ChannelData>");
	connect(&_my_thread, &MyThread::produceChannelDataSignals, &_result_data, &ResultData::distributeChannelData);
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
	// �˳����߳�
	_my_thread.quitThread();
	_my_thread.wait();

	// �û�ӭ�����˳�
	if (_welcome_screen)
		_welcome_screen->close();
	// �˳�����ʱ,������Դй¶,�ͷŵ���Դ
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
	// �رմ���
	this->close();
}

void BoilerFeedPowderOnLineMonitoringSystem::startThread()
{
	// �������߳�
	_my_thread.start();
}

// ��������
void BoilerFeedPowderOnLineMonitoringSystem::initAlarmDatabase()
{
	connect(ui->action_alarm_database, &QAction::triggered, [=]() {
		if (_alarm_database == nullptr)  // ʵ������Դ
			_alarm_database = new AlarmDatabase;

		// �ź���ۺ���
		connect(_alarm_database, &AlarmDatabase::fromAlarmDatabaseToMainScreenSignals, [=]()
			{
				_alarm_database->close();
			});
		connect(_alarm_database, &AlarmDatabase::alarmDatabaseCloseSignals, [=]() {
			this->show(); // ��������ʾ
			_alarm_database->hide();
			});

		this->hide();  // ����������
		_alarm_database->show();// ��ʾ�������ݴ���
		});
}
// ͨ������
void BoilerFeedPowderOnLineMonitoringSystem::initChannelDatabase()
{
	connect(ui->action_channel_database, &QAction::triggered, [=]() {
		if (nullptr == _channel_database) // ʵ������Դ
			_channel_database = new ChannelDatabase;

		// �źźͲۺ���
		connect(_channel_database, &ChannelDatabase::fromChannelDatabaseToMainScreenSignals, [=]()
			{
				_channel_database->close();
			});
		connect(_channel_database, &ChannelDatabase::channelDatabaseCloseSignals, [=]() {
			this->show(); // ��������ʾ
			_channel_database->hide();
			});

		this->hide();// ����������
		_channel_database->show();// ��ʾ�������ݴ���
		});
}
// ���ͷ��ͼ��ʾ
void BoilerFeedPowderOnLineMonitoringSystem::initRodTypeWindPowderDiagram()
{
	connect(ui->action_rod_type_wind_powder_diagram, &QAction::triggered, [=]() {
		if (nullptr == _rod_type_wind_powder_diagram) // ʵ������Դ
			_rod_type_wind_powder_diagram = new RodTypeWindPowderDiagram(nullptr, &_result_data);

		// ���²���, ����ǰ���޸��˱�����
		emit _my_thread.saveCoefficientSignals(_configure->getAllCoefficient());  // ��ֹϵ���Ѿ�������
		// �źźͲ�, �����˳���,��ô��
		connect(_rod_type_wind_powder_diagram, &RodTypeWindPowderDiagram::rodTypeWindPowderDiagramCloseSignals, [=]() {
			this->show(); // ��������ʾ
			_rod_type_wind_powder_diagram->hide();
			});

		this->hide();// �ر�������
		_rod_type_wind_powder_diagram->show(); // ��ʾ�ô���
		});
}

// һ�η���Բͼ
void BoilerFeedPowderOnLineMonitoringSystem::initTangentialCircleDiagramOfPrimaryWind()
{
	connect(ui->action_tangential_circle_diagram_of_primary_wind, &QAction::triggered, [=]() {
		if (nullptr == _tangential_circle_diagram_of_primary_wind) // ʵ������Դ
			_tangential_circle_diagram_of_primary_wind = new TangentialCircleDiagramOfPrimaryWind;
		// ���²���
		emit _my_thread.saveCoefficientSignals(_configure->getAllCoefficient());  // ��ֹϵ���Ѿ�������

		connect(_tangential_circle_diagram_of_primary_wind, &TangentialCircleDiagramOfPrimaryWind::tangentialCircleDiagramOfPrimaryWindCloseSignals, [=]() {
			this->show(); // ��������ʾ
			_tangential_circle_diagram_of_primary_wind->hide();
			});

		this->hide();// �ر�������
		_tangential_circle_diagram_of_primary_wind->show();// ��ʾ�ô���
		});
}

// ����ͼ
void BoilerFeedPowderOnLineMonitoringSystem::initTrendChart()
{
	connect(ui->action_trend_chart, &QAction::triggered, [=]() {
		if (nullptr == _trend_chart)
			_trend_chart = new TrendChart(nullptr, &_result_data);
		// ���²���
		emit _my_thread.saveCoefficientSignals(_configure->getAllCoefficient());  // ��ֹϵ���Ѿ�������

		connect(_trend_chart, &TrendChart::trendChartCloseSignals, [=]() {
			this->show(); // ��������ʾ
			_trend_chart->hide();
			});
		this->hide();// �ر�������
		_trend_chart->show();// ��ʾ�ô���
		});
}

// ��ʷͼ
void BoilerFeedPowderOnLineMonitoringSystem::initHistoricalTrendChart()
{
	connect(ui->action_historical_trend_chart, &QAction::triggered, [=]() {
		if (nullptr == _historical_trend_chart) // ʵ������Դ
			_historical_trend_chart = new HistoricalTrendChart(nullptr, &_result_data);
		emit _my_thread.saveCoefficientSignals(_configure->getAllCoefficient());  // ��ֹϵ���Ѿ�������

		connect(_historical_trend_chart, &HistoricalTrendChart::historicalTrendChartSignals, [=]() {
			this->show(); // ��������ʾ
			_historical_trend_chart->hide();
			});

		this->hide();
		_historical_trend_chart->show();
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
			// ������Ը����²���,��������Ѿ��޸�����
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
			_verify_password = new VerifyPassword(nullptr, _configure);

		_configure->setPassword();  // ��������
		_verify_password->setOption(1);
		_verify_password->show();

		connect(_verify_password, &VerifyPassword::verifyPasswordCloseSignals, [=]() {
			//ֱ�ӹر�������֤����
			_verify_password->hide();
			this->show();
			});

		connect(_verify_password, &VerifyPassword::fromVerifyPasswordToSpoutSignalsIsTrue, [=]() {
			// ������֤�ɹ�
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
			_verify_password = new VerifyPassword(nullptr, _configure);

		// ��������
		_configure->setPassword();
		_verify_password->setOption(2);
		// ������֤������ʾ
		_verify_password->show();

		connect(_verify_password, &VerifyPassword::verifyPasswordCloseSignals, [=]() {
			_verify_password->hide();
			this->show();
			});

		connect(_verify_password, &VerifyPassword::fromVerifyPasswordToBackrestCanalSignalsIsTrue, [=]() {
			// ������֤�ɹ�
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
	if (nullptr == _welcome_screen)
		_welcome_screen = new WelcomeScreen(nullptr);

	// welcomeScreenCloseSignals ���Զ�����ź�
	connect(_welcome_screen, &WelcomeScreen::welcomeScreenCloseSignals, [=]() {
		// �ر�����һ���߳�
		_my_thread.quitThread();
		_my_thread.wait();
		_welcome_screen = nullptr;

		// һ�����,���ǻ�ӭ����ֻ����һ��,һ������ѡ�����������,������Ϊ����������Ҫ�˳�
		this->close();
		});

	//�����Ӵ������ԣ��رռ�����
	_welcome_screen->setAttribute(Qt::WA_DeleteOnClose);

	// ��ʾ��ӭ����
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