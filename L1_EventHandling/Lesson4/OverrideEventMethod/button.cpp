#include "button.h"
#include<QEvent>
#include<QDebug>

Button::Button(QWidget *parent) : QPushButton(parent)
{

}

bool Button::event(QEvent *event)
{
    if(event->type()==QEvent::MouseButtonPress
            ||event->type()==QEvent::MouseButtonDblClick)
    {
        qDebug()<<"Button: mouse press or doubleclick detected";
        //return true;     //If you don't comment out , then slot will not be called
                           /*It means no need for slot associated to be called
                             as it is handled in if condition of event() method itself*/
    }

    return QPushButton::event(event);
}
