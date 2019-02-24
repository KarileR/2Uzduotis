#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "libraries.h"

struct student
{
    std::string FirstName;
    std::string LastName;
    int egz, Med_ar_Vid;
    vector<int> nd;
    bool CorrectData = true;

    double Finale_suVidurkiu()
    {
        double s = 0;
        for (int i=0; i<nd.size(); i++)
        {
            s = s + nd[i];
        }
        double avr = s/nd.size();
        return 0.4 * avr + 0.6 * egz;
    }

    double Finale_suMediana()
    {
        
	    std::sort(nd.begin(), nd.end());  //sorting an array in ascending order

        double s = 0;
        if (nd.size() % 2 == 0)
        {
            s = (double)((nd[nd.size()/2] + nd[nd.size()/2])/2);
        }
        else
        {
            s =(double)nd[nd.size()/2]; 
        }
        return 0.4 * s + 0.6 * egz;
    } 
};


bool Compare_By_FirstName(const student &a, const student &b);
void Sort_By_FirstName(vector<student> &A);
void InsertData(vector <student> &A);
int Choose(int choose);
void InsertFromFile(vector <student> &A);
void Generuoti(vector <student> &A, student &z);
int GetLongestString(vector <student> &A);
int InputInteger(int choose);
void PrintData(vector <student> &A);

#endif
