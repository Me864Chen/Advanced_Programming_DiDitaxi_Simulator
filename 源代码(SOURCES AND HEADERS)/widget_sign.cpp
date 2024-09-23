#include <QMessageBox>
#include <QDebug>
#include <QByteArray>
#include <QString>
#include "widget_sign.h"
#include "ui_widget_sign.h"
#include "user.h"

widget_sign::widget_sign(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widget_sign)
{
    ui->setupUi(this);
    this->setWindowTitle("新用户注册");
    this->setFixedSize(900,840);
    this->setWindowIcon(QIcon(":/picture_cub/title_image.jpg"));
    sign_backgroud=new QMovie(":/picture_cub/sign_page.gif");
    ui->sign_label->setMovie(sign_backgroud);
    sign_backgroud->setScaledSize(ui->sign_label->size());
    sign_backgroud->start();
    sign_password_action=new QAction(this);
    sign_password_action->setIcon(QIcon(":picture_cub/password.jpg"));
    ui->new_password->addAction(sign_password_action,QLineEdit::LeadingPosition);
    sign_name_action=new QAction(this);
    sign_name_action->setIcon(QIcon(":picture_cub/name.webp"));
    ui->new_name->addAction(sign_name_action,QLineEdit::LeadingPosition);
    sign_phone_num_action=new QAction(this);
    sign_phone_num_action->setIcon(QIcon(":picture_cub/telephone(1).webp"));
    ui->new_phone->addAction(sign_phone_num_action,QLineEdit::LeadingPosition);
}

widget_sign::~widget_sign()
{
    sign_backgroud->stop();
    delete sign_backgroud;
    delete ui;
}

void widget_sign::clicked_to_sign()  //注册槽
{
    connect(ui->signup,&QPushButton::clicked,this,[=]()
    {
        QString name,password,phone_num;
        name=ui->new_name->text();
        password=ui->new_password->text();
        phone_num=ui->new_phone->text();   //新用户信息读取准备

        /*文件状态准备*/
        /*新用户信息初筛*/
        if((name!=" ")&&(password!=" "))
        {
            FILE* fp;
            fp=fopen("D:/My-qt/two/users.txt","r+");
            if(fp==nullptr)
            {
                perror("fail to open!");
            }
            char temp[30000];
            while (fgets(temp,30000,fp)!=nullptr)
            {
                qDebug("正在检查是否重名......");
                QString dt_name=QString(strtok(temp,":"));
                if(dt_name==name)
                {
                    QMessageBox::critical(this,"错误","用户名已存在");
                    return;
                }
            }
            fclose(fp);

            /*格式化写入用户信息至文档*/
            FILE* fp1;
            fp1=fopen("D:/My-qt/two/users.txt","a+");
            if(fp1==nullptr)
            {
                perror("fail to open!");
            }
            else
            {
                QByteArray qt_name = ui->new_name->text().toLatin1();
                QByteArray qt_pass = ui->new_password->text().toLatin1();
                QByteArray qt_phonenum = ui->new_phone->text().toLatin1();
                char* ptname = qt_name.data();
                char* ptpass = qt_pass.data();
                char* pphone = qt_phonenum.data();
                fputs(ptname,fp);
                fputs(":",fp);
                fputs(ptpass,fp);
                fputs(" ",fp);
                fputs(pphone,fp);
                fputs(" ",fp);
                if(this->gender_confirm==1)  {fputs("男",fp);}
                if(this->gender_confirm==2)  {fputs("女",fp);}
                fputs(" ",fp);
                if(this->ID_confirm==1)
                {
                    fputs("乘客",fp);
                    this->close();
                }
                if(this->ID_confirm==2)
                {
                    fputs("司机",fp);
                    this->close();
                }
                fputs("\n",fp);
                qDebug()<<"写入文件成功";
                QMessageBox::information(this,"finished","注册成功!");
            }
        }
    });
}

void widget_sign::clicked_to_return()  //返回槽
{
    connect(ui->returnTolast,&QPushButton::clicked,this,[=]()
    {
       this->close();
       this->back_to_start();
    });
}

/*身份信息数据化*/
void widget_sign::on_male_clicked()  {gender_confirm=1;}

void widget_sign::on_female_clicked()  {gender_confirm=2;}

void widget_sign::on_passenger_clicked()  {ID_confirm=1;}

void widget_sign::on_driver_clicked()  {ID_confirm=2;}

void widget_sign::widget_sign_process() //注册界面全任务
{
    this->clicked_to_sign();
    this->clicked_to_return();
}
