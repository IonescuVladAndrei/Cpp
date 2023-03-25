#include "zonaRel.hpp"

zonaRel::~zonaRel()
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

zonaRel::zonaRel() : popRel(0), intrebare(NULL), votDa(NULL), votNu(NULL), nrIntreb(0)
{
  for (int i = 0; i < 5; i++)
    this->popObIndep[i] = 0;
}

zonaRel::zonaRel(int popRel, int *popObIndep)
{
  this->popRel = popRel;
  for (int i = 4; i > -1; i--)
  {
    this->popObIndep[i] = popObIndep[i];
  }
}

void zonaRel::setNrIntreb(int nrIntreb)
{
  this->nrIntreb = nrIntreb;
  this->intrebare = new char *[nrIntreb];
  this->votDa = new int *[nrIntreb];
  this->votNu = new int *[nrIntreb];
}

void zonaRel::setVot(int nrIntreb, char *intrebare, int *votDa, int *votNu)
{
  this->intrebare[nrIntreb - 1] = new char[strlen(intrebare) + 1];
  strcpy(this->intrebare[nrIntreb - 1], intrebare);
  this->votDa[nrIntreb - 1] = new int[5];
  this->votNu[nrIntreb - 1] = new int[5];
  for (int i = 0; i < 5; i++)
  {
    this->votDa[nrIntreb - 1][i] = votDa[i];
    this->votNu[nrIntreb - 1][i] = votNu[i];
  }
}

int zonaRel::codZona()
{
  return 1;
}

double zonaRel::getPrezVot(int nrIntreb)
{
  int sumVot = 0;
  for (int i = 0; i < 5; i++) // 5 categorii de persoane
    sumVot = sumVot + this->votDa[nrIntreb - 1][i] + this->votNu[nrIntreb - 1][i];
  return trunc(100 *((double)100 * sumVot / this->popRel))/100;
}

double zonaRel::getVotTotalDa(int nrIntreb)
{
  double sumVotDa = 0.0;
  for (int i = 0; i < 5; i++) // 5 categorii de persoane
    sumVotDa = sumVotDa + this->votDa[nrIntreb - 1][i] * ((double)(10 - 2 * (4 - i)) / 10);
  return sumVotDa;
}

double zonaRel::getVotTotalNu(int nrIntreb)
{
  double sumVotNu = 0.0;
  for (int i = 0; i < 5; i++) // 5 categorii de persoane
    sumVotNu = sumVotNu + this->votNu[nrIntreb - 1][i] * ((double)(10 - 2 * (4 - i)) / 10);
  return sumVotNu;
}

char* zonaRel::getIntrebare(int nr)
{
  return this->intrebare[nr];
}

void zonaRel::afisare()
{
  std::cout << "Afisare detalii zona religioasa" << std::endl;
  std::cout << "Populatie totala: " << this->popRel << std::endl;
  for (int i = 4; i > -1; i--)
  {
    std::cout << "\tPopulatie cu drept de vot " << i << ": " << this->popObIndep[i] << std::endl;
  }
  for (int j = 0; j < this->nrIntreb; j++)
  {
    std::cout << "Intrebare: " << this->intrebare[j] << std::endl;
    std::cout << "Da:\n";
    for (int i = 4; i > -1; i--)
    {
      std::cout << "\tPopulatie care a votat cu drept de vot " << i << ": " << this->votDa[j][i] << std::endl;
    }
    std::cout << "Nu:\n";
    for (int i = 4; i > -1; i--)
    {
      std::cout << "\tPopulatie care a votat cu drept de vot " << i << ": " << this->votNu[j][i] << std::endl;
    }
  }
}