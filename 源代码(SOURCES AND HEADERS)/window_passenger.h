#ifndef WINDOW_PASSENGER_H
#define WINDOW_PASSENGER_H

#include <QMainWindow>
#include "window_taxi.h"
#include "window_person.h"

namespace Ui {
class window_passenger;
}

class window_passenger : public QMainWindow
{
    Q_OBJECT

public:
    explicit window_passenger(QWidget *parent = nullptr);
    ~window_passenger();
    window_taxi *calltaxi_page;
    window_person *person_page;
    void window_passenger_process();

private slots:
    void on_taxi_action_triggered();
    void on_close_triggered();
    void on_person_inf_triggered();

private:
    QPalette p_passenger_page;
    QImage img_passenger_page;
    QBrush* pic_passenger_page;
    Ui::window_passenger *ui;
};

#endif // WINDOW_PASSENGER_H
