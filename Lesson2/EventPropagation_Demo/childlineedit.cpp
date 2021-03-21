#include "childlineedit.h"
#include<QDebug>
#include<QKeyEvent>

ChildLineEdit::ChildLineEdit(QWidget *parent) : ParentLineEdit(parent)
{

}

void ChildLineEdit::keyPressEvent(QKeyEvent *event)
{
//    qDebug()<<"ChildLineEdit keyPressEvent";
//    ParentLineEdit::keyPressEvent(event);

    qDebug()<<"ChildLineEdit Accepted: "<<event->isAccepted();

    //event->ignore(); //To avoid the event to be propagated to Parent

    if(event->key()==Qt::Key_Delete)
    {
        qDebug()<<"Pressed Delete Key";
        clear();
    }
    else
    {
        ParentLineEdit::keyPressEvent(event);
    }
}
