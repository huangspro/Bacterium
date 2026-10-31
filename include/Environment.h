#ifndef _ENVIRONMENT_H_
#define _ENVIRONMENT_H_


#include "Bacterium.h"
#include "Substance.h"

// a grid in all environment
class Environment{
private:
    Substance* sub;
    Bacterium *bac;
    
public:
    bool has_bacterium;

    Environment();
    void insert_bac(Bacterium *bac);
    Bacterium* getBac();
    Substance* getSub();
    ~Environment();
};

#endif
