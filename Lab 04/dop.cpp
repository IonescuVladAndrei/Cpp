#include "dop.hpp"

Dop::Dop() : diametru(0), tip(NULL)
{
}

Dop::Dop(int diam, char *tip)
{
    this->diametru = diam;
    this->tip = new char[strlen(tip) + 1];
    strcpy(this->tip, tip);
}

Dop::Dop(const Dop &obj)
{
    this->diametru = obj.diametru;
    if (this->tip != NULL)
        delete[] this->tip;
    this->tip = new char[strlen(obj.tip) + 1];
    strcpy(this->tip, obj.tip);
}

Dop &Dop::operator=(const Dop &obj)
{
    if (this != &obj)
    {
        this->diametru = obj.diametru;
        if (this->tip != NULL)
            delete[] this->tip;
        if (obj.tip == NULL)
            this->tip = NULL;
        else
        {
            this->tip = new char[strlen(obj.tip) + 1];
            strcpy(this->tip, obj.tip);
        }
    }
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Dop &obj)
{
    out << "\tDop diametru: " << obj.diametru << "\ttip: ";
    if (obj.tip == NULL)
        out << "NULL";
    else
        out << obj.tip;
    out << std::endl;
    return out;
}

std::istream &operator>>(std::istream &in, Dop &obj)
{
    char temp[100];
    std::cout << "Introduceti date dop:\n" << "Diametru: ";
    in >> obj.diametru; 
    std::cout << "\nTip: ";
    in >> temp;
    obj.tip = new char[sizeof(temp) + 1];
    strcpy(obj.tip, temp);
    fflush(stdin);
    return(in);
}

Dop::~Dop()
{
    delete[] this->tip;
}

int Dop::getDiam()
{
    return this->diametru;
}