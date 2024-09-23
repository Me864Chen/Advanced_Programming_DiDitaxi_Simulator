#include "window_passenger.h"
#include "ui_window_passenger.h"

window_passenger::window_passenger(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::window_passenger)
{
    ui->setupUi(this);
    this->setWindowTitle("乘客端");
    this->setFixedSize(1000,740);
    this->setWindowIcon(QIcon(":/picture_cub/title_image.jpg"));
    p_passenger_page=this->palette();
    img_passenger_page=QImage(":/picture_cub/passenger_page.jpg");
    img_passenger_page=img_passenger_page.scaled(this->size());
    pic_passenger_page=new QBrush(img_passenger_page);
    p_passenger_page.setBrush(QPalette::Window,*pic_passenger_page);
    this->setPalette(p_passenger_page);

    this->calltaxi_page=new window_taxi;
    this->person_page=new window_person;
}

window_passenger::~window_passenger()
{
    delete ui;
}

void window_passenger::on_taxi_action_triggered()
{
    connect(ui->taxi_action,&QAction::triggered,this,[=]()
    {
        this->hide();
        this->calltaxi_page->show();
    });
}

void window_passenger::on_close_triggered()
{
    connect(ui->close,&QAction::triggered,this,&window_passenger::close);
}

void window_passenger::on_person_inf_triggered()
{
    connect(ui->person_inf,&QAction::triggered,this,[=]()
    {
        this->hide();
        this->person_page->show();
    });
}

void window_passenger::window_passenger_process()  //乘客端初始界面全任务
{
    this->on_taxi_action_triggered();
    this->on_close_triggered();
    connect(this->calltaxi_page,&window_taxi::back_signal,this,&window_passenger::show);
    connect(this->person_page,&window_person::back_signal,this,&window_passenger::show);
}
