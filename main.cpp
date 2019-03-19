#include "functions.h"
#include "libraries.h"

high_resolution_clock::time_point t1;
high_resolution_clock::time_point t2;
high_resolution_clock::time_point t3;
high_resolution_clock::time_point t4;
high_resolution_clock::time_point t5;
high_resolution_clock::time_point t6;

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
