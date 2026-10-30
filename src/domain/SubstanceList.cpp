#include "SubstanceList.h"

SubstanceList::SubstanceList(std::vector<Substance> all){
    this->all = all;
}

double SubstanceList::getCon(std::string name){
    for(auto i:all)if(i.name == name)return i.concentration;
    return -1;
}
