#pragma once
#include <iostream>

#include <QWidget>
#include "ui_spout.h"
#include "configure.h"
QT_BEGIN_NAMESPACE
namespace Ui
{
	class SpoutClass;
};
QT_END_NAMESPACE

class Spout : public QWidget
{
	Q_OBJECT

public:
	Spout(QWidget* parent = nullptr, Configure* configure = nullptr);
	~Spout();
private:
	void setReadOnly(bool); // lable 控件是否可以被修改
signals:
	void fromSpoutToMianScreenSignals();

private:
	Ui::SpoutClass* ui;
	Configure* _configure;
};
