#include "sticla.cpp"

int main()
{
    Sticla *v = NULL, temp;
    int size, i, j;
    std::cout << "Introduceti numarul de sticle: " << std::endl;
    std::cin >> size;
    v = new Sticla[size];

    for (i = 0; i < size; i++)
    {
        std::cout << "Introduceti date Sticla " << i+1 << ":" << std::endl;
        std::cin >> v[i];
    }

    std::cout << "Vector nesortat: " << std::endl;
    for (i = 0; i < size; i++)
        std::cout << v[i];

    for (i = 0; i < size - 1; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (v[i].getPret() > v[j].getPret())
            {
                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }
    std::cout << "Vector sortat: " << std::endl;
    for (i = 0; i < size; i++)
        std::cout << v[i];

    std::cout << "Sticle cu diametru >5: " << std::endl;
    for (i = 0; i < size; i++)
        if (v[i].getDiam() > 5)
            std::cout << v[i];

    return 0;
}