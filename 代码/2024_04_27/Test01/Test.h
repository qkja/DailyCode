#pragma once

#include <QWidget>
#include <string>

class Test  : public QWidget
{
	Q_OBJECT

public:
	Test(QWidget *parent);
	~Test();
	void func();

signals:
	void mySig(const std::string&);
};
