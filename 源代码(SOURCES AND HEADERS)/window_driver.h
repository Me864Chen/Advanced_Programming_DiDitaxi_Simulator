#ifndef WINDOW_DRIVER_H
#define WINDOW_DRIVER_H

#include <QMainWindow>
#include "window_driver_own.h"

namespace Ui {
class window_driver;
}

class window_driver : public QMainWindow
{
    Q_OBJECT

public:
    explicit window_driver(QWidget *parent = nullptr);
    ~window_driver();
    void window_driver_process();
    window_driver_own *driver_info_page;

private slots:
    void on_per_info_triggered();
    void on_passenger_ask_triggered();

private:
    char passenger_temp_SUN[1000];
    char passenger_temp_CHEN[1000];
    char passenger_temp_ZHANG[1000];
    char now_temp[1000];

    QString passenger_X;
    QString passenger_Y;
    QString destination_X;
    QString destination_Y;
    QString pickup_time;
    QString dt_now_gender_FLAG;
    QString dt_now_ID_FLAG;
    QString dt_now_name;
    QString dt_now_phonenum;
    QString dt_now_ID;
    QString dt_now_gender;
    QString dt_passenger_name;
    QString dt_passenger_phone_num;
    QString dt_passenger_gender;
    QString dt_passenger_gender_FLAG;
    QPalette p_driver_page;
    QImage img_driver_page;
    QBrush* pic_driver_page;
    QString information;
    Ui::window_driver *ui;
};

#endif // WINDOW_DRIVER_H
