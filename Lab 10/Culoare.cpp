#include "Culoare.hpp"

Culoare::Culoare() : culoare(NULL)
{
}

Culoare::Culoare(char *culoare)
{
    this->culoare = new char[strlen(culoare) + 1];
    strcpy(this->culoare, culoare);
}

Culoare::~Culoare()
{
    delete[] this->culoare;
}

void Culoare::setData(char *culoare)
{
    if (this->culoare != NULL)
        delete[] this->culoare;
    this->culoare = new char[strlen(culoare) + 1];
    strcpy(this->culoare, culoare);
}

Culoare &Culoare::operator=(const Culoare &obj)
{
    if (this != &obj)
    {
        if (this->culoare != NULL)
            delete[] this->culoare;
        if (obj.culoare == NULL)
            this->culoare = NULL;
        else
        {
            this->culoare = new char[strlen(obj.culoare) + 1];
            strcpy(this->culoare, obj.culoare);
        }
    }
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Culoare &obj)
{
    out << "\n\tCuloare: " << obj.culoare;
    return out;
}

void Culoare::afisare()
{
    std::cout << "\n\tCuloare: " << this->culoare;
}

int Culoare::getDescLength()
{
    return 0;
}