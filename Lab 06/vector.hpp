#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <cstring>
#include <math.h>
#include <ctime>
#include <cstdlib>
#include "fractie.cpp"
#include "nr_complex.cpp"

template <class X>
class Vector
{
    int dim;
    X *buf;

public:
    Vector();
    Vector(int, X *);
    Vector(const Vector &);
    ~Vector();

    void afisare();
    void sort();
};

#endif