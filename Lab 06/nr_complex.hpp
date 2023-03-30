#ifndef NR_COMPLEX_HPP
#define NR_COMPLEX_HPP

#include <iostream>
#include <fstream>
#include <math.h>

class Nr_complex
{
    int real;
    int imaginar;

public:
    Nr_complex();
    Nr_complex(int, int);
    Nr_complex(const Nr_complex &);
    ~Nr_complex();

    Nr_complex &operator=(const Nr_complex &);
    friend std::ostream &operator<<(std::ostream &, const Nr_complex &);
    bool operator>(const Nr_complex &);
    void afisareNC();
};

#endif