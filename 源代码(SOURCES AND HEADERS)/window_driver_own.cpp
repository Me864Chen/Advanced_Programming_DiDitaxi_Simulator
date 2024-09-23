#include "window_driver_own.h"
#include "ui_window_driver_own.h"
#include <QDebug>
#include <QMessageBox>

window_driver_own::window_driver_own(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::window_driver_own)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/picture_cub/title_image.jpg"));
    p_driver_own_page=this->palette();
    img_driver_own_page=QImage(":/picture_cub/yellow.jpg");
    img_driver_own_page=img_driver_own_page.scaled(this->size());
    pic_driver_own_page=new QBrush(img_driver_own_page);
    p_driver_own_page.setBrush(QPalette::Window,*pic_driver_own_page);
    this->setPalette(p_driver_own_page);
}

window_driver_own::~window_driver_own()
{
    delete ui;
}

void window_driver_own::on_backTolast_triggered()
{
    connect(ui->backTolast,&QAction::triggered,this,[=]()
    {
        this->close();
        this->back_To_last();
    });
}

void window_driver_own::on_To_ask_clicked()
{
    connect(ui->To_ask,&QPushButton::clicked,this,[=]()
    {
        qDebug()<<"用户信息获取成功！";
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
            qDebug()<<dt_now_name<<":"<<dt_now_gender<<" "<<dt_now_phonenum<<" "<<dt_now_ID;
            QMessageBox::information(this,"个人信息",tr("姓名：%1\n性别：%2\n联系方式：%3\n平台注册身份:%4")
                                     .arg(dt_now_name).arg(dt_now_gender).arg(dt_now_phonenum).arg(dt_now_ID));
        }
    });
}

void window_driver_own::window_driver_own_process()  //司机端个人信息查询全任务
{
    this->on_backTolast_triggered();
    this->on_To_ask_clicked();
}
