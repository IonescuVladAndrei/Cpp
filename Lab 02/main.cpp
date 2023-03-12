#include "biblioteca.cpp"

int main()
{
    Biblioteca b1(1976, (char *)"Str. Constantin", (char *)"Mihai Em", (char *)"Bibl B1"), *v = NULL;
    int i, j, an = 9999, size, an_construire;
    char adresa[20], *nume = NULL, *bibliotecar = NULL;
    std::string inTxt;
    std::ifstream myFile("./data/input.txt");

    b1.afisare();
    std::cout << "Nume bibliotecar: " << b1.getBiblitecar() << std::endl;
    std::cout << "Dupa modificare: " << std::endl;
    b1.modif(1976, (char *)"Str. Constantin", (char *)"Ana Maria", (char *)"Bibl B1");
    b1.afisare();
    Biblioteca b2(b1);
    std::cout << "Dupa copiere: " << std::endl;
    b2.afisare();

    if (myFile.is_open())
    {
        myFile >> size;
        v = new Biblioteca[size];
        std::cout << "Vector nesortat: " << std::endl;
        for (i = 0; i < size; i++)
        {
            myFile >> an_construire;
            myFile >> adresa;
            myFile >> inTxt;
            if (nume != NULL)
                delete[] nume;
            nume = new char[inTxt.length() + 1];
            strcpy(nume, inTxt.c_str());
            myFile >> inTxt;
            if (bibliotecar != NULL)
                delete[] bibliotecar;
            bibliotecar = new char[inTxt.length() + 1];
            strcpy(bibliotecar, inTxt.c_str());
            v[i].modif(an_construire, (char *)adresa, (char *)bibliotecar, (char *)nume);
            v[i].afisare();
            if (an > an_construire)
                an = an_construire;
        }
        for (i = 0; i < size - 1; i++)
            for (j = i + 1; j < size; j++)
                if (strcmp(getNume(v[i]), getNume(v[j])) == 1)
                    interschimbare(v[i], v[j]);

        std::cout << "Vector sortat: " << std::endl;
        for (i = 0; i < size; i++)
            v[i].afisare();
        std::cout << "Cele mai vechi biblioteci sunt: " << std::endl;
        for (i = 0; i < size; i++)
            if (getAn(v[i]) == an)
                v[i].afisare();
    }
    else
        std::cout << "Unable to open file" << std::endl;
    return 0;
}