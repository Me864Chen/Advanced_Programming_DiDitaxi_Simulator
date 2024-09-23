#include "window_taxi.h"
#include "ui_window_taxi.h"
#include <QDebug>
#include <qmath.h>
#include <QtGlobal>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QPushButton>

Driver::Driver(QString NAME,QString CAR_ID,QString PHONE_NUM)
{
    this->name=NAME;
    this->car_ID=CAR_ID;
    this->phone_num=PHONE_NUM;
}
Driver driver[3]=
{
    Driver("张师傅","京A•88888","15328764862"),
    Driver("孙师傅","冀B•34758","15256672280"),
    Driver("陈师傅","湘A•72706","15841621281"),
};

double find_min(double d1,double d2,double d3)
{
    double min=d1;
    if(d2<d1) min=d2;
    if(d3<d2) min=d3;
    return min;
}

window_taxi::window_taxi(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::window_taxi)
{
    ui->setupUi(this);
    ui->setupUi(this);
    this->setWindowTitle("准备出发!");
    this->setFixedSize(800,740);
    this->setWindowIcon(QIcon(":/picture_cub/title_image.jpg"));
    p_taxi_page=this->palette();
    img_taxi_page=QImage(":/picture_cub/taxi.jpg");
    img_taxi_page=img_taxi_page.scaled(this->size());
    pic_taxi_page=new QBrush(img_taxi_page);
    p_taxi_page.setBrush(QPalette::Window,*pic_taxi_page);
    this->setPalette(p_taxi_page);
    QPushButton* TAXI_BUTTON;
    TAXI_BUTTON=ui->confirm_position;
    Button_Adaptive(TAXI_BUTTON);
}

window_taxi::~window_taxi()
{
    delete ui;
}

void window_taxi::on_confirm_position_clicked()
{
    connect(ui->confirm_position,&QPushButton::clicked,this,[&]()
    {
        croweded_degree=rand()%10+1;
        /*乘客位置获取*/
        bool OK_X,OK_Y;
        X_position=ui->X->text().toInt(&OK_X);
        Y_position=ui->Y->text().toInt(&OK_Y);

        /*乘客目的地获取*/
        bool OK_X_D,OK_Y_D;
        X_position_D=ui->X_Destination->text().toInt(&OK_X_D);
        Y_position_D=ui->Y_Destination->text().toInt(&OK_Y_D);
        passenger_distence=sqrt((X_position-X_position_D)*(X_position-X_position_D)
                                +(Y_position-Y_position_D)*(Y_position-Y_position_D));
        passenger_time=passenger_distence/croweded_degree;   //乘客预定路程

        if(OK_X&&OK_Y&&OK_X_D&&OK_Y_D)
        {          
            qDebug()<<"乘客位置获取成功";
            qDebug()<<"乘客目的地获取成功";
            QMessageBox::information(this,"位置获取成功","正在叫车......");

        /*随机生成司机位置*/
            for (int i = 0; i < 3; i++)
            {
                driver[i].driver_X=rand()%100+1;
                driver[i].driver_Y=rand()%100+1;
            }

        /*就近叫车*/
            for (int j = 0; j < 3; j++)
            {
                driver[j].distance=sqrt((X_position-driver[j].driver_X)*(X_position-driver[j].driver_X)
                                  +(Y_position-driver[j].driver_Y)*(Y_position-driver[j].driver_Y));
            }

            goal_distance=find_min(driver[0].distance,driver[1].distance,driver[2].distance);
            goal_time=(int)goal_distance/croweded_degree;  //乘客司机距离
            total_distence=goal_distance+passenger_distence;  //总里程
            total_time=(int)(goal_time+passenger_time);

        /*叫车成功司机信息获取存档*/
            for (int l = 0; l < 3; l++)
            {
                if(qFuzzyCompare(goal_distance,driver[l].distance))
                {
                    qDebug()<<"司机信息获取成功";
                    QMessageBox::information(this,"司机信息",tr("姓名：%1\n车牌：%2\n联系方式：%3\n司机预计%4分钟后到达\n全程预计%5分钟")
                                             .arg(driver[l].name).arg(driver[l].car_ID).arg(driver[l].phone_num).
                                             arg(goal_time).arg(total_time));
                    FILE* f2;
                    f2=fopen("D:/My-qt/two/now_user.txt","r+");
                    if(f2==nullptr)  { perror("fail to open!");}
                    while (fgets(passenger_temp,1000,f2)!=nullptr)
                    {
                        passenger_name=QString(strtok(passenger_temp,":"));
                        passenger_gender_FLAG=QString(strtok(nullptr," "));
                        passsenger_phone_num=QString(strtok(nullptr," "));
                    }
                    if(driver[l].name=="孙师傅")
                    {
                        QFile file2("D:/My-qt/two/sun.txt");
                        if(!file2.open(QIODevice::WriteOnly|QIODevice::Truncate))
                        {
                            return;
                        }
                        QTextStream out(&file2);
                        out<<passenger_name<<":"<<passenger_gender_FLAG<<" "<<passsenger_phone_num<<" "
                          <<X_position<<" "<<Y_position<<" "<<goal_time<<" "<<X_position_D<<" "<<Y_position_D;
                    }
                    if(driver[l].name=="张师傅")
                    {
                        QFile file1("D:/My-qt/two/zhang.txt");
                        if(!file1.open(QIODevice::WriteOnly|QIODevice::Truncate))
                        {
                            return;
                        }
                        QTextStream out(&file1);
                        out<<passenger_name<<":"<<passenger_gender_FLAG<<" "<<passsenger_phone_num<<" "
                          <<X_position<<" "<<Y_position<<" "<<goal_time<<" "<<X_position_D<<" "<<Y_position_D;
                    }
                    if(driver[l].name=="陈师傅")
                    {
                        QFile file3("D:/My-qt/two/chen.txt");
                        if(!file3.open(QIODevice::WriteOnly|QIODevice::Truncate))
                        {
                            return;
                        }
                        QTextStream out(&file3);
                        out<<passenger_name<<":"<<passenger_gender_FLAG<<" "<<passsenger_phone_num<<" "
                          <<X_position<<" "<<Y_position<<" "<<goal_time<<" "<<X_position_D<<" "<<Y_position_D;
                    }
                }
            }
        }
        else
        {
            qDebug()<<"请正确输入:";
            QMessageBox::critical(this,"ERROR!","请重新确认您的有效位置");
        }
    });
    this->close();
}

void window_taxi::on_backTolast_triggered()
{
    connect(ui->backTolast,&QAction::triggered,this,&window_taxi::close);
    this->back_signal();
}

void window_taxi::window_taxi_process()  //乘客端叫车界面全任务
{
    this->on_backTolast_triggered();
    this->on_confirm_position_clicked();
}
