#ifndef STICLA_HPP
#define STICLA_HPP
#include "dop.cpp"

class Sticla: public Dop{
    int pret;
    char *marca;
public:
    Sticla();
    Sticla(int, char*, int, char*);
    Sticla(const Sticla&);
    ~Sticla();

    Sticla& operator=(const Sticla&);
    friend std::istream& operator>>(std::istream&, Sticla&);
    friend std::ostream& operator<<(std::ostream&, const Sticla&);
    int getPret();
};

#endif
