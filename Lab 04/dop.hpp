#ifndef DOP_HPP
#define DOP_HPP

#include <iostream>
#include <cstring>

class Dop
{
protected:
    int diametru;
    char *tip;
public:
    Dop();
    Dop(int, char*);
    Dop(const Dop&);
    ~Dop();

    Dop& operator=(const Dop&);
    friend std::istream& operator>>(std::istream&, Dop&);
    friend std::ostream& operator<<(std::ostream&, const Dop&);
    int getDiam();
};

#endif