#ifndef FIGHT_H
#define FIGHT_H

#include <QWidget>
#include <player.h>
#include <monster.h>
#include "deck.h"
#include "mybutton.h"
namespace Ui {
class fight;
}

class fight : public QWidget
{
    Q_OBJECT

public:
    int turn;
    int win;
    player* pl;
    monster* mo;
    explicit fight(player* pp,monster* mm,QWidget *parent = nullptr);
    ~fight();
    void showfight();
    void endturn();
private:
    Ui::fight *ui;
};

#endif // FIGHT_H
