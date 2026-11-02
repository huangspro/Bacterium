#include "World.h"
#include <cstdlib>
#include <ctime>


int main(){
    srand(time(NULL));
    World newWorld = World(10, 10);
    newWorld.init(10);
    newWorld.real_time_info();
    newWorld.draw();
    for (int i = 1; i <= 50; i++) {
        newWorld.step();newWorld.draw();
        newWorld.real_time_info();
    }
    newWorld.draw();
}
