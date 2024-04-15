#pragma once

#include <QThread>
#include "Task.hpp"
#include <iostream>
#include <fstream>
#include "configure.h"

class MyThread : public QThread
{
	Q_OBJECT
	friend class BoilerFeedPowderOnLineMonitoringSystem;

public:
	MyThread(QObject *parent = nullptr);
	~MyThread();
	void run() override;
signals:
	void produceSignals(Task);
protected slots:
	void stopProcessing();
private:
	void parse(Task *, const std::string &);

private:
	Configure *_configure;
    volatile bool _flag;
};
