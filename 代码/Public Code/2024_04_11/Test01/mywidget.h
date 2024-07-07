#pragma once

#include <QWidget>
#include "ui_mywidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MyWidgetClass; };
QT_END_NAMESPACE

class MyWidget : public QWidget
{
	Q_OBJECT

public:

	MyWidget(QWidget *parent = nullptr);
	~MyWidget();
	void closeEvent(QCloseEvent*);

signals:
	void ExitWin(); // �½�һ���źŲ�
private:
	Ui::MyWidgetClass *ui;
};
