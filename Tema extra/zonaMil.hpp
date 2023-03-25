#ifndef ZONAMIL_HPP
#define ZONAMIL_HPP

#include <iostream>
#include <cstring>
#include <cmath>

class zonaMil
{  
  int popRel;
  int popObIndep[10];
  char **intrebare;
  int **votDa;                    //[nr intrebari][5 categorii de persoane eligibile 6+]    
  int **votNu;
  int nrIntreb;
public:
  zonaMil();
  zonaMil(int, int*);
  ~zonaMil();
  void afisare();
  void setNrIntreb(int);
  void setVot(int, char*, int*, int*);
  double getPrezVot(int);
  char* getIntrebare(int);       
  double getVotTotalDa(int);
  double getVotTotalNu(int);
  int codZona();    // == 2
};

#endif