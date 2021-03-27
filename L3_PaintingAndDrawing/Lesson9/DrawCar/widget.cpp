#include "widget.h"
#include "ui_widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPen mPen(Qt::black);
    mPen.setWidth(3);
    painter.setPen(mPen);

    /*
        Upper Section
    */
    int startAngle=15*16;
    int spanAngle=150*16; //This is angle span, not the end angle
    QRectF outRect(100,100,200,200);
    QRectF inRect(110,110,180,180);

    //Draw the upper roofs
    painter.drawArc(outRect,startAngle,spanAngle);
    painter.drawArc(inRect,20*16,65*16);
    painter.drawArc(inRect,92*16,68*16);

    //Draw upper vertical Lines
    painter.drawLine(197,110,197,170);
    painter.drawLine(207,110,207,170);

    //Draw low horizontal lines
    painter.drawLine(120,170,195,170);
    painter.drawLine(210,170,285,170);

    /*
        Back Section
    */
    painter.drawLine(105,174,50,179); //Horizontal top
    painter.drawLine(50,179,45,235); //Vertical back


    /*
        Front Section
    */
    painter.drawLine(300,174,390,175); //Horizontal top
    painter.drawLine(390,175,400,235); //Vertical back

    /*
        Tires
    */

    //Frames
    QRectF backTireFrame(90,200,80,80);
    QRectF frontTireFrame(270,200,80,80);
    painter.drawArc(backTireFrame,0,170*16);

    painter.drawArc(frontTireFrame,10*16,170*16);

    //Lower connectors
    painter.drawLine(45,235,93,232); //Back
    painter.drawLine(170,240,270,240); //Middle
    painter.drawLine(350,235,400,235); //Front

    //Back Tire
    painter.drawEllipse(100,210,60,60);
    painter.setBrush(Qt::black);

    painter.drawEllipse(110,220,40,40);
    painter.setBrush(Qt::NoBrush);

    //Front Tire
    painter.drawEllipse(280,210,60,60);
    painter.setBrush(Qt::black);

    painter.drawEllipse(290,220,40,40);
    painter.setBrush(Qt::NoBrush);
}

