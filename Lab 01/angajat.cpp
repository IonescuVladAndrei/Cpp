#include "angajat.hpp"

Angajat::Angajat()
{
    std::cout << "Constructor simplu" << std::endl;
    this->varsta = 0;
    strcpy(this->nume, "");
    strcpy(this->CNP, "");
    this->salariu = 0;
}

Angajat::Angajat(int v, char n[], char C[], int s)
{
    this->varsta = v;
    strcpy(this->nume, n);
    strcpy(this->CNP, C);
    this->salariu = s;
}

void Angajat::afisare()
{
    std::cout << "Nume: " << this->nume << "\tCNP: " << this->CNP << "\tvarsta: " << this->varsta << "\tsalariu: " << this->salariu << std::endl;
}

void Angajat::modif(int v, char n[], char C[], int s)
{
    this->varsta = v;
    strcpy(this->nume, n);
    strcpy(this->CNP, C);
    this->salariu = s;
}

int Angajat::getVarsta()
{
    return this->varsta;
}

int Angajat::getSalariu()
{
    return this->salariu;
}

char* Angajat::getNume()
{
    return this->nume;
}

char* Angajat::getCNP()
{
    return this->CNP;
}
