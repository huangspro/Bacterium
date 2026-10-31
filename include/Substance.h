#ifndef _SUBSTANCE_H_
#define _SUBSTANCE_H_

#include<string>
#include<map>


class Substance{
public:
    std::map<std::string, double> all;

    Substance();
    void add(std::string name, double con);
    void change(std::string name, double delta);
    double get(std::string name);
};

#endif
