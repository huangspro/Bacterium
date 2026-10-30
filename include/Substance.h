#ifndef _SUBSTANCE_H_
#define _SUBSTANCE_H_

#include<iostream>
#include<string>
#include<vector>

class Substance{
public:
    std::string name;
    double concentration;

    Substance(std::string name, double con);
};

#endif
