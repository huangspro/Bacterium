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
    std::cout << "step: " << steps << " --> " << std::flush;
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
    std::vector<Bacterium *> new_bacteria;

    for (auto it = bac_list.begin(); it != bac_list.end();) {
        Bacterium *i = *it;

        // cell steps itself
        i->step();

        // divide cell
        if (bac_num < height * width && rand() % 100 > 50) {
            int dx[] = {-1, 1, 0, 0};
            int dy[] = {0, 0, -1, 1};

            for (int d = 0; d < 4; d++) {
                int nx = i->x + dx[d];
                int ny = i->y + dy[d];

                if (nx >= 0 && nx < height && ny >= 0 && ny < width
                    && !grids[nx][ny]->has_bacterium) {
                    Bacterium *newone = i->divide();

                    if (newone != nullptr) {
                        grids[nx][ny]->insert_bac(newone);
                        new_bacteria.push_back(newone);
                        newone->env = grids[nx][ny];
                    }

                    break;
                }
            }
        }

        // kill a cell
        if (i->health <= 0) {
            i->die();
            delete i;
            it = bac_list.erase(it);
        } else {
            ++it;
        }
    }

    for (auto bac : new_bacteria) {
        bac_list.push_back(bac);
    }

    // calculate bac number
    bac_num = 0;

    for (auto x : grids)
        for (auto y : x)
            if (y->has_bacterium)
                bac_num++;

    steps++;
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
    std::cout << std::endl;
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
