#include "widget.h"
#include "mymap.h"
#include <QApplication>
#include "player.h"
#include "monster.h"
#include "fight.h"
#include "deck.h"
using namespace std;

player p(50,0);
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //title();
    Widget q;
    q.show();
    a.exec();
    if(q.state1==1){

    }
    else if(q.state1==2){
        mymap m(&p);
        m.show();
        a.exec();
        monster* mymonster;
        monster1 m1(&p);
        monster2 m2(&p);
        monster3 m3(&p);
        if(m.stateMonster==1){

            mymonster=&m1;
        }
        else if(m.stateMonster==2){

            mymonster=&m2;
        }
        else if(m.stateMonster==3){

            mymonster=&m3;
        }
        fight f(&p,mymonster);
        f.show();
        a.exec();
        if(f.win==1){
            f.win=-1;
            m.n=2;
            m.show();
            a.exec();
            if(m.stateMonster==1){

                mymonster=&m1;
            }
            else if(m.stateMonster==2){

                mymonster=&m2;
            }
            else if(m.stateMonster==3){

                mymonster=&m3;
            }
            fight f(&p,mymonster);
            f.show();
            a.exec();
            if(f.win==1){
                return 0;
            }
            else return 0;
        }
    }
    return 0;
}
