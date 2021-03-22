#include "widget.h"
#include "ui_widget.h"
#include<QDebug>
#include<QMouseEvent>
#include<QMenu>

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

void Widget::mousePressEvent(QMouseEvent *event)
{
    qDebug()<<"Widget, Mouse Pressed at "<<event->pos();
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug()<<"Widget, Mouse Released at "<<event->pos();
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    qDebug()<<"Widget, Mouse Moved at "<<event->pos();
}

void Widget::closeEvent(QCloseEvent *event)
{
    qDebug()<<"Widget about to close";
    event->accept();
    //event->ignore();
}

void Widget::contextMenuEvent(QContextMenuEvent *event)
{
    qDebug()<<"ContextMenu Event";
    QMenu *mMenu= new QMenu(this);
    mMenu->addAction(tr("Action1"));
    mMenu->addAction(tr("Action2"));

    //mMenu->popup(event->pos()); //Entire screen is the reference here
    mMenu->popup(mapToGlobal(event->pos())); //Translates widget coordinates to gobal screen coordinates
    qDebug()<<"\nEvent Coordinates: x= "<<event->x()<<" y="<<event->y();

    qDebug()<<"Event reason: "<<event->reason();
    /*Reason Values:
       QContextMenuEvent::Mouse = 0
       QContextMenuEvent::Keyboard = 1
       QContextMenuEvent::Other = 2
    */
}

void Widget::enterEvent(QEvent *event)
{
    qDebug()<<"Enter Event";
}

void Widget::leaveEvent(QEvent *event)
{
    qDebug()<<"Leave Event";
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    qDebug()<<"Key pressed : "<<event->key()<<" : "<<event->text();

    //Shift Key
    if(event->modifiers()&Qt::ShiftModifier)
    {
        qDebug()<<"Shift + "<<event->text();
    }

    //Control Key  //Gives output in unicode
    if(event->modifiers()&Qt::ControlModifier)
    {
        qDebug()<<"Control + "<<event->text();
    }

    //Alt Key
    if(event->modifiers()&Qt::AltModifier)
    {
        qDebug()<<"Alt + "<<event->text();
    }

    //Detect Shift+A ( Professional Way)
    if(event->modifiers()&Qt::ShiftModifier)
    {
        if(event->key()==Qt::Key_A)
        {
            qDebug()<<"Shift + A detected";
        }
    }
}

void Widget::wheelEvent(QWheelEvent *event)
{
    qDebug()<<" Wheel Event Delta: "<<event->delta();
    qDebug()<<"x: "<<event->x()<<", y: "<<event->y();
    qDebug()<<" Orientation : "<<event->orientation();
}

void Widget::resizeEvent(QResizeEvent *event)
{
    qDebug()<<"Widget Resized, old size: "<<event->oldSize();
    qDebug()<<" new size: "<<event->size();
}

void Widget::paintEvent(QPaintEvent *event)
{
    qDebug()<<"Paint Event Triggered";
}


