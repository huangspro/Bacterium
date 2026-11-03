#include "World.h"
#include <cstdlib>
#include <ctime>


int main(){
    srand(time(NULL));
    World newWorld = World(500, 500);
    newWorld.init(10);
    newWorld.real_time_info();

    for (int i = 1; i <= 100; i++) {
        if (i % 1 == 0)
            newWorld.real_time_info();
        newWorld.step();

    }

}
