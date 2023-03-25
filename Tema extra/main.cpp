#include "zonaRel.cpp"
#include "zonaMil.cpp"
#include "zonaDem.cpp"
#include <fstream>
#include <iostream>
#include <string>
#include <limits>
#include <ios>
#include <vector>

int main()
{
  std::ifstream myFile("./data/input.txt");
  std::ofstream myFileO("./data/output.txt");
  std::string inputData;
  int i, j, tipZona, popZ1[5], popZ2[10], popZ3[4], popT, nrIntreb, minAge, pop1Da[5], pop1Nu[5], pop3Da[1], pop3Nu[1];
  char *intreb = NULL;
  if (myFile.is_open() && myFileO.is_open())
  {
    // zona 1
    myFile >> tipZona;
    std::cout << "Creez obiect din zona: " << tipZona << std::endl;
    myFile >> popT;
    std::cout << "Am citit popT: " << popT << std::endl;
    for (j = 4; j > -1; j--)
    {
      myFile >> popZ1[j];
      std::cout << "\tAm citit popT[" << j << "]: " << popZ1[j] << std::endl;
    }
    zonaRel z1(popT, popZ1);

    // zona 2
    myFile >> tipZona;
    std::cout << "Creez obiect din zona: " << tipZona << std::endl;
    myFile >> popT;
    std::cout << "Am citit popT: " << popT << std::endl;
    for (j = 9; j > -1; j--)
    {
      myFile >> popZ2[j];
      std::cout << "\tAm citit popT[" << j << "]: " << popZ2[j] << std::endl;
    }
    zonaMil z2(popT, popZ2);

    // zona 3
    myFile >> tipZona;
    std::cout << "Creez obiect din zona: " << tipZona << std::endl;
    myFile >> popT;
    std::cout << "Am citit popT: " << popT << std::endl;
    for (j = 3; j > -1; j--)
    {
      myFile >> popZ3[j];
      std::cout << "\tAm citit popT[" << j << "]: " << popZ3[j] << std::endl;
    }
    zonaDem z3(popT, popZ3);

    // zona 1 intrebari
    myFile >> nrIntreb;
    z1.setNrIntreb(nrIntreb);
    std::cout << "Am citit nr intrebari: " << nrIntreb << std::endl;
    myFile >> tipZona;
    std::cout << "O sa citesc pentru zona: " << tipZona << std::endl;
    for (i = 0; i < nrIntreb; i++)
    {
      getline(myFile, inputData);
      getline(myFile, inputData);
      std::cout << "Am citit inputData (intrebare): " << inputData << std::endl;
      if (intreb != NULL)
        delete[] intreb;
      intreb = new char[inputData.length() + 1];
      strcpy(intreb, inputData.c_str());
      myFile >> inputData;
      std::cout << "Am citit inputData (Da): " << inputData << std::endl;
      for (j = 4; j > -1; j--)
        myFile >> pop1Da[j];
      myFile >> inputData;
      std::cout << "Am citit inputData (Nu): " << inputData << std::endl;
      for (j = 4; j > -1; j--)
        myFile >> pop1Nu[j];
      z1.setVot(i + 1, intreb, pop1Da, pop1Nu);
    }
    z1.afisare();
    std::cout << "Prez 1 vot = " << z1.getPrezVot(1) << std::endl;
    std::cout << "Vot total 1 da = " << z1.getVotTotalDa(1) << std::endl;
    std::cout << "Vot total 1 nu = " << z1.getVotTotalNu(1) << std::endl;
    std::cout << "Prez 2 vot = " << z1.getPrezVot(2) << std::endl;
    std::cout << "Vot total 2 da = " << z1.getVotTotalDa(2) << std::endl;
    std::cout << "Vot total 2 nu = " << z1.getVotTotalNu(2) << std::endl;
    //scriere in fisier
    if(nrIntreb > 0)
    {
      myFileO << "Zona 1\n";
      for(i=0;i<nrIntreb;i++)
      {
        myFileO << z1.getIntrebare(i)<<"\n";
        if(z1.getVotTotalDa(i+1)>z1.getVotTotalNu(i+1))
          myFileO << "Acceptat ";
        else if(z1.getVotTotalDa(i+1)==z1.getVotTotalNu(i+1))
          myFileO << "Egalitate ";
        else
          myFileO << "Respins ";
        myFileO << z1.getVotTotalDa(i+1) <<"-"<<z1.getVotTotalNu(i+1)<<"\n"<<"Prezenta vot: "<<z1.getPrezVot(i+1)<<"%\n";
      }
    }

    // zona 2 intrebari
    myFile >> nrIntreb;
    z2.setNrIntreb(nrIntreb);
    std::cout << "Am citit nr intrebari: " << nrIntreb << std::endl;
    myFile >> tipZona;
    std::cout << "O sa citesc pentru zona: " << tipZona << std::endl;
    for (i = 0; i < nrIntreb; i++)
    {
      getline(myFile, inputData);
      getline(myFile, inputData);
      std::cout << "Am citit inputData (intrebare): " << inputData << std::endl;
      if (intreb != NULL)
        delete[] intreb;
      intreb = new char[inputData.length() + 1];
      strcpy(intreb, inputData.c_str());
      myFile >> inputData;
      std::cout << "Am citit inputData (Da): " << inputData << std::endl;
      for (j = 4; j > -1; j--)
        myFile >> pop1Da[j];
      myFile >> inputData;
      std::cout << "Am citit inputData (Nu): " << inputData << std::endl;
      for (j = 4; j > -1; j--)
        myFile >> pop1Nu[j];
      std::cout << "main: intreb = " << intreb << std::endl;
      z2.setVot(i + 1, intreb, pop1Da, pop1Nu);
    }
    z2.afisare();
    std::cout << "Prez 1 vot = " << z2.getPrezVot(1) << std::endl;
    std::cout << "Vot total 1 da = " << z2.getVotTotalDa(1) << std::endl;
    std::cout << "Vot total 1 nu = " << z2.getVotTotalNu(1) << std::endl;
    //scriere in fisier
    if(nrIntreb > 0)
    {
      myFileO << "Zona 2\n";
      for(i=0;i<nrIntreb;i++)
      {
        myFileO << z2.getIntrebare(i)<<"\n";
        if(z2.getVotTotalDa(i+1)>z2.getVotTotalNu(i+1))
          myFileO << "Acceptat ";
        else if(z2.getVotTotalDa(i+1)==z2.getVotTotalNu(i+1))
          myFileO << "Egalitate ";
        else
          myFileO << "Respins ";
        myFileO << z2.getVotTotalDa(i+1) <<"-"<<z2.getVotTotalNu(i+1)<<"\n"<<"Prezenta vot: "<<z2.getPrezVot(i+1)<<"%\n";
      }
    }
    // zona 3 intrebari
    myFile >> nrIntreb;
    std::cout << "Am citit nr intrebari: " << nrIntreb << std::endl;
    myFile >> tipZona;
    std::cout << "O sa citesc pentru zona: " << tipZona << std::endl;
    myFile >> tipZona;
    std::cout << "Varsta minima pentru vot: " << tipZona << std::endl;
    z3.setNrIntreb(nrIntreb, tipZona);
    for (i = 0; i < nrIntreb; i++)
    {
      getline(myFile, inputData);
      getline(myFile, inputData);
      std::cout << "Am citit inputData (intrebare): " << inputData << std::endl;
      if (intreb != NULL)
        delete[] intreb;
      intreb = new char[inputData.length() + 1];
      strcpy(intreb, inputData.c_str());
      myFile >> inputData;
      std::cout << "Am citit inputData (Da): " << inputData << std::endl;
      myFile >> pop3Da[0];
      myFile >> inputData;
      std::cout << "Am citit inputData (Nu): " << inputData << std::endl;
      myFile >> pop3Nu[0];
      std::cout << "main: intreb = " << intreb << std::endl;
      z3.setVot(i + 1, intreb, pop3Da, pop3Nu);
    }
    z3.afisare();
    std::cout << "Prez 1 vot = " << z3.getPrezVot(1) << std::endl;
    std::cout << "Vot total 1 da = " << z3.getVotTotalDa(1) << std::endl;
    std::cout << "Vot total 1 nu = " << z3.getVotTotalNu(1) << std::endl;
    //scriere in fisier
    if(nrIntreb > 0)
    {
      myFileO << "Zona 3\n";
      for(i=0;i<nrIntreb;i++)
      {
        myFileO << z3.getIntrebare(i)<<"\n";
        if(z3.getVotTotalDa(i+1)>z3.getVotTotalNu(i+1))
          myFileO << "Acceptat ";
        else if(z3.getVotTotalDa(i+1)==z3.getVotTotalNu(i+1))
          myFileO << "Egalitate ";
        else
          myFileO << "Respins ";
        myFileO << z3.getVotTotalDa(i+1) <<"-"<<z3.getVotTotalNu(i+1)<<"\n"<<"Prezenta vot: "<<z3.getPrezVot(i+1)<<"%\n";
      }
    }
    myFile.close();
  }
  else
    std::cout << "main: Unable to open file!\n";
  return 0;
}