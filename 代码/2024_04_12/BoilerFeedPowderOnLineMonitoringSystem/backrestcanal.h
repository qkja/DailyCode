#pragma once

#include <QWidget>
#include "ui_backrestcanal.h"
#include <iostream>
#include "configure.h"
QT_BEGIN_NAMESPACE
namespace Ui
{
	class BackrestCanalClass;
};
QT_END_NAMESPACE

class BackrestCanal : public QWidget
{
	Q_OBJECT

public:
	BackrestCanal(QWidget *parent = nullptr, Configure* configure = nullptr);
	~BackrestCanal();
private:
	void setReadOnly(bool); // lable 控件是否可以被修改
signals:
	void fromBackrestCanalToMainScreenSignals();
	void fromBackrestCanalToMainScreenToSaveSignals(std::string, std::string, std::string, std::string
		, std::string, std::string, std::string, std::string
		, std::string, std::string, std::string, std::string
		, std::string, std::string, std::string, std::string
		, std::string, std::string, std::string, std::string
		, std::string, std::string, std::string, std::string);

private:
	Ui::BackrestCanalClass *ui;
	Configure* _configure;

	/*std::string _a1;
	std::string _a2;
	std::string _a3;
	std::string _a4;
	std::string _b1;
	std::string _b2;
	std::string _b3;
	std::string _b4;
	std::string _c1;
	std::string _c2;
	std::string _c3;
	std::string _c4;
	std::string _d1;
	std::string _d2;
	std::string _d3;
	std::string _d4;
	std::string _e1;
	std::string _e2;
	std::string _e3;
	std::string _e4;*/
};
