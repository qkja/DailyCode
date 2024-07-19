#include "Test01.h"
#include <QtWidgets/QApplication>
#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDateTime>
#include <QTimer>
#include <QPainter>
#include <QPen>
#include <QPoint>
#include <cmath>
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")// ��ָ���֧��VS����
#endif
class MyWidget : public QWidget {
public:
    MyWidget(QWidget* parent = nullptr) : QWidget(parent) {
        //ÿ��ˢ�»�ͼ
        QTimer* timer2 = new QTimer(this);
        connect(timer2, &QTimer::timeout, this, &MyWidget::updateSquare);
        timer2->start(1000);

        //���ڷ�Ϊ������ �Ϸ�һ����ǩ��ʾʱ�� �в���ʾ�������� �·���ʾʾ��
        //�����Ϸ�
            // ���һ����ǩ����ʾ��ǰʱ��
        dateTimeLabel = new QLabel(this);
        dateTimeLabel->setAlignment(Qt::AlignCenter);
        updateDateTime(); // Update the time initially
        QTimer* timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &MyWidget::updateDateTime);
        timer->start(1000); // ÿ�����һ��ʱ��

        //�����в�
            // �����������Ʊ�ǩ
        aLabel = new QLabel("D��", this);
        bLabel = new QLabel("E��", this);
        cLabel = new QLabel("F��", this);
        dLabel = new QLabel("A��", this);
        eLabel = new QLabel("B��", this);
        fLabel = new QLabel("C��", this);

        //��ǩ���뷽ʽΪ���ж���
        aLabel->setAlignment(Qt::AlignCenter);
        bLabel->setAlignment(Qt::AlignCenter);
        cLabel->setAlignment(Qt::AlignCenter);
        dLabel->setAlignment(Qt::AlignCenter);
        eLabel->setAlignment(Qt::AlignCenter);
        fLabel->setAlignment(Qt::AlignCenter);

        // ����һ�����Ĵ�ֱ���� ���������ˮƽ���� ����ˮƽ�����и���������ֱ����
        QVBoxLayout* CenterLayout = new QVBoxLayout;

        //������ֱ����
        QVBoxLayout* squareLayout1 = new QVBoxLayout;
        squareLayout1->addStretch(1);
        squareLayout1->addWidget(aLabel);
        QVBoxLayout* squareLayout2 = new QVBoxLayout;
        squareLayout2->addWidget(bLabel);
        QVBoxLayout* squareLayout3 = new QVBoxLayout;
        squareLayout3->addWidget(cLabel);
        QVBoxLayout* squareLayout4 = new QVBoxLayout;
        squareLayout4->addStretch(1);
        squareLayout4->addWidget(dLabel);
        QVBoxLayout* squareLayout5 = new QVBoxLayout;
        squareLayout5->addWidget(eLabel);
        QVBoxLayout* squareLayout6 = new QVBoxLayout;
        squareLayout6->addWidget(fLabel);

        //����������ֱ���ֵĶ��뷽ʽΪ�ײ�����
        squareLayout1->setAlignment(Qt::AlignCenter | Qt::AlignCenter);
        squareLayout2->setAlignment(Qt::AlignCenter | Qt::AlignBottom);
        squareLayout3->setAlignment(Qt::AlignCenter | Qt::AlignBottom);
        squareLayout4->setAlignment(Qt::AlignCenter | Qt::AlignBottom);
        squareLayout5->setAlignment(Qt::AlignCenter | Qt::AlignBottom);
        squareLayout6->setAlignment(Qt::AlignCenter | Qt::AlignBottom);

        //��������ˮƽ���� �ֱ����������ֱ����
        QHBoxLayout* CenLay_Hor1 = new QHBoxLayout;
        CenLay_Hor1->addLayout(squareLayout1);
        CenLay_Hor1->addLayout(squareLayout2);
        CenLay_Hor1->addLayout(squareLayout3);

        QHBoxLayout* CenLay_Hor2 = new QHBoxLayout;
        CenLay_Hor2->addLayout(squareLayout4);
        CenLay_Hor2->addLayout(squareLayout5);
        CenLay_Hor2->addLayout(squareLayout6);

        //������ˮƽ���ַŵ����Ĵ�ֱ����
        CenterLayout->addLayout(CenLay_Hor1);
        CenterLayout->addLayout(CenLay_Hor2);

