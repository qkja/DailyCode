#pragma once
#include "qdebug.h"
#include <QWidget>
#include <qobject.h>
#include <qthread.h>
class Worker  : public QObject
{
	Q_OBJECT

public:
	Worker(QObject*parent = nullptr);
	~Worker();
public slots:
	void doWork()
	{
		qDebug() << "Worker thread ID:" << QThread::currentThreadId();
	}
};
