#ifndef MYBUTTON_H
#define MYBUTTON_H
#include "deck.h"
#include <QWidget>
#include <QPushButton>
extern QVector<card*> handcard;
class mybutton : public QPushButton
{
    Q_OBJECT
public:
    explicit mybutton(QWidget *parent = nullptr);
    explicit mybutton(int _num,QWidget *parent = nullptr);
    int num;
    void usecard();
    player* pl;
    monster* mo;
signals: void flashfight();
signals: void die();

};

#endif // MYBUTTON_H
