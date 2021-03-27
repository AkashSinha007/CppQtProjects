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

    /*
        Linear Gradient
    */
    QLinearGradient linearGradient(QPointF(70,20),QPointF(70,170));
    linearGradient.setColorAt(0,Qt::red);
    linearGradient.setColorAt(1,Qt::yellow);

    linearGradient.setColorAt(0.5,Qt::gray);

    //linearGradient.setSpread(QGradient::PadSpread);  //This is default
    //linearGradient.setSpread(QGradient::RepeatSpread);
    linearGradient.setSpread(QGradient::ReflectSpread);

    QBrush mBrush(linearGradient);
    painter.setBrush(mBrush);
    painter.drawRect(20,20,100,300);

    painter.drawLine(QLineF(QPointF(70,20),QPointF(70,170)));

    /*
        Radial Gradient
    */
    QRadialGradient radialGradient(QPointF(280,170),75);
    radialGradient.setColorAt(0,Qt::blue);
    radialGradient.setColorAt(1,Qt::yellow);

    //radialGradient.setSpread(QGradient::ReflectSpread);
    radialGradient.setSpread(QGradient::RepeatSpread);

    QBrush mBrushRad(radialGradient);

    painter.setBrush(mBrushRad);
    painter.drawRect(130,20,300,300);

    /*
        Conical Gradient
    */
    QConicalGradient conicalGradient(QPointF(600,170),90); //Center of the gradient to 90 degree anticlock
    conicalGradient.setColorAt(0,Qt::blue);
    conicalGradient.setColorAt(1,Qt::yellow);

    painter.setBrush(QBrush(conicalGradient));
    painter.drawEllipse(450,20,300,300);
}

