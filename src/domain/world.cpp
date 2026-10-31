#include "World.h"

#include <cstdlib>
#include <ctime>
#include <iostream>


World::World(int h,int w):height(h), width(w) {}

void World::init(int init_bac_num)
{
    int tem = 0;
    for (int x = 0; x < height; x++) {
        std::vector<Environment *> new_line;
        for (int y = 0; y < width; y++) {
            Environment *new_env = new Environment();
            new_line.push_back(new_env);
        }
        grids.push_back(new_line);
    }
    while (tem < init_bac_num) {
        int temx = rand() % height;
        int temy = rand() % width;
        if (!grids[temx][temy]->has_bacterium) {
            Bacterium *newbac = new Bacterium(temx, temy, grids[temx][temy]);
            bac_list.push_back(newbac);
            grids[temx][temy]->insert_bac(newbac);

            tem++;
            bac_num++;
        }
    }
}

void World::real_time_info()
{
    std::cout << "bacterium number: " << bac_num << std::endl << std::flush;
}

void World::diffusion()
{
    for (int x = 0; x < grids.size(); x++) {
        for (int y = 0; y < grids[x].size(); y++) {
            if (grids[x][y])
                break;
        }
    }
}

void World::step()
{
    for (auto i : bac_list) {
        i->step();
        steps++;
        // calculate bac number
        bac_num = 0;
        for (auto x : grids)
            for (auto y : x)
                if (y->has_bacterium)
                    bac_num++;
    }
}

void World::draw()
{
    for (int x = 0; x < grids.size(); x++) {
        for (int y = 0; y < grids[0].size(); y++) {
            if (grids[x][y]->has_bacterium)
                std::cout << "1";
            else
                std::cout << "0";
        }
        std::cout << std::endl;
    }
}

void World::kill(int x, int y)
{
    Environment *tem = grids[x][y];
    if (tem->has_bacterium) {
        if (tem->getBac()->is_alive) {
            bac_num--;
            tem->has_bacterium = false;
            delete tem->getBac();
        }
    }
}

Environment *World::return_env(int x, int y)
{
    return grids[x][y];
}

World::~World()
{
    for (int x = 0; x < grids.size(); x++)
        for (int y = 0; y < grids[0].size(); y++)
            delete grids[x][y];
}
