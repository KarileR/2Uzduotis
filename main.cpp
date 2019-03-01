#include "functions.h"
#include "libraries.h"

int main ()
{

    high_resolution_clock::time_point t1;
    high_resolution_clock::time_point t2; 
    high_resolution_clock::time_point t3;
    high_resolution_clock::time_point t4;

    t1 = high_resolution_clock::now();

    int MainChoice;
    vector <student> A;
    MENU(MainChoice,A,t2,t3);

    t4 = high_resolution_clock::now();

    Time(MainChoice,t1,t2,t3,t4);

    return 0;
}
