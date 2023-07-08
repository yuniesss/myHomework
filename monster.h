#ifndef MONSTER_H
#define MONSTER_H
#include "player.h"

class monster
{
public:
    int hp;
    int strength;
    int type;
    player *pl;

    monster(int _hp,int _type,player* pp):hp(_hp),type(_type),pl(pp){
        strength=0;
    }
    void changeStrength(int x){
        this->strength=x;
    }
    void changeHp(int x){
        this->hp=x;
    }
    virtual void move(int x){

    }
};
class monster1: public monster{
public:
    monster1(player* pp):monster(30,1,pp){}
    void move(int x){
        pl->damage(6);
    }
};
class monster2: public monster{
public:
    monster2(player* pp):monster(78,2,pp){}
    void move(int x){
        int tmp=6+this->strength;
        pl->damage(tmp);
        this->strength+=3;
    }
};
class monster3: public monster{
public:
    monster3(player* pp):monster(60,3,pp){}
    void move(int x){
        if(x%3==1){
            pl->changeAgility(-5);
            pl->changeStrength(-5);
        }
        else if(x%3==2){
            pl->changeAgility(-5);
            pl->changeStrength(-5);
        }
        else{
            pl->damage(12);
        }
    }
};
#endif // MONSTER_H
