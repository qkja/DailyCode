#pragma once

#include <QWidget>
#include <iostream>
#include <qpainter.h>

#define RECTANGULAR_LINE_WIDTH 5  // �����߶ο��
#define WIDTH_OF_A_CIRCLE 5       // Բ���߶ο��
#define DIAMETER 50               // Բ��ֱ��
#define STRAIGHT_LINE_WIDTH 5     // б�ߵĿ��
class PrimaryWindCutCircleDiagramView : public QWidget
{
	Q_OBJECT

public:
	PrimaryWindCutCircleDiagramView(QWidget* parent);
	~PrimaryWindCutCircleDiagramView();
protected:
	void paintEvent(QPaintEvent*) override;
};
