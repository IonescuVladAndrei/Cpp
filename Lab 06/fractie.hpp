#ifndef FRACTIE_HPP
#define FRACTIE_HPP

#include <iostream>
#include <cstring>
#include <fstream>

class Fractie
{
    int a; // numarator
    int b; // numitor
public:
    Fractie();
    Fractie(int, int);
    ~Fractie();

    Fractie &operator=(const Fractie &);
    friend std::ostream &operator<<(std::ostream &, const Fractie &);
    bool operator>(const Fractie &);
};

#endif