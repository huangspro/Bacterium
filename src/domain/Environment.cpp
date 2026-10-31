#include "Environment.h"

Environment::Environment(int h, int w):height(h), width(w), has_bacterium(false), sunstance(NULL){

}


void Environment::insert_bac(Bacterium *bac);{
    has_bacterium = true;
}

void Environment::insert_sub(Substance *sub){
    has_bacterium = false;
}
