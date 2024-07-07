#pragma once

#include <QWidget>
#include "ui_Spout.h"
#include <iostream>
#include "Configure.h"

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")// ��ָ���֧��VS����
#endif

QT_BEGIN_NAMESPACE
namespace Ui { class SpoutClass; };
QT_END_NAMESPACE

class Spout : public QWidget
{
	Q_OBJECT

public:
	Spout(QWidget* parent = nullptr, Configure* configure = nullptr);
	~Spout();
	void init();
signals:
	void fromSpoutToMianScreenSignals();
	void spoutCloseSignals();
private:
	void setReadOnly(bool); // lable �ؼ��Ƿ���Ա��޸�
	void closeEvent(QCloseEvent*);
private:
	Ui::SpoutClass* ui;
	Configure* _configure;
};
