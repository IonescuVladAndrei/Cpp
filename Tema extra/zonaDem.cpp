#include "zonaDem.hpp"

zonaDem::~zonaDem()
{
  int i;
  for (i = 0; i < this->nrIntreb; i++)
  {
    delete[] this->intrebare[i];
    delete[] this->votDa[i];
    delete[] this->votNu[i];
  }
  delete[] this->intrebare;
  delete[] this->votDa;
  delete[] this->votNu;
}

zonaDem::zonaDem() : popRel(0), intrebare(NULL), votDa(NULL), votNu(NULL), nrIntreb(0), varstaMin(0)
{
  for (int i = 0; i < 4; i++)
    this->popObIndep[i] = 0;
}

zonaDem::zonaDem(int popRel, int *popObIndep)
{
  this->popRel = popRel;
  for (int i = 3; i > -1; i--)
  {
    this->popObIndep[i] = popObIndep[i];
  }
}

void zonaDem::setNrIntreb(int nrIntreb, int varstaMin)
{
  this->nrIntreb = nrIntreb;
  this->intrebare = new char *[nrIntreb];
  this->votDa = new int *[nrIntreb];
  this->votNu = new int *[nrIntreb];
  if (varstaMin == 14)
    this->varstaMin = 0;
  else if (varstaMin == 20)
    this->varstaMin = 1;
  else if (varstaMin == 40)
    this->varstaMin = 2;
  else
  {
    std::cout << "Varsta minima incorecta! (zona3)\n";
    exit(1);
  }
}

void zonaDem::setVot(int nrIntreb, char *intrebare, int *votDa, int *votNu)
{
  this->intrebare[nrIntreb - 1] = new char[strlen(intrebare) + 1];
  strcpy(this->intrebare[nrIntreb - 1], intrebare);
  this->votDa[nrIntreb - 1] = new int[1];
  this->votNu[nrIntreb - 1] = new int[1];
  this->votDa[nrIntreb - 1][0] = votDa[0]; // suma voturilor este deja data
  this->votNu[nrIntreb - 1][0] = votNu[0];
}

int zonaDem::codZona()
{
  return 3;
}

double zonaDem::getPrezVot(int nrIntreb)
{
  int sumVot = 0;
  sumVot += this->votDa[nrIntreb - 1][0] + this->votNu[nrIntreb - 1][0];
  return trunc(100 *((double)100 * sumVot / this->popRel))/100;
}

char* zonaDem::getIntrebare(int nr)
{
  return this->intrebare[nr];
}

double zonaDem::getVotTotalDa(int nrIntreb)
{
  double sumVotDa = (double)this->votDa[nrIntreb - 1][0];
  return sumVotDa;
}

double zonaDem::getVotTotalNu(int nrIntreb)
{
  double sumVotNu = (double)this->votNu[nrIntreb - 1][0];
  return sumVotNu;
}

void zonaDem::afisare()
{
  std::cout << "Afisare detalii zona democratica" << std::endl;
  std::cout << "Populatie totala: " << this->popRel << std::endl;
  for (int i = 3; i > -1; i--)
  {
    std::cout << "\tPopulatie cu drept de vot " << i + 1 << ": " << this->popObIndep[i] << std::endl;
  }

  for (int j = 0; j < this->nrIntreb; j++)
  {
    std::cout << "Intrebare: " << this->intrebare[j] << std::endl;
    std::cout << "Da:\n";
    std::cout << "\tPopulatie care a votat cu drept de vot: " << this->getVotTotalDa(j + 1) << std::endl;
    std::cout << "Nu:\n";
    std::cout << "\tPopulatie care a votat cu drept de vot " << this->getVotTotalNu(j + 1) << std::endl;
  }
}