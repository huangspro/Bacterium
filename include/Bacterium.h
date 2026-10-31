#ifndef _BATERIUM_H_
#define _BATERIUM_H_



#include "Substance.h"

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

    Bacterium(int x, int y);
    Bacterium(Bacterium& other);

    void init_sub();
    void die();
    void move();
    void divide();
    void grow();
    void impair_health(double i);
    void breathe();

    void step();

    void touched();

    ~Bacterium();
};

#endif
