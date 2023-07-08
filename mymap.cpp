#include "mymap.h"
#include "ui_mymap.h"
#include <QMessageBox>
mymap::mymap(player* pp,QWidget *parent) :
    QWidget(parent),pl(*pp),
    ui(new Ui::mymap)
{
    n=1;
    stateMonster=0;
    ui->setupUi(this);
    ui->label_2->setNum(pl.hp);
    ui->label_4->setNum(pl.potion);
}

mymap::~mymap()
{
    delete ui;
}

void mymap::on_pushButton_3_clicked()
{
    if(this->n==1){
        QMessageBox::information(this,"提示","请先击败前面的怪物");
    }
    else{
        this->close();
        stateMonster=3;
    }
}


void mymap::on_pushButton_2_clicked()
{
    if(this->n==1){
        QMessageBox::information(this,"提示","请先击败前面的怪物");
    }
    else{
        stateMonster=2;
        this->close();
    }
}

void mymap::on_pushButton_clicked()
{
    if(this->n>1){
        QMessageBox::information(this,"提示","您已经击败了这个怪物");
    }
    else{
        stateMonster=1;
        this->close();
    }
}

