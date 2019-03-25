#include "functions.h"
#include "libraries.h"

extern string ListNR;
extern high_resolution_clock::time_point t1;
extern high_resolution_clock::time_point t2;
extern high_resolution_clock::time_point t3;
extern high_resolution_clock::time_point t4;
extern high_resolution_clock::time_point t5;
extern high_resolution_clock::time_point t6;


bool Compare_by_FirstName(const student& a, const student& b) 
{
    return a.FirstName < b.FirstName;
}

bool Compare_by_Results(const student &a, const student &b) 
{
    return a.Finale_Vidurkis > b.Finale_Vidurkis;
}

int GetLongestString(vector <student> &A) 
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

void Time(int &MainChoice)
{
    duration <double> time1 = t2 - t1;
    duration <double> time2 = t4 - t3;
    //duration <double> time3 = t6 - t5;
    
    if (MainChoice == 2)
    {
        std::ofstream of("GeneratedLists/" + ListNR + "/time.txt");
        of << std::fixed << std::setprecision(6) << time1.count() - time2.count() << " s" << endl;
        cout << "Sugeneruoti failai issaugoti: GeneratedLists/" << ListNR;
    }
    else if(MainChoice == 1)
    {
        cout << endl << endl;
        cout << std::fixed << std::setprecision(6) << time1.count() - time2.count() << " s" << endl;
    }
}
