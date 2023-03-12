class Angajat{
  int varsta;
  char nume[20];
  char CNP[14];
  int salariu;
public:
  Angajat();
  Angajat(int v, char n[],char C[],int s);
  void afisare(); // afiseaza atributele clasei
  void modif(int v,char n[], char C[], int s); // modifica atributele clasei
  int getVarsta(); // returneaza varsta
  char* getNume(); // returneaza numele
  char* getCNP(); // returneaza CNP-ul
  int getSalariu(); // returneaza salariul
};

Cerinte:
1. creati un obiect si apelati metodele (getSalariu, getNume, modif si afisare)
2. creati un vector de Angajati
3. sortati vectorul alfabetic dupa campul nume
4. afisati angajatii cu salariu maxim
