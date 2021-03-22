#include "childbutton.h"
#include<QDebug>

ChildButton::ChildButton(QWidget *parent) : ParentButton(parent)
{

}

void ChildButton::mousePressEvent(QMouseEvent *event)
{
    qDebug()<<"ParentButton mousePressEvent Called";
    ParentButton::mousePressEvent(event);
}
