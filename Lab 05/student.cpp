#include "student.hpp"

Student::Student() : nume(NULL), Nota(), Diriginte(), Clasa()
{
}
//Student, Nota, Diriginte, Clasa
Student::Student(char *nume, int *note, int nr_note, char *nume_dir, char grupa[], int nr_elevi):Nota(note, nr_note), Diriginte(nume_dir, grupa), Clasa(nr_elevi) 
{
    this->nume = new char[strlen(nume) + 1];
    strcpy(this->nume, nume);
}

Student::Student(const Student& obj):Nota(obj), Diriginte(obj), Clasa(obj)
{
    if(this->nume != NULL)
        delete[] this->nume; 
    this->nume = new char[strlen(obj.nume) + 1];
    strcpy(this->nume, obj.nume);
}

Student::~Student()
{
    delete[] this->nume;
}

Student &Student::operator=(const Student& obj)
{
    if(this != &obj)
    {
        (Nota&)*this = obj;
        (Diriginte&)*this = obj;
        (Clasa&)*this = obj;
        if(this->nume != NULL)
            delete[] this->nume;
        if(obj.nume == NULL)
            this->nume = NULL;
        else
        {
            this->nume = new char[strlen(obj.nume)+1];
            strcpy(this->nume, obj.nume);
        }
    }
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Student& obj)
{
    out << "Student: nume: " << obj.nume << (const Clasa&) obj << (const Diriginte&) obj << (const Nota&) obj;
    return out;
}