#include "vector.hpp"

template <class X>
Vector<X>::Vector() : dim(0), buf(NULL)
{
}

template <class X>
Vector<X>::Vector(int dim, X *buf)
{
    this->dim = dim;
    this->buf = new X[dim];
    for (int i = 0; i < dim; i++)
        this->buf[i] = buf[i];
}

template <class X>
Vector<X>::~Vector()
{
    delete[] this->buf;
}

template <class X>
void Vector<X>::afisare()
{
    std::cout << "Vector: dim: " << this->dim << "\t";
    if (std::is_same<X, Nr_complex>::value || std::is_same<X, Fractie>::value)
        std::cout << "\n";
    for (int i = 0; i < this->dim; i++)
    {
        std::cout << "buf[" << i << "]: " << this->buf[i];
        if (!(std::is_same<X, Nr_complex>::value || std::is_same<X, Fractie>::value))
            std::cout << "  ";
    }
    std::cout << "\n";
}

template <class X>
void Vector<X>::sort()
{
    int i, j;
    for (i = 0; i < this->dim - 1; i++)
        for (j = i + 1; j < this->dim; j++)
        {
            if (this->buf[i] > this->buf[j])
            {
                X temp = this->buf[i];
                this->buf[i] = this->buf[j];
                this->buf[j] = temp;
            }
        }
}

namespace
{
    void test()
    {
        int a1[] = {1, 2};
        Vector<int> v1(2, a1);
        v1.afisare();
        v1.sort();

        double a2[] = {1.0, 2.0};
        Vector<double> v2(2, a2);
        v2.afisare();
        v2.sort();

        Fractie f[2];
        f[0] = Fractie(1, 2);
        f[1] = Fractie(2, 3);
        Vector<Fractie> v3(2, f);
        v3.afisare();
        v3.sort();

        Nr_complex c[2];
        c[0] = Nr_complex(3, 5);
        c[1] = Nr_complex(4, 5);
        Vector<Nr_complex> v4(2, c);
        v4.afisare();
        v4.sort();
    }
}
