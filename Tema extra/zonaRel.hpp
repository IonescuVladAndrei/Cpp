#ifndef ZONAREL_HPP
#define ZONAREL_HPP

#include <iostream>
#include <cstring>
#include <cmath>
#include <fstream>

class zonaRel
{
  int popRel;
  int popObIndep[5];
  char **intrebare;
  int **votDa; //[nr intrebari][4 categorii de persoane]
  int **votNu;
  int nrIntreb;

public:
  zonaRel();
  zonaRel(int, int *);
  ~zonaRel();
  void afisare();
  void setNrIntreb(int);
  void setVot(int, char *, int *, int *);
  char* getIntrebare(int);
  double getPrezVot(int); 
  double getVotTotalDa(int);
  double getVotTotalNu(int);
  int codZona(); // == 1
};

#endif
