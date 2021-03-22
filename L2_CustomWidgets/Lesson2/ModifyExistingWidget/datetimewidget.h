#ifndef DATETIMEWIDGET_H
#define DATETIMEWIDGET_H

#include <QWidget>
#include<QDate>
#include<QLabel>
#include<QTimer>

class DateTimeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DateTimeWidget(QWidget *parent = nullptr);

private:
    QTimer * timer;
    QLabel * labelTop;   //Date
    QLabel * labelBottom;  //Time
    QString dateString;
    QString timeString;


signals:

public slots:
    void updateTime();


};

#endif // DATETIMEWIDGET_H
