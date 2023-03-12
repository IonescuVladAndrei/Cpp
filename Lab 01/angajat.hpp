#ifndef ANGAJAT_HPP
#define ANGAJAT_HPP

#include <iostream>
#include <cstring>
#include <fstream>

class Angajat
{
    int varsta;
    char nume[20];
    char CNP[14];
    int salariu;

public:
    Angajat();
    Angajat(int v, char n[], char C[], int s);
    void afisare();                               // afiseaza atributele clasei
    void modif(int v, char n[], char C[], int s); // modifica atributele clasei
    int getVarsta();                              // returneaza varsta
    char *getNume();                              // returneaza numele
    char *getCNP();                               // returneaza CNP-ul
    int getSalariu();                             // returneaza salariul
};


#endif