#include "mybutton.h"
#include <QMessageBox>
mybutton::mybutton(QWidget *parent)
    : QPushButton{parent}
{
    pl=nullptr;
    mo=nullptr;
    num=-1;
}
mybutton::mybutton(int _num, QWidget *parent)
    : QPushButton{parent}
{
    num = _num;
}
void mybutton::usecard(){
    int n=this->num;
    if(handcard[n]->useCard(this->mo,this->pl)==true){
        this->hide();
        if(this->mo->hp==0){
            emit die();
            qDebug()<<"11111111";
        }
    }
    else {
        QMessageBox::information(this,"提示","您的能量不足");
    }
    emit flashfight();
}
