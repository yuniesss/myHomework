#ifndef PLAYER_H
#define PLAYER_H


class player{
public:
    int cost;
    int hp;
    int potion;
    int strength;
    int agility;
    int defend;
    player(int _hp,int _potion):hp(_hp),potion(_potion){
        cost=3;
        strength=0;
        agility=0;
        defend=0;
    }
    void changeStrength(int x){
        this->strength=x;
    }
    void changeHp(int x){
        this->hp=x;
    }
    void changeAgility(int x){
        this->agility=x;
    }
    void changeCost(int x){
        this->cost=x;
    }
    void changeDefend(int x){
        this->defend=x;
    }
    void damage(int x){
        if(this->hp+this->defend<=x){
            this->hp=0;
        }
        else if(this->defend<x){
            this->hp-=(x-this->defend);
        }
    }
};

#endif // PLAYER_H
