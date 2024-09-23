#ifndef WIDGET_START_H
#define WIDGET_START_H

#include <QWidget>
#include <QPushButton>
#include "widget_log.h"
#include "widget_sign.h"
#include "user.h"

namespace Ui {
class widget_start;
}

class widget_start : public QWidget
{
    Q_OBJECT

public:
    explicit widget_start(QWidget *parent = nullptr);
    ~widget_start();
    void widget_start_process();
    widget_log *log_page;
    widget_sign *sign_page;

private slots:
    void start_clicked_to_close();
    void start_clicked_to_sign();
    void start_clicked_to_log();

private:
    QPushButton* SIGN_BUTTON;
    QPushButton* LOG_BUTTON;
    QPushButton* CLOSE_BUTTON;
    QPalette p_start;
    QImage img_start;
    QBrush* pic_start;
    Ui::widget_start *ui;
};

#endif // WIDGET_START_H
