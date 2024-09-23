#include "driver_window.h"
#include "ui_central_window.h"

Central_Window::Central_Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Central_Window)
{
    ui->setupUi(this);
}

Central_Window::~Central_Window()
{
    delete ui;
}
