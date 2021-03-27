#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    void drawCar(QPainter *painter);
    void drawCarV2(QPainter *painter,QRectF rect,QColor tireColor);
    Ui::Widget *ui;

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event) override;
};
#endif // WIDGET_H
