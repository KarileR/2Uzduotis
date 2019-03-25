#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "libraries.h"

struct student
{
    std::string FirstName;
    std::string LastName;
    int egz, Med_ar_Vid;
    vector <int> nd;
    bool CorrectData = true;
    double Finale_Vidurkis;
    double Finale_Mediana;

    double Finale_suVidurkiu () const
    {
        double s = 0, avr=0;
        for (int i=0; i < nd.size(); i++)
        {
            s = s + nd[i];
        }
        avr = s/nd.size();
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

bool Ar_Islaike (student &a);
bool Compare_by_Results(const student &a, const student &b);
bool Compare_by_FirstName(const student &a, const student &b);
void InsertYourself(list <student> &A);
void InsertFromFile(list <student> &A);
void ReadFromFile(list <student> &A);
void MENU (int &MainChoice,list <student> &A);
void GenerateList(int StudSK);
int Choose(int choose);
int GetLongestString(list <student> &A);
int InputInteger(int choose);
void PrintData(list <student> A);
void GroupStudents(list <student> &A);
bool is_file_exist(std::string fileName);

void Time (int &MainChoice);

#endif
