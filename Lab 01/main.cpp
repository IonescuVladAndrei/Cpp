#include "angajat.cpp"

int main()
{
    Angajat *v = NULL, temp, a1(57, (char *)"Ion", (char *)"1234567890000", 4560);
    int size, varsta, salariu, i, j, max = 0;
    char nume[20], CNP[14];
    std::ifstream myFile("./data/input.txt");

    std::cout << "Afisare detalii obiect Angajat a1: " << std::endl;
    a1.afisare();

    if (myFile.is_open())
    {
        myFile >> size;
        v = new Angajat[size];
        std::cout << "Vector nesortat: " << std::endl;
        for (i = 0; i < size; i++)
        {
            myFile >> varsta;
            myFile >> nume;
            myFile >> CNP;
            myFile >> salariu;
            v[i].modif(varsta, (char *)nume, (char *)CNP, salariu);
            v[i].afisare();
            if (max < salariu)
                max = salariu;
        }
        
        for (i = 0; i < size - 1; i++)
        {
            for (j = i + 1; j < size; j++)
            {
                if (strcmp(v[i].getNume(), v[j].getNume()) == 1)
                {
                    temp.modif(v[i].getVarsta(), v[i].getNume(), v[i].getCNP(), v[i].getSalariu());
                    v[i].modif(v[j].getVarsta(), v[j].getNume(), v[j].getCNP(), v[j].getSalariu());
                    v[j].modif(temp.getVarsta(), temp.getNume(), temp.getCNP(), temp.getSalariu());
                }
            }
        }

        std::cout << "Vector sortat(dupa nume): " << std::endl;
        for (i = 0; i < size; i++)
            v[i].afisare();

        std::cout << "Angajatul sau angajatii cu salariul max sunt: " << std::endl;
        for (i = 0; i < size; i++)
            if(v[i].getSalariu() == max)
                v[i].afisare();
    }
    else
        std::cout << "Unable to open file" << std::endl;
    delete[] v;
    return 0;
}