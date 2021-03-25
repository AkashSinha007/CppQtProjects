#ifndef WATERTANK_H
#define WATERTANK_H

#include <QWidget>
#include<QTimer>

class WaterTank : public QWidget
{
    Q_OBJECT
public:
    explicit WaterTank(QWidget *parent = nullptr);

signals:
    void normal();  //Green
    void warning(); //Yellow
    void danger();  //Red

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event) override;

    // QWidget interface
public:
    QSize sizeHint() const override;

private:
    int waterHeight; //Coming from Sensor on Tank
    QTimer *timer;

    // QWidget interface
protected:
    void wheelEvent(QWheelEvent *event) override;
};

#endif // WATERTANK_H
