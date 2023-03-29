#include "PopulareDatePisici.hpp"

PopulareDatePisici::PopulareDatePisici() : nrOfCats()
{
}

PopulareDatePisici::PopulareDatePisici(int nrOfCats)
{
    this->nrOfCats = nrOfCats;
    int nrOfNames = 0, nrOfDescrip = 0, nrOfColors = 0; // din fisier
    int wantedNrOfCats = nrOfCats;                      // de la constructor
    int i, randCatName, randCatAge, randCatVac, randCatDescrip, randCatColor;
    std::ifstream inputCatNames("data/CatNamesInput.txt");
    std::ifstream inputCatDescrip("data/CatDescripInput.txt");
    std::ifstream inputCatColor("data/CatColorsInput.txt");
    std::ofstream outputCatData("data/CatData.txt");
    std::string inputData;
    char **catNames, **catDesrip, **catColors;
    if (inputCatNames.is_open())
    {
        inputCatNames >> nrOfNames;
        // std::cout << "Numarul de nume pisici in fisier: " << nrOfNames << std::endl;
        catNames = new char *[nrOfNames];
        for (i = 0; i < nrOfNames; i++)
        {
            inputCatNames >> inputData;
            catNames[i] = new char[inputData.length() + 1];
            strcpy(catNames[i], inputData.c_str());
            // std::cout << "Nume pisica " << i + 1 << ": " << catNames[i] << std::endl;
        }
    }
    else
        std::cout << "Eroare la deschidere fisier CatNamesInput.txt\n";

    if (inputCatDescrip.is_open())
    {
        inputCatDescrip >> nrOfDescrip;
        // std::cout << "Numarul de descrieri pisici in fisier: " << nrOfDescrip << std::endl;
        catDesrip = new char *[nrOfDescrip];
        getline(inputCatDescrip, inputData);
        for (i = 0; i < nrOfDescrip; i++)
        {
            getline(inputCatDescrip, inputData);
            catDesrip[i] = new char[inputData.length() + 1];
            strcpy(catDesrip[i], inputData.c_str());
            // std::cout << "Nume pisica " << i + 1 << ": " << catDesrip[i] << std::endl;
        }
    }
    else
        std::cout << "Eroare la deschidere fisier CatDescripInput.txt\n";

    if (inputCatColor.is_open())
    {
        inputCatColor >> nrOfColors;
        //std::cout << "Numarul de culori pisici in fisier: " << nrOfColors << std::endl;
        catColors = new char *[nrOfColors];
        for (i = 0; i < nrOfColors; i++)
        {
            inputCatColor >> inputData;
            catColors[i] = new char[inputData.length() + 1];
            strcpy(catColors[i], inputData.c_str());
            //std::cout << "Nume pisica " << i + 1 << ": " << catColors[i] << std::endl;
        }
    }
    else
        std::cout << "Eroare la deschidere fisier CatColorsInput.txt\n";

    //  Nume, varsta(in luni), culoare, vacinata(0/1)
    outputCatData << wantedNrOfCats << "\n";
    if (outputCatData.is_open())
    {
        srand(time(0));
        for (i = 0; i < wantedNrOfCats; i++)
        {
            randCatAge = 0;
            while (randCatAge == 0) // varsta in luni != 0
                randCatAge = (rand() % 241);
            randCatDescrip = (rand() % nrOfDescrip);
            randCatName = (rand() % nrOfDescrip);
            randCatColor = (rand() % nrOfColors);
            randCatVac = (rand() % 2);
            outputCatData << catNames[randCatName] << " " << randCatAge << " " << catColors[randCatColor] << " " << randCatVac << "\n"
                          << catDesrip[randCatDescrip] << "\n";
        }
    }
    else
        std::cout << "Eroare la deschidere fisier CatDescripInput.txt\n";

    for (i = 0; i < nrOfDescrip; i++)
        delete[] catDesrip[i];
    delete[] catDesrip;

    for (i = 0; i < nrOfNames; i++)
        delete[] catNames[i];
    delete[] catNames;

    for (i = 0; i < nrOfColors; i++)
        delete[] catColors[i];
    delete[] catColors;
}

PopulareDatePisici::~PopulareDatePisici()
{
}