#include "Environment.h"

Environment::Environment(int h, int w):height(h), width(w), has_bacterium(false), sub(NULL){

}


void Environment::insert_bac(Bacterium *bac){
    has_bacterium = true;
    this->bac = bac;
}

void Environment::insert_sub(Substance *sub){
    has_bacterium = false;
    this->sub = sub;
}

Environment::~Environment(){
    delete bac;
    delete sub;
}
