#include "keyboardfilter.h"
#include<QKeyEvent>
#include<QDebug>

KeyboardFilter::KeyboardFilter(QObject *parent) : QObject(parent)
{

}

bool KeyboardFilter::eventFilter(QObject *watched, QEvent *event)
{
    if(event->type()==QEvent::KeyPress)
    {
        QKeyEvent *keyEvent=static_cast<QKeyEvent*>(event);
        QString numbers = QString("1234567890");
        if(numbers.indexOf(keyEvent->text())!=-1)
        {
            qDebug()<<"Number Filtered Out";

            return true; //Event Handled, no need to notify the destination

            /*
                In short, if we use return true, lineEdit will not have any
                numeric digits visible inside it.
                If we return false, numeric digits will be visible as slot
                is handling them.
            */
        }
    }
    return QObject::eventFilter(watched,event);
}
