#include "Categorii.hpp"

Categorii::Categorii() : categorie(0)
{
}

Categorii::Categorii(int luni)
{
    if (luni >= 0 && luni <= 12)
        this->categorie = 1;
    else if (luni > 12 && luni <= 36)
        this->categorie = 2;
    else
        this->categorie = 3;
}

Categorii::~Categorii()
{
}

Categorii &Categorii::operator=(const Categorii &obj)
{
    if (this != &obj)
    {
        this->categorie = obj.categorie;
    }
    return *this;
}

void Categorii::setData(int ani, int luni)
{
    int cat = ani * 12 + luni;
    if (cat >= 0 && cat <= 12)
        this->categorie = 1;
    else if (cat > 12 && cat <= 36)
        this->categorie = 2;
    else
        this->categorie = 3;
}

void Categorii::afisare()
{
    if (this->categorie == 1)
        std::cout << "\n\tCategorie: pui(0-1 ani)";
    else if (this->categorie == 2)
        std::cout << "\n\tCategorie: tanara(1-3 ani)";
    else
        std::cout << "\n\tCategorie: matura(1-3 ani)";
}

std::ostream &operator<<(std::ostream &out, const Categorii &obj)
{
    if (obj.categorie == 1)
        out << "\n\tCategorie: pui(0-1 ani)";
    else if (obj.categorie == 2)
        out << "\n\tCategorie: tanara(1-3 ani)";
    else
        out << "\n\tCategorie: matura(1-3 ani)";
    return out;
}

int Categorii::getDescLength()
{
    return 0;
}