#include <QMessageBox>
#include <QDebug>
#include <QByteArray>
#include <QString>
#include <QFile>
#include <QTextStream>
#include "widget_log.h"
#include "ui_widget_log.h"

user userlist[10000];

/*重写当前用户信息*/
/*用户信息复筛*/
void overwriteFile(const QString &filename,const user &now_user)
{
    QString GENDER,IIDD;
    QFile file(filename);
    if(!file.open(QIODevice::WriteOnly|QIODevice::Truncate))  {return;}  //处理打开文件失败的情况

    QTextStream out(&file);
    if(now_user.ID=="乘客")  {IIDD="passenger";}
    if(now_user.ID=="司机")  {IIDD="driver";}
    if(now_user.gender=="男")  {GENDER="male";}
    if(now_user.gender=="女")  {GENDER="female";}
    out<<now_user.name<<":"<<GENDER<<" "<<now_user.phone_num<<" "<<IIDD<<" ";
    file.close();
}

widget_log::widget_log(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widget_log)
{
    ui->setupUi(this);
    this->setWindowTitle("登录");
    this->setFixedSize(1400,740);

    this->setWindowIcon(QIcon(":/picture_cub/title_image.jpg"));
    p_log=this->palette();
    img_log=QImage(":/picture_cub/yellow.jpg");
    img_log=img_log.scaled(this->size());
    pic_log=new QBrush(img_log);
    p_log.setBrush(QPalette::Window,*pic_log);
    this->setPalette(p_log);
    log_password_action = new QAction(this);
    log_password_action->setIcon(QIcon(":picture_cub/password.jpg"));
    ui->password->addAction(log_password_action,QLineEdit::LeadingPosition);
    log_name_action=new QAction(this);
    log_name_action->setIcon(QIcon(":picture_cub/name.webp"));
    ui->name->addAction(log_name_action,QLineEdit::LeadingPosition);
    RETURN_BUTTON=ui->returntolast;
    LOG_BUTTON=ui->log_in;
    Button_Adaptive(RETURN_BUTTON);
    Button_Adaptive(LOG_BUTTON);       //按钮自适应
    m_log=new QMovie(":/picture_cub/try.gif");
    ui->gif_background->setMovie(m_log);
    m_log->start();

    this->driver_page=new window_driver;
    this->passenger_page=new window_passenger;

}

widget_log::~widget_log()
{
    m_log->stop();
    delete m_log;
    delete ui;
}

void widget_log::clickedto_login()  //登录槽
{
    static int COUNT=0;
    static int count=0;
    QString now_user_Filename="D:/My-qt/two/now_user.txt";
    connect(ui->log_in,&QPushButton::clicked,this,[=]()
    {
        in_name=ui->name->text();
        in_password=ui->password->text();
        if((in_name!=nullptr)&&(in_password!=nullptr))    //遍历已注册用户,用户信息初始化
        {
            FILE* fp;
            fp=fopen("D:/My-qt/two/users.txt","r+");
            if(fp==nullptr)  {perror("fail to open!");}
            while (fgets(temp,30000,fp)!=nullptr)
            {
                qDebug("正在登录中......请稍后......");
                dt_name=QString(strtok(temp,":"));
                dt_password=QString(strtok(nullptr," "));
                dt_phonenum=QString(strtok(nullptr," "));
                dt_gender=QString(strtok(nullptr," "));
                dt_ID=QString(strtok(nullptr,"\n"));
                userlist[count].FLAG=count;
                userlist[count].name=dt_name;
                userlist[count].password=dt_password;
                userlist[count].phone_num=dt_phonenum;
                userlist[count].gender=dt_gender;
                userlist[count].ID=dt_ID;
                qDebug()<<dt_name<<" "<<dt_password;
                count++;
            }
            for (int i = 0; i < count; i++)    //登录判决
            {
                while ((userlist[i].name==in_name)&&(userlist[i].password==in_password))
                {
                    QMessageBox::information(this,"登录成功","欢迎回来！");
                    overwriteFile(now_user_Filename,userlist[i]);
                    this->close();
                    if(userlist[i].ID=="乘客")
                        this->passenger_page->show();
                    if(userlist[i].ID=="司机")
                        this->driver_page->show();
                    COUNT+=1;
                    break;
                }
            }
            if(COUNT==0)
            {
                QMessageBox::critical(this,"错误！","登录失败");
            }
            fclose(fp);
        }
        else
        {
            QMessageBox::critical(this,"错误!","密码或账号为空！");
        }
    });
}

void widget_log::clickedto_return()  //返回槽
{
    connect(ui->returntolast,&QPushButton::clicked,this,[=]()
    {
        this->close();
        this->back_to_start();
    });
}

void widget_log::widget_log_process()  //登录界面全任务
{
    this->clickedto_login();
    this->clickedto_return();
}
