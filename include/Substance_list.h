#ifndef _SUBSTANCE_LIST_H_
#define _SUBSTANCE_LIST_H_

#include<iostream>
#include<string>
#include<vector>

#include "Substance.h"

class SubstanceList{
private:
    std::vector<Substance> all;
public:
    SubstanceList(std::vector<Substance> all);
    double getCon(std::string name);
};

#endif
