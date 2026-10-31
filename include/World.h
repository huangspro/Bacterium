#ifndef WORLD_H
#define WORLD_H

#include "Bacterium.h"
#include "Environment.h"
#include <vector>

class World
{
private:
    std::vector<std::vector<Environment> > grids;
    std::vector<Bacterium *> bac_list;
    int bac_num = 0;

public:
    World();
    void init(int init_bac_num);
    void step();
    void real_time_info();
    void draw();
};

#endif
