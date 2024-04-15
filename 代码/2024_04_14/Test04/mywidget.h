#pragma once
#include <qpainter.h>
#include <QWidget>

class MyWidget  : public QWidget
{
	Q_OBJECT

public:
	MyWidget(QWidget *parent);
	~MyWidget();
	void paintEvent(QPaintEvent* event) override;
};
