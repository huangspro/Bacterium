#include "Substance.h"

Substance::Substance(){
}


void Substance::add(std::string name, double con)
{
    all[name] = con;
}

double Substance::get(std::string name)
{
    if (all.find(name) != all.end())
        return all[name];
    return -1;
}

void Substance::change(std::string name, double delta)
{
    if (all.find(name) != all.end())
        all[name] = all[name] + delta > 0?all[name] + delta:0;
}
