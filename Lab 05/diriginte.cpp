#include "diriginte.hpp"

Diriginte::Diriginte() : nume_dir(NULL), grupa("")
{
}

Diriginte::Diriginte(char *nume_dir, char grupa[])
{
    this->nume_dir = new char[strlen(nume_dir) + 1];
    strcpy(this->nume_dir, nume_dir);
    strcpy(this->grupa, grupa);
}

Diriginte::Diriginte(const Diriginte &obj)
{
    if (this->nume_dir != NULL)
        delete[] this->nume_dir;
    this->nume_dir = new char[strlen(obj.nume_dir) + 1];
    strcpy(this->nume_dir, obj.nume_dir);
    strcpy(this->grupa, grupa);
}

Diriginte::~Diriginte()
{
    delete[] this->nume_dir;
}

void Diriginte::setNume_dir(char *nume)
{
    if (this->nume_dir != NULL)
        delete[] this->nume_dir;
    this->nume_dir = new char[strlen(nume) + 1];
    strcpy(this->nume_dir, nume);
}

Diriginte &Diriginte::operator=(const Diriginte &obj)
{
    if (this != &obj)
    {
        strcpy(this->grupa, obj.grupa);
        if (this->nume_dir != NULL)
            delete[] this->nume_dir;
        if (obj.nume_dir == NULL)
            this->nume_dir = NULL;
        else
        {
            this->nume_dir = new char[strlen(obj.nume_dir) + 1];
            strcpy(this->nume_dir, obj.nume_dir);
        }
    }
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Diriginte &obj)
{
    out << "\tDiriginte: nume: " << obj.nume_dir << "; grupa: " << obj.grupa;
    return out;
}