        // �����ײ�����ʾ��
            //ʾ��1 ú��Ũ�� ��ɫ
            //������ɫ����
        redRectLabel = new QLabel(this);
        redRectLabel->setFixedSize(50, 25);
        redRectLabel->setStyleSheet("background-color: red");
        //������ǩ��ʾ��ú��Ũ�ȡ�
        redLabel = new QLabel("ú��Ũ��", this);
        redLabel->setAlignment(Qt::AlignCenter);


        //ʾ��2 ���� ��ɫ
        //������ɫ����
        whiteRectLabel = new QLabel(this);
        whiteRectLabel->setFixedSize(50, 25);
        whiteRectLabel->setStyleSheet("background-color: white");
        //������ǩ��ʾ�����١�
        whiteLabel = new QLabel("����", this);
        whiteLabel->setAlignment(Qt::AlignCenter);

        //����һ��ˮƽ���� ���ĸ�����Ž�ȥ
        QHBoxLayout* redwhiteLayout = new QHBoxLayout;
        //addStretch�������൱�ڵ��ɣ����ĸ����ǰ�ͺ����һ�����ɣ��Ϳ���ʹ�ĸ�������յ�������Ļ����
        redwhiteLayout->addStretch(1);
        redwhiteLayout->addWidget(redRectLabel);
        redwhiteLayout->addWidget(redLabel);
        redwhiteLayout->addWidget(whiteRectLabel);
        redwhiteLayout->addWidget(whiteLabel);
        redwhiteLayout->addStretch(1);

        // ����һ�����ְ�������Ļ�Ž�ȥ
        QVBoxLayout* mainLayout = new QVBoxLayout(this);
        mainLayout->addWidget(dateTimeLabel, 0, Qt::AlignTop | Qt::AlignHCenter);
        mainLayout->addLayout(CenterLayout);
        mainLayout->addLayout(redwhiteLayout);

    }


