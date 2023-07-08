#ifndef MYMAP_H
#define MYMAP_H

#include <QWidget>
#include "player.h"


namespace Ui {
class mymap;
}

class mymap : public QWidget
{
    Q_OBJECT

public:
    int n;
    player pl;
    int stateMonster;
    explicit mymap(player* pp,QWidget *parent = nullptr);
    ~mymap();
    void changePlayer(player *pp){
        pl=*pp;
    }

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::mymap *ui;
};

#endif // MYMAP_H
