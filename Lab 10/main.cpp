#include "Baza.cpp"
#include "Culoare.cpp"
#include "Pisica.cpp"
#include "Categorii.cpp"
#include "PopulareDatePisici.cpp"

int main()
{
    int nrPisici = 300, nrPisiciFisier = 0;
    PopulareDatePisici obj(nrPisici);
    std::ifstream inputCatData("data/CatData.txt");
    std::string inputData;
    int inData = 0, i, j, pisicaVarsta = 0, copieNrPisici = nrPisici, nrZile = 0, sumMancare = 0, top3Values[3] = {0, 0, 0};
    char *pisicaNume = NULL, *pisicaDescriere = NULL, *pisicaCuloare = NULL;
    bool vac = 0;
    Baza ***B = new Baza **[nrPisici];

    // matrice de 3 pe 4 pt top 3 pisici cu desc dif
    Baza ***top3 = new Baza **[3];
    top3[0] = new Baza *[3]; // Pisica, Culoare, Categorie
    top3[1] = new Baza *[3];
    top3[2] = new Baza *[3];

    while (copieNrPisici > nrPisici / 2)
    {
        nrZile++;
        copieNrPisici -= 2;
    }
    std::cout << "Cafeneaua ajunge la jumatate din ocupare in " << nrZile << " zile.\n";

    // pisicile sunt hranite inainte de adoptie si dupa cele 3 salvate, adica in prima zi avem 303 pisici
    //  a doua zi 301 pisici
    copieNrPisici = nrPisici + 3;
    for (i = 0; i < 100; i++)
    {
        sumMancare += copieNrPisici * 100;
        copieNrPisici -= 2;
    }
    std::cout << "Hrana consumata in 100 de zile: " << sumMancare << " grame.\n";

    if (inputCatData.is_open())
    {
        inputCatData >> nrPisiciFisier;
        if (nrPisici != nrPisiciFisier)
        {
            std::cout << "Ceva nu e bine !=300";
            exit(1);
        }
        for (i = 0; i < nrPisiciFisier; i++)
        {
            inputCatData >> inputData;
            pisicaNume = new char[inputData.length() + 1];
            strcpy(pisicaNume, inputData.c_str());
            inputCatData >> pisicaVarsta;
            inputCatData >> inputData;
            pisicaCuloare = new char[inputData.length() + 1];
            strcpy(pisicaCuloare, inputData.c_str());
            inputCatData >> vac;
            getline(inputCatData, inputData);
            getline(inputCatData, inputData);
            pisicaDescriere = new char[inputData.length() + 1];
            strcpy(pisicaDescriere, inputData.c_str());
            B[i] = new Baza *[nrPisici];
            B[i][0] = new Pisica(pisicaVarsta, pisicaNume, pisicaDescriere, vac);
            B[i][1] = new Culoare(pisicaCuloare);
            B[i][2] = new Categorii(pisicaVarsta);
        }
        // intrucat descriile din top 3 ar fi toate la fel, am decis sa le aleg pe top 3 diferite
        for (i = 0; i < nrPisiciFisier; i++)
        {
            if (B[i][0]->getDescLength() != top3Values[0] && B[i][0]->getDescLength() != top3Values[1] && B[i][0]->getDescLength() != top3Values[2])
            {
                if (B[i][0]->getDescLength() > top3Values[0])
                {
                    top3Values[0] = B[i][0]->getDescLength();
                    top3[0][0] = B[i][0];
                    top3[0][1] = B[i][1];
                    top3[0][2] = B[i][2];
                }
                else if (B[i][0]->getDescLength() > top3Values[1])
                {
                    top3Values[1] = B[i][0]->getDescLength();
                    top3[1][0] = B[i][0];
                    top3[1][1] = B[i][1];
                    top3[1][2] = B[i][2];
                }
                else if (B[i][0]->getDescLength() > top3Values[2])
                {
                    top3Values[2] = B[i][0]->getDescLength();
                    top3[2][0] = B[i][0];
                    top3[2][1] = B[i][1];
                    top3[2][2] = B[i][2];
                }
            }
        }
        std::cout << "Top 3 pisici cu cele mai lungi descrieri:\n";
        for (i = 0; i < 3; i++)
        {
            top3[i][0]->afisare();
            top3[i][1]->afisare();
            top3[i][2]->afisare();
        }
    }
    else
        std::cout << "Eroare la deschidere fisier CatData.txt\n";
    return 0;
}
