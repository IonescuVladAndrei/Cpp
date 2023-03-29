#include "Pisica.hpp"

Pisica::Pisica() : varsta(0), nume(NULL), descriere(NULL), vaccin(0)
{
}

Pisica::Pisica(int varsta, char *nume, char *desc, bool vaccin)
{
    this->varsta = varsta;
    this->vaccin = vaccin;
    this->nume = new char[strlen(nume) + 1];
    strcpy(this->nume, nume);
    this->descriere = new char[strlen(desc) + 1];
    strcpy(this->descriere, desc);
}

Pisica::~Pisica()
{
    delete[] this->descriere;
    delete[] this->nume;
}

void Pisica::setData(int varsta, char *nume, char *desc, bool vaccin)
{
    this->varsta = varsta;
    this->vaccin = vaccin;
    if (this->nume != NULL)
        delete[] this->nume;
    this->nume = new char[strlen(nume) + 1];
    strcpy(this->nume, nume);
    if (this->descriere != NULL)
        delete[] this->descriere;
    this->descriere = new char[strlen(desc) + 1];
    strcpy(this->descriere, desc);
}

std::ostream &operator<<(std::ostream &out, const Pisica &obj)
{
    out << "Pisica: nume: " << obj.nume << " varsta: " << obj.varsta << " luni   vacinata: ";
    if (obj.vaccin)
        out << "da";
    else
        out << "nu";
    out << "\n\tdescriere: " << obj.descriere;
    return out;
}

Pisica &Pisica::operator=(const Pisica &obj)
{
    this->varsta = obj.varsta;
    this->vaccin = obj.vaccin;
    if (this->nume != NULL)
        delete[] this->nume;
    this->nume = new char[strlen(obj.nume) + 1];
    strcpy(this->nume, obj.nume);
    if (this->descriere != NULL)
        delete[] this->descriere;
    this->descriere = new char[strlen(obj.descriere) + 1];
    strcpy(this->descriere, obj.descriere);
    return *this;
}


bool Pisica::operator<(const Pisica &obj)
{
    if (strlen(this->descriere) < strlen(obj.descriere))
        return 1;
    return 0;
}

void Pisica::afisare()
{
    std::cout << "Pisica: Nume: " << this->nume << "\n\tVarsta: " << this->varsta << " luni\n\tVacinata: ";
    if (this->vaccin)
        std::cout << "da";
    else
        std::cout << "nu";
    std::cout << "\n\tdescriere: " << this->descriere;
}

int Pisica::getDescLength()
{
    return strlen(this->descriere);
}