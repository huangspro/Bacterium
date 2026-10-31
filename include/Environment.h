#ifndef _ENVIRONMENT_H_
#define _ENVIRONMENT_H_


#include "Bacterium.h"
#include "Substance.h"

// a grid in all environment
class Environment{
private:
    Substance* substance;
    Bacterium* bacterium;
    int height, width;
    
public:
    bool has_bacterium;

    Environment(int h, int w);
    void insert_bac(Bacterium *bac);
    void insert_sub(Substance *sub);
    Bacterium* getBac();
    Substance* getSub();
};

#endif
