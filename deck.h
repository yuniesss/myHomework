#ifndef DECK_H
#define DECK_H
#include <QVector>
#include "monster.h"
#include "player.h"
class card{
public:
    int num;
    int cost;
public:
    card(int _num,int _cost){
        num=_num;
        cost=_cost;
    }
    virtual bool useCard(monster *x,player *y){

    }
};

class attack : public card{
public:
    attack():card(1,1){}
    bool useCard(monster *x,player *y){
        if(this->cost>y->cost){
            return false;
        }
        int tmp=y->strength+6;
        if(x->hp<=tmp){
            x->changeHp(0);
        }
        else{
            x->changeHp(x->hp-tmp);
        }
        y->changeCost(y->cost-this->cost);
        return true;
    }
};

class defend : public card{
public:
    defend():card(2,1){}
    bool useCard(monster *x,player *y){
        if(this->cost>y->cost){
            return false;
        }
        int tmp=y->agility+5;
        y->changeDefend(y->defend+tmp);
        y->changeCost(y->cost-this->cost);
        return true;
    }
};


#endif // DECK_H
