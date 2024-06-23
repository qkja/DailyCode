#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Test01.h"
#include "Sub.h"
#include "Test.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Test01Class; };
QT_END_NAMESPACE

class Test01 : public QMainWindow
{
	Q_OBJECT

public:
	Test01(QWidget* parent = nullptr);
	~Test01();
	void closeEvent(QCloseEvent*);
private:
	Ui::Test01Class* ui;
	Sub* sub;
	Test* _t;
};
