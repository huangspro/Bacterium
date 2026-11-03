#ifndef WORLD_H
#define WORLD_H

#include <vector>

#include "Environment.h"
#include "Bacterium.h"

class World
{
private:
    std::vector<std::vector<Environment *> > grids;  // each grid contain an env
    std::vector<Bacterium *> bac_list;  // list of bac
    int bac_num = 0;  // number of alive bacterium
    int height, width;
    int steps = 0;

public:
    // global operations
    World(int h, int w);
    void init(int init_bac_num);  // initialize the world
    void step();  // one step of the world
    void real_time_info();  // return current information
    void draw();  // output the grids onto the screen

    // bacterium operations: To avoid loop independence, must put some cell operation here 
    void add_bac(Bacterium *bac);
    void kill(int x, int y);  // kill a cell, release its substance
    void move(int x, int y); 

    // environment operations: To avoid loop independence, must put some environment operation here
    void diffusion();  // simulate substance diffusion process 

    ~World();
};

#endif
