#ifndef _ENVIRONMENT_H_
#define _ENVIRONMENT_H_

#include<iostream>
#include<string>
#include<vector>

class Environment{
private:
    Substance substance;
    bool has_bacterium;
    int height, width;
    
public:
    Environment(int h, int w);
    
};

#endif
