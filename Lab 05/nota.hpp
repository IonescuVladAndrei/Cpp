
#ifndef NOTA_hpp
#define NOTA_HPP

#include <iostream>
#include <cstring>

class Nota
{
protected:
    int *note;
    int nr_note;
public:
    Nota();
    Nota(int*, int);
    Nota(const Nota&);
    ~Nota();
    friend double getMedie(const Nota &);
    Nota& operator=(const Nota&);
    friend std::ostream& operator<<(std::ostream&, const Nota&);
};

#endif