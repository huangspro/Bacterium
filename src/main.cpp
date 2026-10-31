#include "World.h"


int main(){
    World newWorld = World(1000, 1000);
    newWorld.init(100);
    newWorld.real_time_info();
    for (int i = 1; i <= 10; i++){
        newWorld.step();
        newWorld.real_time_info();
    }
}
