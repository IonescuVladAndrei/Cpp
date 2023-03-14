#ifndef STUDENT_HPP
#define STUDENT_HPP

#include "clasa.cpp"
#include "diriginte.cpp"
#include "nota.cpp"

class Student : public Nota, public Diriginte, public Clasa
{
    char *nume;

public:
    Student();
    Student(char *, int *, int, char *, char[], int); // Student, Nota, Diriginte, Clasa
    Student(const Student &);
    ~Student();

    Student &operator=(const Student &);
    friend std::ostream &operator<<(std::ostream &, const Student &);
};

#endif