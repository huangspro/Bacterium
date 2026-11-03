#ifndef _ENVIRONMENT_H_
#define _ENVIRONMENT_H_

#include "Substance.h"


class Bacterium;

// a grid in all environment
class Environment{
private:
    Substance *sub;
    Bacterium *bac;
    
public:
    bool has_bacterium;

    Environment();
    void insert_bac(Bacterium *bac);
    Bacterium* getBac();
    Substance* getSub();
    void swap(Environment* other);  // swap substance between two environment due to resolution difference
    void delete_bac();

    ~Environment();
};

#endif
