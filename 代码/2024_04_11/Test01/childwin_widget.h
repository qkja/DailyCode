#pragma once

#include <QWidget>
#include "ui_childwin_widget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ChildWin_WidgetClass; };
QT_END_NAMESPACE

class ChildWin_Widget : public QWidget
{
	Q_OBJECT

public:
	ChildWin_Widget(QWidget *parent = nullptr);
	~ChildWin_Widget();
	// ��д�ر��¼�
	void closeEvent(QCloseEvent*);

signals:
	void ExitWin(); // �½�һ���źŲ�
private:
	Ui::ChildWin_WidgetClass *ui;
};
