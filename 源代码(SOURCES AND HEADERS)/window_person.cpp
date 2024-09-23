#include "window_person.h"
#include "ui_window_person.h"
#include <QString>
#include <QMessageBox>
#include <QDebug>
#include <QtGlobal>

window_person::window_person(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::window_person)
{
    ui->setupUi(this);
    this->setWindowTitle("乘客个人信息");
    this->setFixedSize(1000,740);
    this->setWindowIcon(QIcon(":/picture_cub/title_image.jpg"));
    p_person_page=this->palette();
    img_person_page=QImage(":/picture_cub/passenger_person.jpg");
    img_person_page=img_person_page.scaled(this->size());
    pic_person_page=new QBrush(img_person_page);
    p_person_page.setBrush(QPalette::Window,*pic_person_page);
    this->setPalette(p_person_page);
}

window_person::~window_person()
{
    delete ui;
}

void window_person::on_To_ask_clicked()
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
            if(dt_now_ID_FLAG=="passenger")  {dt_now_ID="乘客";}
            qDebug()<<dt_now_name<<":"<<dt_now_gender<<" "<<dt_now_phonenum<<" "<<dt_now_ID;
            QMessageBox::information(this,"个人信息",tr("姓名：%1\n性别：%2\n联系方式：%3\n平台注册身份:%4")
                                     .arg(dt_now_name).arg(dt_now_gender).arg(dt_now_phonenum).arg(dt_now_ID));
        }
    });
}

void window_person::on_returnTolast_triggered()
{
    connect(ui->returnTolast,&QAction::triggered,this,[=]()
    {
        this->close();
        this->back_signal();
    });
}


void window_person::window_person_process()
{
   this->on_To_ask_clicked();
   this->on_returnTolast_triggered();
}
