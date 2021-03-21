#include "widget.h"

//#include <QApplication>
#include "application.h"

int main(int argc, char *argv[])
{
    //QApplication a(argc, argv);
    Application a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
