#include "Bacterium.h"

Bacterium::Bacterium(int x, int y):is_alive(true), health(100), is_touched(false), x(x), y(y){}

void Bacterium::die(){
    is_alive = false;
}

void Bacterium::move(){
    int dx, dy;
    if(is_alive){
        x += dx;
        y += dy;
    }
}


void Bacterium::touched(){

}


Bacterium::~Bacterium(){
    delete sub;
}
