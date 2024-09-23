#include "window_driver.h"
#include "ui_window_driver.h"
#include <QDebug>
#include <QMessageBox>

window_driver::window_driver(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::window_driver)
{
    ui->setupUi(this);
    this->setWindowTitle("司机端");
    this->setFixedSize(1000,740);
    this->setWindowIcon(QIcon(":/picture_cub/title_image.jpg"));
    p_driver_page=this->palette();
    img_driver_page=QImage(":/picture_cub/wight-yellow.jpg");
    img_driver_page=img_driver_page.scaled(this->size());
    pic_driver_page=new QBrush(img_driver_page);
    p_driver_page.setBrush(QPalette::Window,*pic_driver_page);
    this->setPalette(p_driver_page);
    this->driver_info_page=new window_driver_own;
}

window_driver::~window_driver()
{
    delete ui;
}

void window_driver::on_per_info_triggered()
{
    this->hide();
    connect(ui->per_info,&QAction::triggered,this,[=]()
    {
        this->driver_info_page->show();
    });
}

void window_driver::on_passenger_ask_triggered()
{
    connect(ui->passenger_ask,&QAction::triggered,this,[=]()
    {
        information=ui->past_ask->text();
        /*当前司机身份确认*/
        FILE* fp;
        fp=fopen("D:/My-qt/two/now_user.txt","r+");
        if(fp==nullptr)  {perror("fail to open!");}
        while (fgets(now_temp,1000,fp)!=nullptr)
        {
            dt_now_name=QString(strtok(now_temp,":"));
            dt_now_gender_FLAG=QString(strtok(nullptr," "));
            if(dt_now_gender_FLAG=="male")  {dt_now_gender="男";}
            if(dt_now_gender_FLAG=="female")  {dt_now_gender="女";}
            dt_now_phonenum=QString(strtok(nullptr," "));
            dt_now_ID_FLAG=QString(strtok(nullptr," "));
            if(dt_now_ID_FLAG=="driver")  {dt_now_ID="司机";}
        }
        qDebug()<<dt_now_name<<":"<<dt_now_gender<<" "<<dt_now_phonenum<<" "<<dt_now_ID;

        /*司机接客信息*/
        if(dt_now_name=="p1")
        {
            FILE* fp_SUN;
            fp_SUN=fopen("D:/My-qt/two/sun.txt","r+");
            if(fp==nullptr)  {perror("fail to open!");}
            while (fgets(passenger_temp_SUN,1000,fp_SUN)!=nullptr)
            {
                dt_passenger_name=QString(strtok(passenger_temp_SUN,":"));
                dt_passenger_gender_FLAG=QString(strtok(nullptr," "));
                if(dt_passenger_gender_FLAG=="male")  {dt_passenger_gender="男";}
                if(dt_passenger_gender_FLAG=="female")  {dt_passenger_gender="女";}
                dt_passenger_phone_num=QString(strtok(nullptr," "));
                passenger_X=QString(strtok(nullptr," "));
                passenger_Y=QString(strtok(nullptr," "));
                pickup_time=QString(strtok(nullptr," "));
                destination_X=QString(strtok(nullptr," "));
                destination_Y=QString(strtok(nullptr," "));
            }
            qDebug("订单获取成功");
            QMessageBox::information(this,"订单信息",tr("乘客姓名：%1\n乘客性别：%2\n乘客联系方式：%3\n乘客所在坐标:(%4,%5)\n预计接客时间:%6\n"
                                                    "乘客目的地坐标:(%7,%8)")
                                     .arg(dt_passenger_name).arg(dt_passenger_gender).arg(dt_passenger_phone_num).arg(passenger_X)
                                     .arg(passenger_Y).arg(pickup_time).arg(destination_X).arg(destination_Y));
        }
        if(dt_now_name=="p2")
        {
            FILE* fp_CHEN;
                fp_CHEN=fopen("D:/My-qt/two/chen.txt","r+");
                if(fp==nullptr)  {perror("fail to open!");}
                while (fgets(passenger_temp_CHEN,1000,fp_CHEN)!=nullptr)
                {
                    dt_passenger_name=QString(strtok(passenger_temp_CHEN,":"));
                    dt_passenger_gender_FLAG=QString(strtok(nullptr," "));
                    if(dt_passenger_gender_FLAG=="male")  {dt_passenger_gender="男";}
                    if(dt_passenger_gender_FLAG=="female")  {dt_passenger_gender="女";}
                    dt_passenger_phone_num=QString(strtok(nullptr," "));
                    passenger_X=QString(strtok(nullptr," "));
                    passenger_Y=QString(strtok(nullptr," "));
                    pickup_time=QString(strtok(nullptr," "));
                    destination_X=QString(strtok(nullptr," "));
                    destination_Y=QString(strtok(nullptr," "));
                }
                qDebug("订单获取成功");
                QMessageBox::information(this,"订单信息",tr("乘客姓名：%1\n乘客性别：%2\n乘客联系方式：%3\n乘客所在坐标(%4,%5)\n预计接客时间:%6\n"
                                                        "乘客目的地坐标:(%7,%8)")
                                         .arg(dt_passenger_name).arg(dt_passenger_gender).arg(dt_passenger_phone_num).arg(passenger_X));

        }
        if(dt_now_name=="p3")
        {
            FILE* fp_ZHANG;
            fp_ZHANG=fopen("D:/My-qt/two/zhang.txt","r+");
            if(fp==nullptr)  {perror("fail to open!");}
            while (fgets(passenger_temp_ZHANG,1000,fp_ZHANG)!=nullptr)
            {
                dt_passenger_name=QString(strtok(passenger_temp_ZHANG,":"));
                dt_passenger_gender_FLAG=QString(strtok(nullptr," "));
                if(dt_passenger_gender_FLAG=="male")  {dt_passenger_gender="男";}
                if(dt_passenger_gender_FLAG=="female")  {dt_passenger_gender="女";}
                dt_passenger_phone_num=QString(strtok(nullptr," "));
                passenger_X=QString(strtok(nullptr," "));
                passenger_Y=QString(strtok(nullptr," "));
                pickup_time=QString(strtok(nullptr," "));
                destination_X=QString(strtok(nullptr," "));
                destination_Y=QString(strtok(nullptr," "));
            }
            qDebug("订单获取成功");
            QMessageBox::information(this,"订单信息",tr("乘客姓名：%1\n乘客性别：%2\n乘客联系方式：%3\n乘客所在坐标(%4,%5)\n预计接客时间:%6\n"
                                                    "乘客目的地坐标:(%7,%8)")
                                     .arg(dt_passenger_name).arg(dt_passenger_gender).arg(dt_passenger_phone_num).arg(passenger_X)
                                     .arg(passenger_Y).arg(pickup_time).arg(destination_X).arg(destination_Y));
        }
    });
}

void window_driver::window_driver_process()  //司机端初始界面全任务
{
    this->on_per_info_triggered();
    this->on_passenger_ask_triggered();
    connect(this->driver_info_page,&window_driver_own::back_To_last,this,&window_driver::show);
}
