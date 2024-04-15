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

    // ���þ��ε�λ�úʹ�С
    QRect rect(50, 50, 200, 100);

    // ���þ��ε���ɫ�ͱ߿�
    painter.setBrush(Qt::blue);
    painter.setPen(Qt::black);

    // ���ƾ���
    painter.drawRect(rect);
}
