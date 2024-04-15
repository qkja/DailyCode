#pragma once
#include <iostream>

#include <QWidget>
#include "ui_spout.h"
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
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
	Spout(QWidget *parent = nullptr);
	~Spout();
signals:
	void fromSpoutToMianScreenSignals();

private:
	Ui::SpoutClass *ui;
};
