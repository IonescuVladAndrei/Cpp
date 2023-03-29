#ifndef CULOARE_HPP
#define CULOARE_HPP

#include "Baza.hpp"
#include <iostream>
#include <string.h>

class Culoare:  virtual public Baza
{
  char *culoare;
  
public:
  Culoare();
  Culoare(char *);
  ~Culoare();

  Culoare &operator=(const Culoare&);
  friend std::ostream &operator<<(std::ostream &, const Culoare &);
  void setData(char*);
  void afisare();
  int getDescLength();
};

#endif