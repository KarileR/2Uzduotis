#include "functions.h"
#include "libraries.h"

extern string ListNR;
extern high_resolution_clock::time_point t3;
extern high_resolution_clock::time_point t4;
extern high_resolution_clock::time_point t5;
extern high_resolution_clock::time_point t6;

void MENU(int &MainChoice, list <student> &A)
{
    cout << endl;
    cout << "Paspausti atitinkamus skaicius, jeigu norite:" << endl << endl;
    cout << "1. Sukelti duomenis is esamo failo" << endl;
    cout << "2. Generuoti atsitiktini sarasa" << endl; 
    cout << "3. Ivesti duomenis ranka" << endl << endl;
    cout << "Jusu pasirinkimas: ";

    t3 = high_resolution_clock::now();
    MainChoice = Choose(3);
    t4 = high_resolution_clock::now();

    if (MainChoice == 1) 
    {
        InsertFromFile(A); 
        PrintData(A);
    }       
    else if (MainChoice == 2) 
    {
        cout << "Kiek norite sugeneruoti studentu? "; 

        t5 = high_resolution_clock::now();
        int StudSk = InputInteger(1);
        t6 = high_resolution_clock::now();

        GenerateList(StudSk);
        ReadFromFile(A);
        GroupStudents(A);
    }
    else if (MainChoice == 3)
    {
        InsertYourself(A);
        PrintData(A);
    } 
}