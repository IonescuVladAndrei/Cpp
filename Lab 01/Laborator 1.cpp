#include <iostream>
#include <cstring>
using namespace std;

class Jucarie{
    int pret;
    char denumire[20];
public:
    Jucarie()
    { 
    	pret = 0;
    	strcpy(denumire, "");
	}
    Jucarie(int p, char d[])
    {
    	pret = p;
    	strcpy(denumire, d);
	}
	void afisare()
	{
		cout << "Pretul este: " << pret << ". ";
		cout << "Denumirea este: " << denumire << endl;
	}
	void modif(int p,char d[]) // modifica atributele clasei
	{
		pret = p;
		strcpy(denumire, d);
	}
	int getPret() // returneaza pretul
	{
		return pret;
	}
	char* getDenumire() // returneaza denumirea
	{
		return denumire;
	}
};

int main()
{
	Jucarie obj1;
	Jucarie obj2(10,"Urs");
	Jucarie maxim;
	
	obj1.afisare();
	obj2.afisare();
	
	cout << "Am modificat obiectul 1." << endl;
	obj1.modif(30,"Masina");
	obj1.afisare();
	
	cout << "Pretul returnat este: " << obj1.getPret() << endl;
	cout << "Denumirea returnata este: " << obj1.getDenumire() << endl;
	
	Jucarie vector[5];
	vector[0].modif(84,"Papusa");
	vector[1].modif(34,"Balena");
	vector[2].modif(25,"Caine");
	vector[3].modif(65,"Tren");
	vector[4].modif(59,"Avion");
	
	for( int i = 0; i < 5; i ++)
	{
		vector[i].afisare();
	}
	
	cout << "--------Sortat--------\n";
	for( int i = 0; i < 4; i ++)
	{
		for ( int j = i + 1; j < 5; j++)
		{
			if(strcmp(vector[i].getDenumire(),vector[j].getDenumire()) > 0)
			{
				Jucarie aux;
				aux = vector[i];
				vector[i] = vector[j];
				vector[j] = aux;
			}
		}
	}
	
	for( int i = 0; i < 5; i ++)
	{
		vector[i].afisare();
	}
	
	maxim = vector[0];
	
	for( int i = 1; i < 5; i ++)
	{
		if(maxim.getPret() < vector[i].getPret())
		{
			maxim = vector[i];
		}
	}
	cout << "Jucaria cu pretul maxim din vector este:\n";
	maxim.afisare();
	
	return 0;
}