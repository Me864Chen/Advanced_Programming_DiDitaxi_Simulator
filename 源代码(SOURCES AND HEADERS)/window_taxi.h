#ifndef WINDOW_TAXI_H
#define WINDOW_TAXI_H

#include <QMainWindow>
#include <QString>
#include "user.h"

namespace Ui {
class window_taxi;
}

class window_taxi : public QMainWindow
{
    Q_OBJECT

public:
    explicit window_taxi(QWidget *parent = nullptr);
    ~window_taxi();
    void window_taxi_process();

private slots:
    void on_confirm_position_clicked();
    void on_backTolast_triggered();

signals:
    void back_signal();

private:
    int X_position_D;
    int Y_position_D;
    int X_position;
    int Y_position;
    int croweded_degree;
    double passenger_time;
    double goal_distance;
    double total_distence;
    double passenger_distence;
    double goal_time;
    double total_time;
    char passenger_temp[1000];
    QString passenger_name;
    QString passsenger_phone_num;
    QString passenger_gender;
    QString passenger_gender_FLAG;
    QPalette p_taxi_page;
    QImage img_taxi_page;
    QBrush* pic_taxi_page;
    Ui::window_taxi *ui;
};

    double find_min(float,float,float);

class Driver
{
public:
     QString name;
     QString car_ID;
     QString phone_num;
     double driver_X;
     double driver_Y;
     double distance;

     Driver(QString,QString,QString);

};
extern Driver driver[3];
#endif // WINDOW_TAXI_H
