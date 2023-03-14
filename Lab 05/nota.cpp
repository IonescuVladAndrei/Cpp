#include "nota.hpp"

Nota::Nota() : note(NULL), nr_note(0)
{
}

Nota::Nota(int *note, int nr_note)
{
    this->note = new int[nr_note];
    for (int i = 0; i < nr_note; i++)
        this->note[i] = note[i];
    this->nr_note = nr_note;
}

Nota::Nota(const Nota &obj)
{
    note = new int[obj.nr_note];
    for (int i = 0; i < obj.nr_note; i++)
        this->note[i] = obj.note[i];
    this->nr_note = obj.nr_note;
}

Nota::~Nota()
{
    delete[] this->note;
}

double getMedie(const Nota &obj)
{
    int i, rez = 0;
    for (i = 0; i < obj.nr_note; i++)
        rez = rez + obj.note[i];
    return (double)rez / obj.nr_note;
}

std::ostream &operator<<(std::ostream &out, const Nota &obj)
{
    out << "\tNota: nr note: " << obj.nr_note << "; note: ";
    for (int i = 0; i < obj.nr_note; i++)
        out << obj.note[i] << " ";
    out << std::endl;
    return out;
}

Nota &Nota::operator=(const Nota &obj)
{
    if(this != &obj)
    {
        this->nr_note = obj.nr_note;
        if(this->note != NULL)
            delete[] this->note;
        if(obj.note == NULL)
            this->note = NULL;
        else
        {
            this->note = new int[obj.nr_note];
            for(int i = 0;i<obj.nr_note;i++)
                this->note[i] = obj.note[i];
        }
    }
    return *this;
}