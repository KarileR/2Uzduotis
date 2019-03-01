#include "functions.h"
#include "libraries.h"

void MENU(int &MainChoice, vector <student> &A, high_resolution_clock::time_point &t2, high_resolution_clock::time_point &t3)
{
    cout << endl;
    cout << "Paspausti atitinkamus skaicius, jeigu norite:" << endl << endl;
    cout << "1. Sukelti duomenis is esamo failo" << endl;
    cout << "2. Generuoti atsitiktini sarasa" << endl; 
    cout << "3. Ivesti duomenis ranka" << endl << endl;
    cout << "Jusu pasirinkimas: ";

    t2 = high_resolution_clock::now();

    MainChoice = Choose(3);

    t3 = high_resolution_clock::now();

    if (MainChoice == 1) 
    {
        InsertFromFile(A); 
        PrintData(A);
    }       
    else if (MainChoice == 2) 
    {
        GenerateList(A);
        Print_Gen_List(A);
        GroupStudents(A);
    }
    else if (MainChoice == 3)
    {
        InsertYourself(A);
        PrintData(A);
    } 
}