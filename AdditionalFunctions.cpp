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

