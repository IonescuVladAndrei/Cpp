#include "sticla.hpp"

Sticla::Sticla() : Dop(), pret(0), marca(NULL)
{
}

Sticla::Sticla(int diametru, char *tip, int pret, char *marca) : Dop(diametru, tip)
{
    this->pret = pret;
    this->marca = new char[strlen(marca) + 1];
    strcpy(this->marca, marca);
}

Sticla::Sticla(const Sticla &obj) : Dop(obj)
{

    this->pret = pret;
    if (this->marca != NULL)
        delete[] this->marca;
    this->marca = new char[strlen(obj.marca) + 1];
    strcpy(this->marca, obj.marca);
}

Sticla::~Sticla()
{
    delete[] this->tip;
    delete[] this->marca;
}

Sticla &Sticla::operator=(const Sticla &obj)
{
    if (this != &obj)
    {
        this->pret = obj.pret;
        if (this->marca != NULL)
            delete[] this->marca;
        if (obj.marca == NULL)
            this->marca = NULL;
        else
        {
            this->marca = new char[strlen(obj.marca) + 1];
            strcpy(this->marca, obj.marca);
        }
        (Dop &)(*this) = obj;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Sticla &obj)
{
    out << "Sticla pret: " << obj.pret << "\tMarca: ";
    if (obj.marca == NULL)
        out << "NULL";
    else
        out << obj.marca;
    out << (Dop &)obj;
    return out;
}

std::istream &operator>>(std::istream &in, Sticla &obj)
{
    char temp[100];
    in >> (Dop&)obj;
    std::cout << "Introduceti date sticla:\n" << "Pret: ";
    in >> obj.pret;
    std::cout << "\nMarca: ";
    in >> temp;
    obj.marca = new char[sizeof(temp) + 1];
    strcpy(obj.marca, temp);
    std::cin.clear();
    fflush(stdin);
    return(in);
}

int Sticla::getPret()
{
    return this->pret;
}
