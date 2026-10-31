#include "World.h"

#include <cstdlib>
#include <ctime>
#include <iostream>


World::World() {}

void World::init(int init_bac_num)
{
    int tem = 0;
    for (int x = 0; x < grids.size(); x++) {
        for (int y = 0; y < grids[0].size(); y++) {
            grids[x][y] = Environment();
            if (tem < init_bac_num && rand() % 100 > 50) {
                Bacterium *newbac = new Bacterium(x, y);
                bac_list.push_back(newbac);
                grids[x][y].insert_bac(newbac);

                tem++;
                bac_num++;
            }
        }
    }
}

void World::real_time_info()
{
    std::cout << "bacterium number: " << bac_num << std::endl;
}

void World::step()
{
    for (auto i : bac_list)
        i->step();
}

void World::draw()
{
    for (int x = 0; x < grids.size(); x++) {
        for (int y = 0; y < grids[0].size(); y++) {
            if (grids[x][y].has_bacterium)
                std::cout << "1";
            else
                std::cout << "0";
        }
        std::cout << std::endl;
    }
}
