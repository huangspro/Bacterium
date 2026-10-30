#include "Substance.h"

Substance::Substance(std::vector<Substance> all){
    this->all = all;
}

double getCon(std::string name){
    for(auto i:all)if(i.name == name)return i.concentration;
    return -1;
}
