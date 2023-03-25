#include "zonaMil.hpp"

zonaMil::~zonaMil()
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

zonaMil::zonaMil() : popRel(0), intrebare(NULL), votDa(NULL), votNu(NULL), nrIntreb(0)
{
  for (int i = 0; i < 10; i++)
    this->popObIndep[i] = 0;
}

zonaMil::zonaMil(int popRel, int *popObIndep)
{
  this->popRel = popRel;
  for (int i = 9; i > -1; i--)
  {
    this->popObIndep[i] = popObIndep[i];
  }
}

void zonaMil::setNrIntreb(int nrIntreb)
{
  this->nrIntreb = nrIntreb;
  this->intrebare = new char *[nrIntreb];
  this->votDa = new int *[nrIntreb];
  this->votNu = new int *[nrIntreb];
}

void zonaMil::setVot(int nrIntreb, char *intrebare, int *votDa, int *votNu)
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

int zonaMil::codZona()
{
  return 2;
}

double zonaMil::getPrezVot(int nrIntreb)
{
  int sumVot = 0;
  int popEligib = 0;
  for (int i = 0; i < 5; i++) // 5 categorii de persoane eligibile
    sumVot = sumVot + this->votDa[nrIntreb - 1][i] + this->votNu[nrIntreb - 1][i];
  for (int i = 5; i < 10; i++)
    popEligib += this->popObIndep[i];
  return trunc(100 *((double)100 * sumVot / popEligib))/100;
}

double zonaMil::getVotTotalDa(int nrIntreb)
{
  double sumVotDa = 0.0;
  for (int i = 0; i < 5; i++) // 5 categorii de persoane cu drept de vot
    sumVotDa += this->votDa[nrIntreb - 1][i] * (i + 6);
  return sumVotDa;
}

double zonaMil::getVotTotalNu(int nrIntreb)
{
  double sumVotNu = 0.0;
  for (int i = 0; i < 5; i++) // 5 categorii de persoane cu drept de vot
  {
    sumVotNu += this->votNu[nrIntreb - 1][i] * (i + 6);
  }
  return sumVotNu;
}

char* zonaMil::getIntrebare(int nr)
{
  return this->intrebare[nr];
}

void zonaMil::afisare()
{
  std::cout << "Afisare detalii zona militara" << std::endl;
  std::cout << "Populatie totala: " << this->popRel << std::endl;
  for (int i = 9; i > -1; i--)
  {
    std::cout << "\tPopulatie cu drept de vot " << i + 1 << ": " << this->popObIndep[i] << std::endl;
  }

  for (int j = 0; j < this->nrIntreb; j++)
  {
    std::cout << "Intrebare: " << this->intrebare[j] << std::endl;
    std::cout << "Da:\n";
    for (int i = 4; i > -1; i--)
    {
      std::cout << "\tPopulatie care a votat cu drept de vot " << i + 6 << ": " << this->votDa[j][i] << std::endl;
    }
    std::cout << "Nu:\n";
    for (int i = 4; i > -1; i--)
    {
      std::cout << "\tPopulatie care a votat cu drept de vot " << i + 6 << ": " << this->votNu[j][i] << std::endl;
    }
  }
}