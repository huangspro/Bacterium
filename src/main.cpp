#include "World.h"


int main(){
    World newWorld = World(100, 100);
    newWorld.init(100);
    newWorld.real_time_info();
    for (int i = 1; i <= 100; i++){
        newWorld.step();
        newWorld.real_time_info();
    }
}
