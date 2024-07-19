#include "childwin_widget.h"

ChildWin_Widget::ChildWin_Widget(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::ChildWin_WidgetClass())
{
	ui->setupUi(this);
}

ChildWin_Widget::~ChildWin_Widget()
{
	delete ui;
}

void ChildWin_Widget::closeEvent(QCloseEvent*)
{
	emit ExitWin();
}
