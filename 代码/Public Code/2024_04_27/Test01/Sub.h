#pragma once

#include <QWidget>
#include "ui_Sub.h"

QT_BEGIN_NAMESPACE
namespace Ui { class SubClass; };
QT_END_NAMESPACE
#include "Test.h"
class Sub : public QWidget
{
	Q_OBJECT

public:
	Sub(QWidget* parent = nullptr, Test* t = nullptr);
	~Sub();
signals:
	void subClose();
private:
	void closeEvent(QCloseEvent*);

private:
	Ui::SubClass* ui;
	Test* _t;
};
