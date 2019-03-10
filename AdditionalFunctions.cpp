#include "functions.h"
#include "libraries.h"

bool Compare_by_FirstName(const student& a, const student& b) 
{
    return a.FirstName < b.FirstName;
}

bool Compare_by_Results(const student &a, const student &b) 
{
    return a.Finale_suVidurkiu() > b.Finale_suVidurkiu();
}


void Time(int &MainChoice, high_resolution_clock::time_point t1, high_resolution_clock::time_point t2, high_resolution_clock::time_point t3, high_resolution_clock::time_point t4)
{
    duration <double> time1 = t4 - t1;
    duration <double> time2 = t3 - t2;
    
    if (MainChoice == 2)
    {
        std::ofstream of("GeneratedLists/List5/time.txt");
        of << std::fixed << std::setprecision(6) << time1.count() - time2.count() << " s" << endl;
        cout << "Sugeneruoti failai issaugoti: GeneratedLists/List2/time.txt ";
    }
    else if(MainChoice == 1)
    {
        cout << endl << endl;
        cout << std::fixed << std::setprecision(6) << time1.count() - time2.count() << " s" << endl;
    }
    
}

int GetLongestString(list <student> &A) 
{
    int ln=0, max=0;
    for(auto &i: A)
    {
        ln = i.FirstName.size();
        if (ln > max) max = ln;
    }
    for(auto &i: A)
    {
        ln = i.LastName.size();
        if (ln > max) max = ln;
    }
    return max;
}

