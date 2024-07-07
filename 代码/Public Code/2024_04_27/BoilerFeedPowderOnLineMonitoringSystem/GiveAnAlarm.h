#pragma once

#include <QWidget>
#include "ui_GiveAnAlarm.h"
#include <iostream>
#include "Configure.h"
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")// ��ָ���֧��VS����
#endif

QT_BEGIN_NAMESPACE
namespace Ui { class GiveAnAlarmClass; };
QT_END_NAMESPACE

class GiveAnAlarm : public QWidget
{
	Q_OBJECT

public:
	GiveAnAlarm(QWidget* parent = nullptr, Configure* configure = nullptr);
	~GiveAnAlarm();
	void init();
signals:
	void giveAnAlarmCloseSignals();
	void fromGiveAnAlarmToMainScreenSignals();
private:
	void closeEvent(QCloseEvent*);
	int strfromDoubleToInt(const std::string&);  // �ַ���ת����
	std::string intToStr(int);                   // ����ת�ַ���
private:
	Ui::GiveAnAlarmClass* ui;
	Configure* _configure;
};
