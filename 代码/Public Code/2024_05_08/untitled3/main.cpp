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


class MyWidget : public QWidget {
public:
    MyWidget(QWidget *parent = nullptr) : QWidget(parent) {
        //每秒刷新画图
        QTimer *timer2 = new QTimer(this);
        connect(timer2, &QTimer::timeout, this, &MyWidget::updateSquare);
        timer2->start(1000);

        //窗口分为三部分 上方一个标签显示时间 中部显示六个表盘 下方显示示例
        //窗口上方
            // 添加一个标签来显示当前时间
            dateTimeLabel = new QLabel(this);
            dateTimeLabel->setAlignment(Qt::AlignCenter);
            updateDateTime(); // Update the time initially
            QTimer *timer = new QTimer(this);
            connect(timer, &QTimer::timeout, this, &MyWidget::updateDateTime);
            timer->start(1000); // 每秒更新一次时间

        //窗口中部
            // 建立六个名称标签
            aLabel = new QLabel("D层", this);
            bLabel = new QLabel("E层", this);
            cLabel = new QLabel("F层", this);
            dLabel = new QLabel("A层", this);
            eLabel = new QLabel("B层", this);
            fLabel = new QLabel("C层", this);

            //标签对齐方式为居中对齐
            aLabel->setAlignment(Qt::AlignCenter);
            bLabel->setAlignment(Qt::AlignCenter);
            cLabel->setAlignment(Qt::AlignCenter);
            dLabel->setAlignment(Qt::AlignCenter);
            eLabel->setAlignment(Qt::AlignCenter);
            fLabel->setAlignment(Qt::AlignCenter);

            // 创建一个中心垂直布局 里面放两个水平布局 两个水平布局中各放三个垂直布局
            QVBoxLayout *CenterLayout = new QVBoxLayout;

            //六个垂直布局
            QVBoxLayout *squareLayout1 = new QVBoxLayout;
            squareLayout1->addStretch(1);
            squareLayout1->addWidget(aLabel);
            QVBoxLayout *squareLayout2 = new QVBoxLayout;
            squareLayout2->addWidget(bLabel);
            QVBoxLayout *squareLayout3 = new QVBoxLayout;
            squareLayout3->addWidget(cLabel);
            QVBoxLayout *squareLayout4 = new QVBoxLayout;
            squareLayout4->addStretch(1);
            squareLayout4->addWidget(dLabel);
            QVBoxLayout *squareLayout5 = new QVBoxLayout;
            squareLayout5->addWidget(eLabel);
            QVBoxLayout *squareLayout6 = new QVBoxLayout;
            squareLayout6->addWidget(fLabel);

            //设置六个垂直布局的对齐方式为底部居中
            squareLayout1->setAlignment(Qt::AlignCenter | Qt::AlignCenter);
            squareLayout2->setAlignment(Qt::AlignCenter | Qt::AlignBottom);
            squareLayout3->setAlignment(Qt::AlignCenter | Qt::AlignBottom);
            squareLayout4->setAlignment(Qt::AlignCenter | Qt::AlignBottom);
            squareLayout5->setAlignment(Qt::AlignCenter | Qt::AlignBottom);
            squareLayout6->setAlignment(Qt::AlignCenter | Qt::AlignBottom);

            //建立两个水平布局 分别放入三个垂直布局
            QHBoxLayout *CenLay_Hor1 = new QHBoxLayout;
            CenLay_Hor1->addLayout(squareLayout1);
            CenLay_Hor1->addLayout(squareLayout2);
            CenLay_Hor1->addLayout(squareLayout3);

            QHBoxLayout *CenLay_Hor2 = new QHBoxLayout;
            CenLay_Hor2->addLayout(squareLayout4);
            CenLay_Hor2->addLayout(squareLayout5);
            CenLay_Hor2->addLayout(squareLayout6);

            //将两个水平布局放到中心垂直布局
            CenterLayout->addLayout(CenLay_Hor1);
            CenterLayout->addLayout(CenLay_Hor2);

        // 创建底部两个示例
            //示例1 煤粉浓度 红色
            //创建红色矩形
            redRectLabel = new QLabel(this);
            redRectLabel->setFixedSize(50,25);
            redRectLabel->setStyleSheet("background-color: red");
            //创建标签显示“煤粉浓度”
            redLabel = new QLabel("煤粉浓度", this);
            redLabel->setAlignment(Qt::AlignCenter);


            //示例2 流速 白色
            //创建白色矩形
            whiteRectLabel = new QLabel(this);
            whiteRectLabel->setFixedSize(50,25);
            whiteRectLabel->setStyleSheet("background-color: white");
            //创建标签显示“流速”
            whiteLabel = new QLabel("流速", this);
            whiteLabel->setAlignment(Qt::AlignCenter);

            //创建一个水平布局 把四个组件放进去
            QHBoxLayout *redwhiteLayout = new QHBoxLayout;
            //addStretch的作用相当于弹簧，在四个组件前和后各加一个弹簧，就可以使四个组件紧凑的排在屏幕中心
            redwhiteLayout->addStretch(1);
            redwhiteLayout->addWidget(redRectLabel);
            redwhiteLayout->addWidget(redLabel);
            redwhiteLayout->addWidget(whiteRectLabel);
            redwhiteLayout->addWidget(whiteLabel);
            redwhiteLayout->addStretch(1);

        // 创建一个布局把整个屏幕放进去
        QVBoxLayout *mainLayout = new QVBoxLayout(this);
        mainLayout->addWidget(dateTimeLabel, 0, Qt::AlignTop | Qt::AlignHCenter);
        mainLayout->addLayout(CenterLayout);
        mainLayout->addLayout(redwhiteLayout);

    }


protected:
    //每秒刷新画图
    void paintEvent(QPaintEvent *event) override {
        Q_UNUSED(event);
        QPainter* tempPainter = new QPainter(this);

        //画6个正方形表盘

        //第一个正方形表盘,aLabel,D层

        //调整画笔粗细
        int pen_width=this->width()/200;
        QPen pen;
        pen.setWidth(pen_width);
        tempPainter->setPen(pen); // 将画笔应用到painter上
        //画外层,四个参数分别为矩形起点xy，长，宽
        //定义正方形表盘边长
        int length = this->width()/6;
        //定义表盘起点
        int squ1_x1 = ((this->width()/3)/2)-(length/2)+pen_width;
        int squ1_y1 = aLabel->pos().y()-length-pen_width-5;

        //画刷。填充几何图形的调色板，由颜色和填充风格组成
        QBrush brush;
        brush.setColor(QColor(105,105,105,120));
        brush.setStyle(Qt::SolidPattern);
        tempPainter->setBrush(brush);

        //画表盘
        tempPainter->drawRect(squ1_x1, squ1_y1, length, length);

        //画中心圆圈
        //定义圆的直径
        int cir1_dia = this->width()/25;
        //画圆圈，画圆可以看作是先画一个矩形 然后画这个矩形的内切圆 所以四个参数与上条一致
        //定义矩形起点
        int cir1_x1 = squ1_x1+length/2-cir1_dia/2;
        int cir1_y1 = squ1_y1+length/2-cir1_dia/2;
        //调整画笔
        pen.setWidth(1);
        pen.setColor(QColor(0,0,255,255));
        tempPainter->setPen(pen);
        //画刷。填充几何图形的调色板，由颜色和填充风格组成
        brush.setColor(QColor(255,0,0,120));
        brush.setStyle(Qt::SolidPattern);
        tempPainter->setBrush(brush);
        //画圆
        //定义圆圈偏移量，范围为-10到10
        int cir1_offset = qrand() % 21 - 10;
        //定义圆圈中心线起点与终点
        double cir1_centerline_x1 = cir1_x1+cir1_dia/2;
        double cir1_centerline_y1 = cir1_y1-5*pen_width;
        double cir1_centerline_x2 = cir1_centerline_x1;
        double cir1_centerline_y2 = cir1_centerline_y1 + cir1_dia + 2*5*pen_width;

        if (cir1_offset == 0) {
            tempPainter->drawEllipse(cir1_x1, cir1_y1, cir1_dia,cir1_dia);
        } else {
            //如果有中心偏移量，就让圆圈偏移，并画出中心线
            tempPainter->drawEllipse(cir1_x1+cir1_offset, cir1_y1, cir1_dia,cir1_dia);
            tempPainter->setPen(QPen(Qt::yellow, 2, Qt::DashLine));
            tempPainter->drawLine(cir1_centerline_x1, cir1_centerline_y1, cir1_centerline_x2, cir1_centerline_y2);
        }


        //画四条斜线
        //调整线条粗细
        int pen_width2 = this->width()/110;
        pen.setWidth(pen_width2);
        tempPainter->setPen(pen);

        //生成指定范围内的随机数，可以使用取模运算符（%）
        //用于获取煤粉浓度与流速
        // 指定范围为0到9
        int randomRange = 10;

        //定义斜线修正量
        double l1_correction = this->width()/23;

        //第一条斜线
            //确定斜线的起点与终点
            int l11_x1 = squ1_x1+pen_width;
            int l11_y1 = squ1_y1+pen_width;
            int l11_x2 = squ1_x1+l1_correction;
            int l11_y2 = squ1_y1+l1_correction;
            //计算斜线总长
            double l11_length = sqrt(pow((l11_x2-l11_x1),2)+pow(l11_y2-l11_y1,2));

            //获得输入数据：煤粉浓度与流速
            //煤粉浓度
            double l11_pulverized_coal_concentration = qrand() % randomRange;
            //流速
            double l11_flow_rate = qrand() % randomRange;

            //计算煤粉浓度（红线）的长度
            double l11_pulverized_coal_concentration_length = l11_length*(l11_pulverized_coal_concentration/(l11_pulverized_coal_concentration+l11_flow_rate));

            //计算红线终点坐标
            double l11_x_half = (l11_pulverized_coal_concentration_length/l11_length)*(l11_x2-l11_x1)+l11_x1;
            double l11_y_half = (l11_pulverized_coal_concentration_length/l11_length)*(l11_y2-l11_y1)+l11_y1;

            //先绘制红线
            pen.setColor(QColor(255,0,0,255));
            tempPainter->setPen(pen);
            tempPainter->drawLine(l11_x1,l11_y1,l11_x_half,l11_y_half);
            //再绘制白线
            pen.setColor(QColor(255,255,255,255));
            tempPainter->setPen(pen);
            tempPainter->drawLine(l11_x_half,l11_y_half,l11_x2,l11_y2);

    //第二条斜线
            //确定斜线的起点与终点
            int l12_x1 = squ1_x1+length-pen_width;
            int l12_y1 = squ1_y1+pen_width;
            int l12_x2 = l12_x1-l1_correction+pen_width;
            int l12_y2 = l12_y1+l1_correction-pen_width;
            //计算斜线总长
            double l12_length = sqrt(pow((l12_x2-l12_x1),2)+pow(l12_y2-l12_y1,2));

            //获得输入数据：煤粉浓度与流速

            //煤粉浓度
            double l12_pulverized_coal_concentration = qrand() % randomRange;
            //流速
            double l12_flow_rate = qrand() % randomRange;

            //计算煤粉浓度（红线）的长度
            double l12_pulverized_coal_concentration_length = l12_length*(l12_pulverized_coal_concentration/(l12_pulverized_coal_concentration+l12_flow_rate));

            //计算红线终点坐标
            double l12_x_half = (l12_pulverized_coal_concentration_length/l12_length)*(l12_x2-l12_x1)+l12_x1;
            double l12_y_half = (l12_pulverized_coal_concentration_length/l12_length)*(l12_y2-l12_y1)+l12_y1;

            //先绘制红线
            pen.setColor(QColor(255,0,0,255));
            tempPainter->setPen(pen);
            tempPainter->drawLine(l12_x1,l12_y1,l12_x_half,l12_y_half);
            //再绘制白线
            pen.setColor(QColor(255,255,255,255));
            tempPainter->setPen(pen);
            tempPainter->drawLine(l12_x_half,l12_y_half,l12_x2,l12_y2);

        //第三条斜线（右下角开始）
            //确定斜线的起点与终点
            int l13_x1 = squ1_x1+length-pen_width;
            int l13_y1 = squ1_y1+length-pen_width;
            int l13_x2 = l13_x1-l1_correction+pen_width;
            int l13_y2 = l13_y1-l1_correction+pen_width;
            //计算斜线总长
            double l13_length = sqrt(pow((l13_x2-l13_x1),2)+pow(l13_y2-l13_y1,2));

            //获得输入数据：煤粉浓度与流速
            //煤粉浓度
            double l13_pulverized_coal_concentration = qrand() % randomRange;
            //流速
            double l13_flow_rate = qrand() % randomRange;

            //计算煤粉浓度（红线）的长度
            double l13_pulverized_coal_concentration_length = l13_length*(l13_pulverized_coal_concentration/(l13_pulverized_coal_concentration+l13_flow_rate));

            //计算红线终点坐标
            double l13_x_half = (l13_pulverized_coal_concentration_length/l13_length)*(l13_x2-l13_x1)+l13_x1;
            double l13_y_half = (l13_pulverized_coal_concentration_length/l13_length)*(l13_y2-l13_y1)+l13_y1;

            //先绘制红线
            pen.setColor(QColor(255,0,0,255));
            tempPainter->setPen(pen);
            tempPainter->drawLine(l13_x1,l13_y1,l13_x_half,l13_y_half);
            //再绘制白线
            pen.setColor(QColor(255,255,255,255));
            tempPainter->setPen(pen);
            tempPainter->drawLine(l13_x_half,l13_y_half,l13_x2,l13_y2);

        //第四条斜线（左下角开始）
            //确定斜线的起点与终点
            int l14_x1 = squ1_x1+pen_width;
            int l14_y1 = squ1_y1+length-pen_width;
            int l14_x2 = l14_x1+l1_correction-pen_width;
            int l14_y2 = l14_y1-l1_correction+pen_width;
            //计算斜线总长
            double l14_length = sqrt(pow((l14_x2-l14_x1),2)+pow(l14_y2-l14_y1,2));

            //获得输入数据：煤粉浓度与流速
            //煤粉浓度
            double l14_pulverized_coal_concentration = qrand() % randomRange;
            //流速
            double l14_flow_rate = qrand() % randomRange;

            //计算煤粉浓度（红线）的长度
            double l14_pulverized_coal_concentration_length = l14_length*(l14_pulverized_coal_concentration/(l14_pulverized_coal_concentration+l14_flow_rate));

            //计算红线终点坐标
            double l14_x_half = (l14_pulverized_coal_concentration_length/l14_length)*(l14_x2-l14_x1)+l14_x1;
            double l14_y_half = (l14_pulverized_coal_concentration_length/l14_length)*(l14_y2-l14_y1)+l14_y1;

            //先绘制红线
            pen.setColor(QColor(255,0,0,255));
            tempPainter->setPen(pen);
            tempPainter->drawLine(l14_x1,l14_y1,l14_x_half,l14_y_half);
            //再绘制白线
            pen.setColor(QColor(255,255,255,255));
            tempPainter->setPen(pen);
            tempPainter->drawLine(l14_x_half,l14_y_half,l14_x2,l14_y2);


        //再绘制一下第一个表盘边框
        pen.setWidth(pen_width);
        pen.setColor(QColor(0,0,0,255));
        tempPainter->setBrush(Qt::NoBrush);
        tempPainter->setPen(pen);
        tempPainter->drawRect(squ1_x1, squ1_y1, length, length);

        delete tempPainter;
    }



private:
    QLabel *dateTimeLabel;
    QLabel *aLabel, *bLabel, *cLabel, *dLabel, *eLabel, *fLabel;
    QLabel *redRectLabel, *whiteRectLabel;
    QLabel *redLabel, *whiteLabel;

    //顶部标签显示时间
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

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MyWidget widget;
    widget.resize(600, 400); // Set the window size
    widget.show();
    return app.exec();
}
