#ifndef WIDGET_LOG_H
#define WIDGET_LOG_H

#include <QWidget>
#include <QMovie>
#include <QAction>
#include <QPushButton>
#include "window_driver.h"
#include "window_passenger.h"
#include "user.h"

namespace Ui {
class widget_log;
}

class widget_log : public QWidget
{
    Q_OBJECT

public:
    explicit widget_log(QWidget *parent = nullptr);
    ~widget_log();
    void widget_log_process();
    QString in_name,in_password;
    char temp[30000];
    QString dt_name;
    QString dt_password;
    QString dt_phonenum;
    QString dt_gender;
    QString dt_ID;

    window_driver* driver_page;
    window_passenger* passenger_page;

private slots:
    void clickedto_login();
    void clickedto_return();

signals:
    void back_to_start();

private:
    QPushButton* RETURN_BUTTON;
    QPushButton* LOG_BUTTON;
    QAction* log_password_action;
    QAction* log_name_action;
    QPalette p_log;
    QImage img_log;
    QBrush* pic_log;
    QMovie *m_log;
    Ui::widget_log *ui;
};

void overwriteFile(const QString &filename,const user &now_user);

#endif // WIDGET_LOG_H
