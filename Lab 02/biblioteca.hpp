#ifndef BIBLIOTECA_HPP
#define BIBLIOTECA_HPP

#include <iostream>
#include <cstring>
#include <fstream>

class Biblioteca
{
  int an_construire;
  char adresa[20];
  char *nume;
  char *bibliotecar;

public:
  Biblioteca();                            // constructor fara parametri
  Biblioteca(int, char[], char *, char *); // constructor cu parametri
  Biblioteca(const Biblioteca &);          // constructor de copiere
  ~Biblioteca();                           // destructorul

  void afisare() const;                    // afiseaza atributele clasei
  void modif(int, char *, char *, char[]); // modifica atributele clasei
  char *getBiblitecar() const;
  friend int getAn(const Biblioteca &);                   // returneaza vechimea obiectului apelat
  friend void interschimbare(Biblioteca &, Biblioteca &); // interschimba valorile dintre 2
  friend char *getNume(const Biblioteca &);
};

#endif