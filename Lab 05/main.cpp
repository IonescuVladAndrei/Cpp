#include "student.cpp"

int main()
{
    Student *v = new Student[10], temp;
    int size = 10, i, j;
    int note0[] = {10, 10, 9};
    int note1[] = {10, 9, 9};
    int note2[] = {10, 8, 9};
    int note3[] = {10, 7, 9};
    int note4[] = {10, 6, 9};
    int note5[] = {10, 6, 9, 10};
    int note6[] = {10, 6, 9, 8};
    int note7[] = {10, 6, 9, 10};
    int note8[] = {10, 6, 9, 5};
    int note9[] = {10, 6, 9, 10};
    v[0] = Student((char*)"S1 James", note0, 3, (char*)"Popescu Marcel", (char*)"335AB", 10);
    v[1] = Student((char*)"S2 Robert", note1, 3, (char*)"Popescu Marcel", (char*)"335AB", 10);
    v[2] = Student((char*)"S3 John", note2, 3, (char*)"Popescu Marcel", (char*)"335AB", 10);
    v[3] = Student((char*)"S4 Michael", note3, 3, (char*)"Popescu Marcel", (char*)"335AB", 10);
    v[4] = Student((char*)"S5 David", note4, 3, (char*)"Popescu Marcel", (char*)"335AB", 10);
    v[5] = Student((char*)"S6 Mary", note5, 4, (char*)"Popescu Marcel", (char*)"335AB", 10);
    v[6] = Student((char*)"S7 Patricia", note6, 4, (char*)"Popescu Marcel", (char*)"335AB", 10);
    v[7] = Student((char*)"S8 Jennifer", note7, 4, (char*)"Popescu Marcel", (char*)"335AB", 10);
    v[8] = Student((char*)"S9 Linda", note8, 4, (char*)"Popescu Marcel", (char*)"335AB", 10);
    v[9] = Student((char*)"S10 Elizabeth", note9, 4, (char*)"Popescu Marcel", (char*)"335AB", 10);

    std::cout << "Vector nesortat: " << std::endl;
    for (i = 0; i < size; i++)
        std::cout << "Medie = " << getMedie(v[i]) << "\t"<< v[i];
    int M = 0;
    for (i = 0; i < size-1; i++)
        for (j = i+1; j < size; j++)
            if(getMedie(v[i]) < getMedie(v[j]))
            {   
                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
    
    std::cout << "Vector sortat: " << std::endl;
    for (i = 0; i < size; i++)
    {
        std::cout << "Medie = " << getMedie(v[i]) << "\t"<< v[i];
        v[i].setNume_dir((char*)"Alex Zdranciu");
    }
    std::cout << "Vector sortat dupa schimbare diriginte: " << std::endl;
    for (i = 0; i < size; i++)
        std::cout << "Medie = " << getMedie(v[i]) << "\t"<< v[i];

    int poz = 6;
    int noteNew[] = {8, 8, 8};
    Student studentNew = Student((char*)"EU", noteNew, 3, (char*)"Alex Zdranciu", (char*)"335AB", 11);
    Student *v2 = new Student[11];
    j = 0;
    size++;

    for(i=0;i<size;i++)
    {   
        
        
        std::cout<< "j = " << j << std::endl;
        if(i==poz)
        {
            std::cout<<"AICI"<<std::endl;
            v2[i] = studentNew;
            std::cout << v2[i];
        }
        else
        {
            v2[i] = v[j];
            std::cout << v2[i];
            j++;
        }
        v2[i].setNrElv(11);
    }
    
    std::cout<<"AICI"<<std::endl;
    std::cout << "Vector dupa adaugare student: " << std::endl;
    for (i = 0; i < size; i++)
        std::cout << "Medie = " << getMedie(v2[i]) << "\t"<< v2[i];
    delete[] v;
    delete[] v2;
    return 0;
}