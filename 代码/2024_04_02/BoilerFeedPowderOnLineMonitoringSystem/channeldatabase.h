#pragma once

#include <QWidget>
#include "ui_channeldatabase.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ChannelDatabaseClass; };
QT_END_NAMESPACE

class ChannelDatabase : public QWidget
{
	Q_OBJECT

public:
	ChannelDatabase(QWidget *parent = nullptr);
	~ChannelDatabase();
signals:
	void fromChannelDatabaseToMainScreenSignals();
private:
	Ui::ChannelDatabaseClass *ui;
};
