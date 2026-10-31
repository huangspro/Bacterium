#ifndef _SUBSTANCE_H_
#define _SUBSTANCE_H_

#include<string>

class Substance{
public:
    std::string name;
    double concentration;

    Substance(std::string name, double con);
};

#endif
