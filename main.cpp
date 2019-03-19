#include "functions.h"
#include "libraries.h"

extern high_resolution_clock::time_point t1;
extern high_resolution_clock::time_point t2;

int main ()
{

    t1 = high_resolution_clock::now();

    int MainChoice;
    list <student> A;
    MENU(MainChoice,A);

    t2 = high_resolution_clock::now();

    Time(MainChoice);

    return 0;
}
