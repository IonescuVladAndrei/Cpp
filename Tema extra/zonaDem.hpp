#ifndef ZONADEM_HPP
#define ZONADEM_HPP

#include <iostream>
#include <cstring>
#include <cmath>

class zonaDem
{  
  int popRel;
  int popObIndep[4];
  char **intrebare;
  int **votDa;                    //[nr intrebari][4 categorii de persoane]    
  int **votNu;
  int nrIntreb;
  int varstaMin;
public:
  zonaDem();
  zonaDem(int, int*);
  ~zonaDem();
  void afisare();
  void setNrIntreb(int, int);
  void setVot(int, char*, int*, int*);
  double getPrezVot(int);
  char* getIntrebare(int);        
  double getVotTotalDa(int);
  double getVotTotalNu(int);
  int codZona();    // == 3
};

#endif