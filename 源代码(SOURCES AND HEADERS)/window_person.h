#ifndef WINDOW_PERSON_H
#define WINDOW_PERSON_H

#include <QMainWindow>
#include <QString>
#include "user.h"

namespace Ui {
class window_person;
}

class window_person : public QMainWindow
{
    Q_OBJECT

public:
    explicit window_person(QWidget *parent = nullptr);
    ~window_person();
    void window_person_process();

private slots:
    void on_returnTolast_triggered();
    void on_To_ask_clicked();

signals:
    void back_signal();

private:
    QString dt_now_gender_FLAG;
    QString dt_now_ID_FLAG;
    QString dt_now_name;
    QString dt_now_phonenum;
    QString dt_now_ID;
    QString dt_now_gender;
    QPalette p_person_page;
    QImage img_person_page;
    QBrush* pic_person_page;
    char now_temp[1000];
    Ui::window_person *ui;
};

#endif // WINDOW_PERSON_H
