#include "portocale.cpp"
#include "banana.cpp"
#include "nuci.cpp"
#include "morcovi.cpp"
#include "fructe.cpp"

// ca afisare: Morcovi, Nuci, Banana, Portocale

int main()
{
    Fructe **v, *a;
    int i, j, size = 8;
    double suma = 0;
    v = new Fructe *[8];
    v[0] = new Nuci(200, 5);
    v[1] = new Nuci(500, 6);
    v[2] = new Banana(7);
    v[3] = new Banana(6);
    v[4] = new Portocale(3, 10);
    v[5] = new Portocale(5, 15);
    v[6] = new Morcovi(200, 3);
    v[7] = new Morcovi(500, 1);

    std::cout << "Fructe nesortate:" << std::endl;
    for (i = 0; i < size; i++)
        v[i]->afisare();

    for (i = 0; i < size - 1; i++)
        for (j = i + 1; j < size; j++)
            if (v[i]->ord() > v[j]->ord())
            {
                a = v[i];
                v[i] = v[j];
                v[j] = a;
            }

    std::cout << "Fructe sortate:" << std::endl;
    for (i = 0; i < size; i++)
        v[i]->afisare();

    for (i = 0; i < size - 1; i++)
        if (v[i]->ord() == 2)
            suma = suma + v[i]->getPretFinal();
    std::cout << "Costul total al tuturor Portocalelor: " << suma << std::endl;

    for (int i = 0; i < size; i++)
        delete v[i];
    delete[] v;
    return 0;
}
