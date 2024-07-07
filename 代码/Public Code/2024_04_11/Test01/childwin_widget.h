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
	// 重写关闭事件
	void closeEvent(QCloseEvent*);

signals:
	void ExitWin(); // 新建一个信号槽
private:
	Ui::ChildWin_WidgetClass *ui;
};
