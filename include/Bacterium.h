#ifndef _BATERIUM_H_
#define _BATERIUM_H_



#include "Substance.h"

class Bacterium{
private:
    Substance *sub;
    double health;
    int x, y;
    bool is_touched;

public:
    bool is_alive;

    Bacterium(int x, int y);

    void init_sub();
    void die();
    void move();
    Bacterium divide();
    void grow();
    void impair_health(int i);
    void breathe();

    void touched();

    ~Bacterium();
};

#endif
