#ifndef NOR_FUNCTION_H
#define NOR_FUNCTION_H
#include <QString>
#include <QPushButton>

class user
{
public:
    double FLAG;  //用户标志位
    QString name;
    QString password;
    QString phone_num;
    QString gender;
    QString ID;
};

extern user userlist[10000];

void Button_Adaptive(QPushButton*);
#endif // NOR_FUNCTION_H
