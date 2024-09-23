#include "user.h"

/*QPushButton自适应背景*/
void Button_Adaptive(QPushButton* BUTTON)
{
    BUTTON->setFlat(true);
    BUTTON->setStyleSheet("QPushButton{color:white; background-color:transparent;}"
                          "QPushButton:hover{border:1px solid #97B6FE; background-color:transparent;}");
}
