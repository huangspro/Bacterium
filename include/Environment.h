#ifndef _ENVIRONMENT_H_
#define _ENVIRONMENT_H_

#include<iostream>
#include<string>
#include<vector>

// a grid in all environment
class Environment{
private:
    Substance substance;
    bool has_bacterium;
    int height, width;
    
public:
    Environment(int h, int w);
    void insert_bac(Bacterium *bac);
    void init_env();
};

#endif
