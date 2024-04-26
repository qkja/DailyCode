#pragma once

#include "configure.h"
#include "ui_backrestcanal.h"
#include <iostream>
#include <QWidget>
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
	BackrestCanal(QWidget* parent = nullptr, Configure* configure = nullptr);
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
	Ui::BackrestCanalClass* ui;
	Configure* _configure;
};
