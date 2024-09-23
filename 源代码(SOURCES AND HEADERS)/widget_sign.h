#ifndef WIDGET_SIGN_H
#define WIDGET_SIGN_H

#include <QAction>
#include <QWidget>
#include <QMovie>

namespace Ui {
class widget_sign;
}

class widget_sign : public QWidget
{
    Q_OBJECT

public:
    explicit widget_sign(QWidget *parent = nullptr);
    ~widget_sign();
    void widget_sign_process();

private slots:
    void clicked_to_sign();
    void clicked_to_return();
    void on_male_clicked();
    void on_female_clicked();
    void on_passenger_clicked();
    void on_driver_clicked();

signals:
    void back_to_start();

private:
    int gender_confirm;
    int ID_confirm;
    QMovie* sign_backgroud;
    QAction* sign_password_action;
    QAction* sign_name_action;
    QAction* sign_phone_num_action;
    Ui::widget_sign *ui;
};

#endif // WIDGET_SIGN_H
