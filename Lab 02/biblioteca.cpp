#include "biblioteca.hpp"

Biblioteca::Biblioteca()
{
  this->an_construire = 0;
  strcpy(this->adresa, "");
  this->bibliotecar = NULL;
  this->nume = NULL;
}

Biblioteca::Biblioteca(int an, char adresa[], char *bibliotecar, char *nume)
{
  this->an_construire = an;
  strcpy(this->adresa, adresa);
  this->bibliotecar = new char[strlen(bibliotecar) + 1];
  strcpy(this->bibliotecar, bibliotecar);
  this->nume = new char[strlen(nume) + 1];
  strcpy(this->nume, nume);
}

Biblioteca::Biblioteca(const Biblioteca &obj)
{
  this->an_construire = obj.an_construire;
  strcpy(this->adresa, obj.adresa);
  this->nume = new char[strlen(obj.nume) + 1];
  strcpy(this->nume, obj.nume);
  this->bibliotecar = new char[strlen(obj.bibliotecar) + 1];
  strcpy(this->bibliotecar, obj.bibliotecar);
}

Biblioteca::~Biblioteca()
{
  delete[] this->nume;
  delete[] this->bibliotecar;
}

void Biblioteca::afisare() const
{
  std::cout << "Nume: " << this->nume << "\t||Adresa: " << this->adresa << "\t||An construire: " << this->an_construire << "\t||Bibliotecar: " << this->bibliotecar << std::endl;
}

void Biblioteca::modif(int an, char *adresa, char *bibliotecar, char *nume)
{
  this->an_construire = an;
  strcpy(this->adresa, adresa);
  if (this->nume != NULL)
    delete[] this->nume;
  this->nume = new char[strlen(nume) + 1];
  strcpy(this->nume, nume);
  if (this->bibliotecar != NULL)
    delete[] this->bibliotecar;
  this->bibliotecar = new char[strlen(bibliotecar) + 1];
  strcpy(this->bibliotecar, bibliotecar);
}

char *Biblioteca::getBiblitecar() const
{
  return this->bibliotecar;
}

int getAn(const Biblioteca &obj)
{
  return obj.an_construire;
}

char* getNume(const Biblioteca &obj)
{
  return obj.nume;
}

void interschimbare(Biblioteca &obj1, Biblioteca &obj2)
{
  
  Biblioteca obj3 (obj1);
  obj1.an_construire = obj2.an_construire;
  strcpy(obj1.adresa, obj2.adresa);
  
  if(obj1.nume != NULL)
    delete[] obj1.nume;
  obj1.nume = new char[strlen(obj2.nume) + 1];
  strcpy(obj1.nume, obj2.nume);

  if(obj1.bibliotecar != NULL)
    delete[] obj1.bibliotecar;
  obj1.bibliotecar = new char[strlen(obj2.bibliotecar) + 1];
  strcpy(obj1.bibliotecar, obj2.bibliotecar);

  obj2.an_construire = obj3.an_construire;
  strcpy(obj2.adresa, obj3.adresa);
  if(obj2.nume != NULL)
    delete[] obj2.nume;
  obj2.nume = new char[strlen(obj3.nume) + 1];
  strcpy(obj2.nume, obj3.nume);

  if(obj2.bibliotecar != NULL)
    delete[] obj2.bibliotecar;
  obj2.bibliotecar = new char[strlen(obj3.bibliotecar) + 1];
  strcpy(obj2.bibliotecar, obj3.bibliotecar);
}
