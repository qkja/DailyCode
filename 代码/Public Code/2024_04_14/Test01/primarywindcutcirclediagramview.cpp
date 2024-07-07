#include "primarywindcutcirclediagramview.h"

primaryWindCutCircleDiagramView::primaryWindCutCircleDiagramView(QWidget *parent)
	: QWidget(parent)
{}

primaryWindCutCircleDiagramView::~primaryWindCutCircleDiagramView()
{}

void primaryWindCutCircleDiagramView::paintEvent(QPaintEvent* event)
{
	/*QPainter p(this);
	p.setPen(Qt::black);
	p.drawLine(50, 100, 50, 200);*/
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    // 设置矩形的位置和大小
    QRect rect(50, 50, 200, 100);

    // 设置矩形的颜色和边框
    painter.setBrush(Qt::blue);
    painter.setPen(Qt::black);

    // 绘制矩形
    painter.drawRect(rect);
}
