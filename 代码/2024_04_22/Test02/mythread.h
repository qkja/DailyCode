#pragma once
#include <QThread>
#include <QDebug>
#include <QThread>

class MyThread  : public QThread
{
	Q_OBJECT

public:
	MyThread(QObject *parent = nullptr);
	~MyThread();
public:
	void run();
};
