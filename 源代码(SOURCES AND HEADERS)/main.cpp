#include "widget_start.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    widget_start START;
    START.show();
    START.widget_start_process();
    START.log_page->widget_log_process();
    START.sign_page->widget_sign_process();
    START.log_page->driver_page->window_driver_process();
    START.log_page->passenger_page->calltaxi_page->window_taxi_process();
    START.log_page->passenger_page->person_page->window_person_process();
    START.log_page->driver_page->driver_info_page->window_driver_own_process();

    return a.exec();
}
