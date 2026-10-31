#ifndef WORLD_H
#define WORLD_H

#include "Bacterium.h"
#include "Environment.h"
#include <vector>

class World
{
private:
    std::vector<std::vector<Environment *> > grids;  // each grid contain an env
    std::vector<Bacterium *> bac_list;  // list of bac
    int bac_num = 0;  // number of alive bacterium

public:
    World();
    void init(int init_bac_num);  // initialize the world
    void step();  // one step of the world
    void real_time_info();  // return current information
    void draw();  // output the grids onto the screen

    void kill(int x, int y);  // kill a cell, release its substance
    Environment *return_env(int x, int y);  // return the env of a grid

    ~World();
};

#endif
