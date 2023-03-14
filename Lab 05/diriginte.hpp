#ifndef DIRIGINTE_HPP
#define DIRIGINTE_HPP

#include <iostream>
#include <cstring>

class Diriginte
{
protected:
    char *nume_dir;
    char grupa[7];

public:
    Diriginte();
    Diriginte(char *, char[]);
    Diriginte(const Diriginte &);
    ~Diriginte();

    void setNume_dir(char *);
    Diriginte &operator=(const Diriginte &);
    friend std::ostream &operator<<(std::ostream &, const Diriginte &);
};

#endif