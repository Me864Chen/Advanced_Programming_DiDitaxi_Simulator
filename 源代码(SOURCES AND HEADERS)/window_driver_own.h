#ifndef WINDOW_DRIVER_OWN_H
#define WINDOW_DRIVER_OWN_H

#include <QMainWindow>

namespace Ui {
class window_driver_own;
}

class window_driver_own : public QMainWindow
{
    Q_OBJECT

public:
    explicit window_driver_own(QWidget *parent = nullptr);
    void window_driver_own_process();
    ~window_driver_own();

private slots:
    void on_backTolast_triggered();
    void on_To_ask_clicked();

signals:
    void back_To_last();

private:
    QString dt_now_gender_FLAG;
    QString dt_now_ID_FLAG;
    QString dt_now_name;
    QString dt_now_phonenum;
    QString dt_now_ID;
    QString dt_now_gender;
    char now_temp[1000];
    QPalette p_driver_own_page;
    QImage img_driver_own_page;
    QBrush* pic_driver_own_page;
    Ui::window_driver_own *ui;
};

#endif // WINDOW_DRIVER_OWN_H
