#pragma once
#include <QThread>
#include "Task.hpp"
class ProducerThread  : public QThread
{
	Q_OBJECT

public:
	ProducerThread();
	~ProducerThread();
	void run() override;
signals:
	void produceSignals(Task);
private:
	void parse(Task* task, const std::string& line);
};