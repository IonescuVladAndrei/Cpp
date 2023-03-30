#include "vector.cpp"

// pt nr complex merge: <<, =, >
// idem pt fractie
int main()
{
    int vecInt[] = {9888, 213, 32587, 9328, 92348, 10293, 123, 324, 5493, 13213}, i;
    Vector<int> vec_int(sizeof(vecInt) / sizeof(int), vecInt);
    std::cout << "Vector int nesortat(crescator):\n";
    vec_int.afisare();
    vec_int.sort();
    std::cout << "Vector int sortat:\n";
    vec_int.afisare();

    double vecDouble[] = {9888, 213.9, 213.1, 9328.66, 9238.6, 10293, 123.001, 123.01, 5493, 13213};
    Vector<double> vec_double(sizeof(vecDouble) / sizeof(double), vecDouble);
    std::cout << "\n\nVector double nesortat:\n";
    vec_double.afisare();
    vec_double.sort();
    std::cout << "Vector int sortat:\n";
    vec_double.afisare();

    Nr_complex *vecNrComplx;
    srand(time(0));
    int vecNrComplxSize = 10 + (rand() % 5);
    vecNrComplx = new Nr_complex[vecNrComplxSize];
    for (i = 0; i < vecNrComplxSize; i++)
        vecNrComplx[i] = Nr_complex(rand() % 20, rand() % 20);
    Vector<Nr_complex> vec_nrComplx(vecNrComplxSize, vecNrComplx);
    std::cout << "\n\nVector Nr_complex nesortat:\n";
    vec_nrComplx.afisare();
    vec_nrComplx.sort();
    std::cout << "Vector Nr_complex sortat:\n";
    vec_nrComplx.afisare();

    Fractie *vecFractie;
    int vecFractieSize = 10 + (rand() % 5);
    vecFractie = new Fractie[vecFractieSize];
    for (i = 0; i < vecFractieSize; i++)
        vecFractie[i] = Fractie(rand() % 20, 1 + rand() % 19);
    Vector<Fractie> vec_fractie(vecFractieSize, vecFractie);
    std::cout << "\n\nVector Fractie nesortat:\n";
    vec_fractie.afisare();
    vec_fractie.sort();
    std::cout << "Vector Fractie sortat:\n";
    vec_fractie.afisare();
    return 0;
}