protected:
    //ÿ��ˢ�»�ͼ
    void paintEvent(QPaintEvent* event) override {
        Q_UNUSED(event);
        QPainter* tempPainter = new QPainter(this);

        //��6�������α���

        //��һ�������α���,aLabel,D��

        //�������ʴ�ϸ
        int pen_width = this->width() / 200;
        QPen pen;
        pen.setWidth(pen_width);
        tempPainter->setPen(pen); // ������Ӧ�õ�painter��
        //�����,�ĸ������ֱ�Ϊ�������xy��������
        //���������α��̱߳�
        int length = this->width() / 6;
        //����������
        int squ1_x1 = ((this->width() / 3) / 2) - (length / 2) + pen_width;
        int squ1_y1 = aLabel->pos().y() - length - pen_width - 5;

        //��ˢ����伸��ͼ�εĵ�ɫ�壬����ɫ����������
        QBrush brush;
        brush.setColor(QColor(105, 105, 105, 120));
        brush.setStyle(Qt::SolidPattern);
        tempPainter->setBrush(brush);

        //������
        tempPainter->drawRect(squ1_x1, squ1_y1, length, length);

        //������ԲȦ
        //����Բ��ֱ��
        int cir1_dia = this->width() / 25;
        //��ԲȦ����Բ���Կ������Ȼ�һ������ Ȼ��������ε�����Բ �����ĸ�����������һ��
        //����������
        int cir1_x1 = squ1_x1 + length / 2 - cir1_dia / 2;
        int cir1_y1 = squ1_y1 + length / 2 - cir1_dia / 2;
        //��������
        pen.setWidth(1);
        pen.setColor(QColor(0, 0, 255, 255));
        tempPainter->setPen(pen);
        //��ˢ����伸��ͼ�εĵ�ɫ�壬����ɫ����������
        brush.setColor(QColor(255, 0, 0, 120));
        brush.setStyle(Qt::SolidPattern);
        tempPainter->setBrush(brush);
        //��Բ
        //����ԲȦƫ��������ΧΪ-10��10
        int cir1_offset = qrand() % 21 - 10;
        //����ԲȦ������������յ�
        double cir1_centerline_x1 = cir1_x1 + cir1_dia / 2;
        double cir1_centerline_y1 = cir1_y1 - 5 * pen_width;
        double cir1_centerline_x2 = cir1_centerline_x1;
        double cir1_centerline_y2 = cir1_centerline_y1 + cir1_dia + 2 * 5 * pen_width;

        if (cir1_offset == 0) {
            tempPainter->drawEllipse(cir1_x1, cir1_y1, cir1_dia, cir1_dia);
        }
        else {
            //���������ƫ����������ԲȦƫ�ƣ�������������
            tempPainter->drawEllipse(cir1_x1 + cir1_offset, cir1_y1, cir1_dia, cir1_dia);
            tempPainter->setPen(QPen(Qt::yellow, 2, Qt::DashLine));
            tempPainter->drawLine(cir1_centerline_x1, cir1_centerline_y1, cir1_centerline_x2, cir1_centerline_y2);
        }


        //������б��
        //����������ϸ
        int pen_width2 = this->width() / 110;
        pen.setWidth(pen_width2);
        tempPainter->setPen(pen);

        //����ָ����Χ�ڵ������������ʹ��ȡģ�������%��
        //���ڻ�ȡú��Ũ��������
        // ָ����ΧΪ0��9
        int randomRange = 10;

        //����б��������
        double l1_correction = this->width() / 23;

        //��һ��б��
            //ȷ��б�ߵ�������յ�
        int l11_x1 = squ1_x1 + pen_width;
        int l11_y1 = squ1_y1 + pen_width;
        int l11_x2 = squ1_x1 + l1_correction;
        int l11_y2 = squ1_y1 + l1_correction;
        //����б���ܳ�
        double l11_length = sqrt(pow((l11_x2 - l11_x1), 2) + pow(l11_y2 - l11_y1, 2));

        //����������ݣ�ú��Ũ��������
        //ú��Ũ��
        double l11_pulverized_coal_concentration = qrand() % randomRange;
        //����
        double l11_flow_rate = qrand() % randomRange;

        //����ú��Ũ�ȣ����ߣ��ĳ���
        double l11_pulverized_coal_concentration_length = l11_length * (l11_pulverized_coal_concentration / (l11_pulverized_coal_concentration + l11_flow_rate));

        //��������յ�����
        double l11_x_half = (l11_pulverized_coal_concentration_length / l11_length) * (l11_x2 - l11_x1) + l11_x1;
        double l11_y_half = (l11_pulverized_coal_concentration_length / l11_length) * (l11_y2 - l11_y1) + l11_y1;

        //�Ȼ��ƺ���
        pen.setColor(QColor(255, 0, 0, 255));
        tempPainter->setPen(pen);
        tempPainter->drawLine(l11_x1, l11_y1, l11_x_half, l11_y_half);
        //�ٻ��ư���
        pen.setColor(QColor(255, 255, 255, 255));
        tempPainter->setPen(pen);
        tempPainter->drawLine(l11_x_half, l11_y_half, l11_x2, l11_y2);

        //�ڶ���б��
                //ȷ��б�ߵ�������յ�
        int l12_x1 = squ1_x1 + length - pen_width;
        int l12_y1 = squ1_y1 + pen_width;
        int l12_x2 = l12_x1 - l1_correction + pen_width;
        int l12_y2 = l12_y1 + l1_correction - pen_width;
        //����б���ܳ�
        double l12_length = sqrt(pow((l12_x2 - l12_x1), 2) + pow(l12_y2 - l12_y1, 2));

        //����������ݣ�ú��Ũ��������

        //ú��Ũ��
        double l12_pulverized_coal_concentration = qrand() % randomRange;
        //����
        double l12_flow_rate = qrand() % randomRange;

        //����ú��Ũ�ȣ����ߣ��ĳ���
        double l12_pulverized_coal_concentration_length = l12_length * (l12_pulverized_coal_concentration / (l12_pulverized_coal_concentration + l12_flow_rate));

        //��������յ�����
        double l12_x_half = (l12_pulverized_coal_concentration_length / l12_length) * (l12_x2 - l12_x1) + l12_x1;
        double l12_y_half = (l12_pulverized_coal_concentration_length / l12_length) * (l12_y2 - l12_y1) + l12_y1;

        //�Ȼ��ƺ���
        pen.setColor(QColor(255, 0, 0, 255));
        tempPainter->setPen(pen);
        tempPainter->drawLine(l12_x1, l12_y1, l12_x_half, l12_y_half);
        //�ٻ��ư���
        pen.setColor(QColor(255, 255, 255, 255));
        tempPainter->setPen(pen);
        tempPainter->drawLine(l12_x_half, l12_y_half, l12_x2, l12_y2);

        //������б�ߣ����½ǿ�ʼ��
            //ȷ��б�ߵ�������յ�
        int l13_x1 = squ1_x1 + length - pen_width;
        int l13_y1 = squ1_y1 + length - pen_width;
        int l13_x2 = l13_x1 - l1_correction + pen_width;
        int l13_y2 = l13_y1 - l1_correction + pen_width;
        //����б���ܳ�
        double l13_length = sqrt(pow((l13_x2 - l13_x1), 2) + pow(l13_y2 - l13_y1, 2));

        //����������ݣ�ú��Ũ��������
        //ú��Ũ��
        double l13_pulverized_coal_concentration = qrand() % randomRange;
        //����
        double l13_flow_rate = qrand() % randomRange;

        //����ú��Ũ�ȣ����ߣ��ĳ���
        double l13_pulverized_coal_concentration_length = l13_length * (l13_pulverized_coal_concentration / (l13_pulverized_coal_concentration + l13_flow_rate));

        //��������յ�����
        double l13_x_half = (l13_pulverized_coal_concentration_length / l13_length) * (l13_x2 - l13_x1) + l13_x1;
        double l13_y_half = (l13_pulverized_coal_concentration_length / l13_length) * (l13_y2 - l13_y1) + l13_y1;

        //�Ȼ��ƺ���
        pen.setColor(QColor(255, 0, 0, 255));
        tempPainter->setPen(pen);
        tempPainter->drawLine(l13_x1, l13_y1, l13_x_half, l13_y_half);
        //�ٻ��ư���
        pen.setColor(QColor(255, 255, 255, 255));
        tempPainter->setPen(pen);
        tempPainter->drawLine(l13_x_half, l13_y_half, l13_x2, l13_y2);

        //������б�ߣ����½ǿ�ʼ��
            //ȷ��б�ߵ�������յ�
        int l14_x1 = squ1_x1 + pen_width;
        int l14_y1 = squ1_y1 + length - pen_width;
        int l14_x2 = l14_x1 + l1_correction - pen_width;
        int l14_y2 = l14_y1 - l1_correction + pen_width;
        //����б���ܳ�
        double l14_length = sqrt(pow((l14_x2 - l14_x1), 2) + pow(l14_y2 - l14_y1, 2));

        //����������ݣ�ú��Ũ��������
        //ú��Ũ��
        double l14_pulverized_coal_concentration = qrand() % randomRange;
        //����
        double l14_flow_rate = qrand() % randomRange;

        //����ú��Ũ�ȣ����ߣ��ĳ���
        double l14_pulverized_coal_concentration_length = l14_length * (l14_pulverized_coal_concentration / (l14_pulverized_coal_concentration + l14_flow_rate));

        //��������յ�����
        double l14_x_half = (l14_pulverized_coal_concentration_length / l14_length) * (l14_x2 - l14_x1) + l14_x1;
        double l14_y_half = (l14_pulverized_coal_concentration_length / l14_length) * (l14_y2 - l14_y1) + l14_y1;

        //�Ȼ��ƺ���
        pen.setColor(QColor(255, 0, 0, 255));
        tempPainter->setPen(pen);
        tempPainter->drawLine(l14_x1, l14_y1, l14_x_half, l14_y_half);
        //�ٻ��ư���
        pen.setColor(QColor(255, 255, 255, 255));
        tempPainter->setPen(pen);
        tempPainter->drawLine(l14_x_half, l14_y_half, l14_x2, l14_y2);


        //�ٻ���һ�µ�һ�����̱߿�
        pen.setWidth(pen_width);
        pen.setColor(QColor(0, 0, 0, 255));
        tempPainter->setBrush(Qt::NoBrush);
        tempPainter->setPen(pen);
        tempPainter->drawRect(squ1_x1, squ1_y1, length, length);

        delete tempPainter;
    }



private:
    QLabel* dateTimeLabel;
    QLabel* aLabel, * bLabel, * cLabel, * dLabel, * eLabel, * fLabel;
    QLabel* redRectLabel, * whiteRectLabel;
    QLabel* redLabel, * whiteLabel;

    //������ǩ��ʾʱ��
    void updateDateTime() {
        QDateTime currentDateTime = QDateTime::currentDateTime();
        QString dateTimeString = currentDateTime.toString("hh:mm:ss    yyyy-MM-dd");
        dateTimeLabel->setText(dateTimeString);
    }

    void updateSquare() {
        // Redraw the square
        repaint();
    }


};
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   /* Test01 w;
    w.show();*/
    MyWidget widget;
    widget.resize(600, 400); // Set the window size
    widget.show();
    return a.exec();
}
