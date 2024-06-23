#pragma once
#include <QPainter>

#include <QWidget>

class primaryWindCutCircleDiagramView  : public QWidget
{
	Q_OBJECT

public:
	primaryWindCutCircleDiagramView(QWidget *parent = nullptr);
	~primaryWindCutCircleDiagramView();
protected:
	void paintEvent(QPaintEvent*) override;
};
