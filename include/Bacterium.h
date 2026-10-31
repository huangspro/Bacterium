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
    void die();
    void move();
    void touched();
    ~Bacterium();
};

#endif
