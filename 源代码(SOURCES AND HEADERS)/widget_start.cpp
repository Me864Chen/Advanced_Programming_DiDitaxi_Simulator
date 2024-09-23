#include "widget_start.h"
#include "ui_widget_start.h"

widget_start::widget_start(QWidget *parent) :  /*页面布局*/
    QWidget(parent),
    ui(new Ui::widget_start)
{
    /*基础布局*/
    ui->setupUi(this);
    this->setWindowTitle("滴滴出行模拟器");
    this->setFixedSize(1400,740);

    /*设置界面背景*/
    this->setAutoFillBackground(true);
    p_start=this->palette();
    img_start=QImage(":/picture_cub/start.jpg");
    img_start=img_start.scaled(this->size());
    pic_start=new QBrush(img_start);
    p_start.setBrush(QPalette::Window,*pic_start);
    this->setPalette(p_start);

    /*设置网页图标*/
    this->setWindowIcon(QIcon(":/picture_cub/title_image.jpg"));

    /*按钮图片自适应*/
    SIGN_BUTTON=ui->sign_button;
    LOG_BUTTON=ui->log_button;
    CLOSE_BUTTON=ui->close_button;
    Button_Adaptive(LOG_BUTTON);
    Button_Adaptive(SIGN_BUTTON);
    Button_Adaptive(CLOSE_BUTTON);

    /*实例化下一级各项任务*/
    this->log_page=new widget_log;  //登录界面
    this->sign_page=new widget_sign;  //注册界面
}

widget_start::~widget_start()
{
    delete ui;
}

void widget_start::start_clicked_to_close()  //关闭槽
{
   connect(ui->close_button,&QPushButton::clicked,this,&widget_start::close);
}

void widget_start::start_clicked_to_sign()  //进入注册槽
{
    connect(ui->sign_button,&QPushButton::clicked,this,[=]()
    {
        this->hide();
        this->sign_page->show();
    });
}

void widget_start::start_clicked_to_log()  //进入登录槽
{
  connect(ui->log_button,&QPushButton::clicked,[=]()
  {
      this->hide();
      this->log_page->show();
  });
}

void widget_start::widget_start_process()  //一级界面全任务
{
    this->start_clicked_to_log();
    this->start_clicked_to_sign();
    this->start_clicked_to_close();
    connect(this->log_page,&widget_log::back_to_start,this,&widget_start::show);
    connect(this->sign_page,&widget_sign::back_to_start,this,&widget_start::show);
}
