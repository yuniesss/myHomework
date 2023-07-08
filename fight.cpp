#include "fight.h"
#include "mybutton.h"
#include "qmessagebox.h"
#include "ui_fight.h"
attack a1;
defend d1;
card* p1=&a1;
card* p6=&d1;
QVector<card*> deck={p1,p1,p1,p1,p1,p6,p6,p6,p6,p6};
QVector<card*> handcard;
mybutton *hd;

fight::fight(player* pp,monster* mm,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::fight)
{
    win=-1;
    turn=1;
    pl=pp;
    mo=mm;
    ui->setupUi(this);

    //状态的初始化
    if(mo->type==1){
        QFont ft;
        ft.setPointSize(48);
        ui->labelMonster->setText("怪物1");
        ui->labelMonster->setFont(ft);
    }
    else if(mo->type==2){
        QFont ft;
        ft.setPointSize(48);
        ui->labelMonster->setText("怪物2");
        ui->labelMonster->setFont(ft);
    }
    else if(mo->type==3){
        QFont ft;
        ft.setPointSize(48);
        ui->labelMonster->setText("怪物3");
        ui->labelMonster->setFont(ft);
    }
    QFont ft;
    ft.setPointSize(12);
    ui->labelPlayerA2->setNum(pl->agility);
    ui->labelPlayerA2->setFont(ft);
    ui->labelPlayerD2->setNum(pl->defend);
    ui->labelPlayerD2->setFont(ft);
    ui->labelPlayerS2->setNum(pl->strength);
    ui->labelPlayerS2->setFont(ft);
    ui->labelPlayerHp2->setNum(pl->hp);
    ui->labelPlayerHp2->setFont(ft);
    ui->labelPlayerS2_2->setNum(mo->strength);
    ui->labelPlayerS2_2->setFont(ft);
    ui->labelPlayerHp2_2->setNum(mo->hp);
    ui->labelPlayerHp2_2->setFont(ft);
    ft.setPointSize(16);
    ui->labelE2->setNum(pl->cost);
    ui->labelE2->setFont(ft);

    //手牌的初始化
    handcard.clear();
    delete[] hd;
    std::random_shuffle(deck.begin(),deck.end());
    for(int i=4;i>=0;i--){
        handcard.push_back(deck[i+5]);
    }

    hd=new mybutton[handcard.size()];
    for(int i=0;i<handcard.size();i++){
        if(handcard[i]->num==1){
            hd[i].setText("攻击 能量1 造成6点伤害");
            ui->verticalLayout_3->addWidget(&hd[i]);
        }
        else if(handcard[i]->num==2){
            hd[i].setText("防御 能量1 获得5点护甲");
            ui->verticalLayout_3->addWidget(&hd[i]);
        }
        hd[i].num=i;
        hd[i].mo=this->mo;
        hd[i].pl=this->pl;
        hd[i].show();
        connect(&hd[i],&mybutton::clicked,&hd[i],&mybutton::usecard);
        connect(&hd[i],&mybutton::flashfight,this,&fight::showfight);
        connect(&hd[i],&mybutton::die,this,&fight::endturn);
    }
    connect(ui->pushButton,&QPushButton::clicked,this,&fight::endturn);

}

fight::~fight()
{
    delete ui;
}

void fight::showfight(){
    ui->labelPlayerD2->setNum(pl->defend);
    ui->labelPlayerS2->setNum(pl->strength);
    ui->labelPlayerS2_2->setNum(mo->strength);
    ui->labelPlayerHp2_2->setNum(mo->hp);
    ui->labelPlayerHp2->setNum(pl->hp);
    ui->labelE2->setNum(pl->cost);
    ui->labelPlayerA2->setNum(pl->agility);
}

void fight::endturn(){
    this->mo->move(turn);
    pl->changeCost(3);
    pl->changeDefend(0);
    handcard.clear();
    delete[] hd;

    std::random_shuffle(deck.begin(),deck.end());
    for(int ii=4;ii>=0;ii--){
        handcard.push_back(deck[ii+5]);
    }

    hd=new mybutton[handcard.size()];
    for(int ii=0;ii<handcard.size();ii++){
        if(handcard[ii]->num==1){
            hd[ii].setText("攻击 能量1 造成6点伤害");
            ui->verticalLayout_3->addWidget(&hd[ii]);
        }
        else if(handcard[ii]->num==2){
            hd[ii].setText("防御 能量1 获得5点护甲");
            ui->verticalLayout_3->addWidget(&hd[ii]);
        }
        hd[ii].num=ii;
        hd[ii].mo=this->mo;
        hd[ii].pl=this->pl;
        hd[ii].show();
        connect(&hd[ii],&mybutton::clicked,&hd[ii],&mybutton::usecard);
        connect(&hd[ii],&mybutton::flashfight,this,&fight::showfight);
        connect(&hd[ii],&mybutton::die,this,&fight::endturn);
    }
    this->turn++;
    showfight();
    if(pl->hp==0){
        QMessageBox::information(this,"提示","你输了");
        this->close();
        win=0;
    }
    else if(mo->hp==0){
        QMessageBox::information(this,"提示","你赢了");
        this->close();
        win=1;
    }
}
