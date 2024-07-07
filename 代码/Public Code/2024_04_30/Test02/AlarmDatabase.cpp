#include "AlarmDatabase.h"

AlarmDatabase::AlarmDatabase(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::AlarmDatabaseClass())
    , _current_page_count(1)
    , _number_of_total_pages(1)
{
	ui->setupUi(this);
    init();

    QTimer* t = new QTimer;

    connect(t, &QTimer::timeout, [=]() {

        AlertData data;
        static int i = 1;
        data._sensor_name = "����" + std::to_string(i);
        data._alarm_type = "����";
        data._initial_time_point = "����";
        data._data = "����";
        data._end_time_point = "����";
        writeData(data);
        ++i;
        });

    t->start(1000);
}

AlarmDatabase::~AlarmDatabase()
{
	delete ui;
}

void AlarmDatabase::init()
{
    setTableWidget();
    ui->label_cur->setText(std::to_string(_current_page_count).c_str());
    ui->label_total->setText(std::to_string(_number_of_total_pages).c_str());
    connect(ui->pushButton_up, &QPushButton::clicked, [=]() {

        int cur = ui->label_cur->text().toInt();
        cur = cur - 1;
        if (0 == cur)
            cur = ui->label_total->text().toInt();
        showView(cur);

        ui->label_cur->setText(std::to_string(cur).c_str());
        std::cout << "shang" << std::endl;
        _current_page_count = cur;

        });
    connect(ui->pushButton_next, &QPushButton::clicked, [=]() {
        int cur = ui->label_cur->text().toInt();
        cur = cur % ui->label_total->text().toInt() + 1;
        showView(cur);
        ui->label_cur->setText(std::to_string(cur).c_str());
        std::cout << "xia" << std::endl;
        _current_page_count = cur;
        });
}

void AlarmDatabase::setTableWidget()
{
    ui->tableWidget->resizeRowsToContents();//���������ݴ�С
    ui->tableWidget->setColumnCount(COL);//��������
    ui->tableWidget->setRowCount(ROW * NUMBER_OF_TOTAL_PAGES);//��������
    ui->tableWidget->horizontalHeader()->setDefaultSectionSize(200);//����ͷ�Ĵ�С
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);//����������Ӧ���
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);//Ȼ������Ҫ��������ʹ�ÿ�ȵ���

    QStringList header;
    header << tr("����������") << tr("��������") << tr("��ʼʱ���") << tr("����") << tr("����ʱ���");
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->verticalHeader()->setVisible(false); //�����к���,trueΪ��ʾ
    ui->tableWidget->setSelectionMode(QAbstractItemView::ExtendedSelection); //�ɶ�ѡ��Ctrl��Shift�� Ctrl+A�����ԣ�
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows); //����ѡ����Ϊʱÿ��ѡ��һ��
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); //���ò��ɱ༭

    //����ˮƽ����ֱ��������ʽ
    ui->tableWidget->horizontalScrollBar()->setStyleSheet("QScrollBar{background:transparent; height:10px;}"
        "QScrollBar::handle{background:lightgray; border:2px solid transparent; border-radius:5px;}"
        "QScrollBar::handle:hover{background:gray;}"
        "QScrollBar::sub-line{background:transparent;}"
        "QScrollBar::add-line{background:transparent;}");
    ui->tableWidget->verticalScrollBar()->setStyleSheet("QScrollBar{background:transparent; width: 10px;}"
        "QScrollBar::handle{background:lightgray; border:2px solid transparent; border-radius:5px;}"
        "QScrollBar::handle:hover{background:gray;}"
        "QScrollBar::sub-line{background:transparent;}"
        "QScrollBar::add-line{background:transparent;}");

    ui->tableWidget->clearContents();//���������������������ݣ����ǲ������ͷ
}

void AlarmDatabase::writeData(const AlertData& data)
{
    if (_v.size() == ROW * NUMBER_OF_TOTAL_PAGES)
    {
        _v.erase(_v.begin());
        _v.push_back(data);
        std::string _sensor_name; // ����������

        for (int i = 0; i < _v.size(); ++i)
        {
            ui->tableWidget->setItem(i, 0, new QTableWidgetItem(_v[i]._sensor_name.c_str()));
            ui->tableWidget->setItem(i, 1, new QTableWidgetItem(_v[i]._alarm_type.c_str()));
            ui->tableWidget->setItem(i, 2, new QTableWidgetItem(_v[i]._initial_time_point.c_str()));
            ui->tableWidget->setItem(i, 3, new QTableWidgetItem(_v[i]._data.c_str()));
            ui->tableWidget->setItem(i, 4, new QTableWidgetItem(_v[i]._end_time_point.c_str()));
        }
    }
    else
    {
        _v.push_back(data);
        ui->tableWidget->setItem(_v.size() - 1, 0, new QTableWidgetItem(_v.back()._sensor_name.c_str()));
        ui->tableWidget->setItem(_v.size() - 1, 1, new QTableWidgetItem(_v.back()._alarm_type.c_str()));
        ui->tableWidget->setItem(_v.size() - 1, 2, new QTableWidgetItem(_v.back()._initial_time_point.c_str()));
        ui->tableWidget->setItem(_v.size() - 1, 3, new QTableWidgetItem(_v.back()._data.c_str()));
        ui->tableWidget->setItem(_v.size() - 1, 4, new QTableWidgetItem(_v.back()._end_time_point.c_str()));
    }
    ui->tableWidget->update();

    _number_of_total_pages = _v.size() / ROW;
    if (_v.size() % ROW != 0)
        _number_of_total_pages = _number_of_total_pages + 1;

    ui->label_cur->setText(std::to_string(_current_page_count).c_str());
    ui->label_total->setText(std::to_string(_number_of_total_pages).c_str());
    showView(_current_page_count);
}


void AlarmDatabase::showView(int page)
{
    int start = ROW * (page - 1);
    int end = start + ROW;
    if (end > _v.size())
        end = _v.size();
    for (int i = 0; i < ui->tableWidget->rowCount(); ++i)
    {
        if (i >= start && i < end)
        {
            ui->tableWidget->setRowHidden(i, false);
        }
        else
        {
            ui->tableWidget->setRowHidden(i, true);
        }
    }
}
