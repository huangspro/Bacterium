#ifndef _ENVIRONMENT_H_
#define _ENVIRONMENT_H_


#include "Substance.h"
#include "Bacterium.h"


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

    void step();

    ~Environment();
};

#endif
