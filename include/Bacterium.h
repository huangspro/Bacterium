#ifndef _BATERIUM_H_
#define _BATERIUM_H_



#include "Substance.h"
#include "World.h"


class World;

class Bacterium{
private:
    Substance *sub;
    double health;
    int x, y;
    bool is_touched;
    double size;
    World *world;

public:
    bool is_alive;

    Bacterium(int x, int y, World *w);
    Bacterium(Bacterium& other);

    void init_sub();  // init cell substance components
    void die();  // when health is below 0, the cell dies
    void move();  // the cell can move
    void divide();  // the cell can divide itself into 2 cells, and reallocate the substance
    void grow();  // the cell can grow its size
    void impair_health(double i);  // health -= i
    void breathe();  // the cell must breathe

    void step();  // one step of the cell, do every thing

    void touched();  // when the cell is touched by other cell, this function will be called

    ~Bacterium();
};

#endif
