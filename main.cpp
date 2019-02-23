#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <cstring>
#include <limits>

using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::setfill;
using std::left;
using std::vector;

int const N = 20;

struct student
{
    std::string FirstName;
    std::string LastName;
    int egz, Med_ar_Vid;
    vector<int> nd;

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


bool Compare_By_FirstName(const student &a, const student &b) 
{
    return a.FirstName < b.LastName;
}

void Sort_By_FirstName(vector<student> &A) 
{
    std::sort(A.begin(), A.end(), Compare_By_FirstName);
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
    cout << max << endl << endl;
    return max;
}

void PrintData(vector <student> &A)
{
    int num = 0;
    int const num2 = 20;
    num = GetLongestString(A) + 7;

    
    Sort_By_FirstName(A);

    cout << endl;
    cout<< left << setfill(' ') << setw(num) << "Pavarde";
    cout<< left << setfill(' ') << setw(num) << "Vardas";
    cout<< left << setfill(' ') << setw(num2) << "Galutinis (Vid.)";
    cout<< left << setfill(' ') << setw(num2) << "Galutinis (Med.)" << endl; 

    
    const std::string bruksnys(num+num+20+17,'_');
    cout<<bruksnys<<endl;

    for(auto &i: A)
    {
        cout << left << setfill(' ')<< setw(num) << i.LastName;
        cout << left << setfill(' ')<< setw(num) << i.FirstName;
        
        if(i.Med_ar_Vid == 2)  //Spausdina ir ta, ir ta
        {
            cout << std::fixed;
            cout << left << setfill(' ')<< setw(num2) << std::setprecision(2) << i.Finale_suVidurkiu();
            cout << left << setfill(' ')<< setw(num2) << std::setprecision(2) << i.Finale_suMediana();
        }

        if(i.Med_ar_Vid == 1) //Spausdina tik su vidurkiu
        {
            cout << std::fixed;
            cout << left << setfill(' ')<< setw(num2) << std::setprecision(2) << i.Finale_suVidurkiu();
        }

        if (i.Med_ar_Vid == 0) //Spausdina tik su mediana
        {
            cout << "                    ";
            cout << left << setfill(' ')<< setw(num2);
            cout << left << setfill(' ')<< setw(num2) << std::setprecision(2) << i.Finale_suMediana();
        }
        cout << endl;
    }
}

void Generuoti(vector <student> &A, student &z)
{
    std::srand (std::time(NULL));
    for(int j=1; j<=6; j++)
    {
        z.nd.push_back(rand() % 10 + 1);
    }
    z.egz = rand() % 10 + 1;
}

int CountLines(int &numLines)
{
    std::ifstream in("kursiokai.txt");

    while ( in.good() )
    {
        std::string line;
        std::getline(in, line);
        ++numLines;
    }
    in.close();

    return numLines;
}

void InsertFromFile(vector <student> &A)
{
    std::ifstream fd("kursiokai.txt");

    int numLines;
    CountLines(numLines);
    if(!fd)
	{
		cout << "Cannot open the File : "<<endl;
	}
    cout << numLines << endl;

    int inputNd;
    int i=1;
    student z;
    
    while(i<=numLines) 
    {
        z.nd.clear();
        fd >> z.FirstName;
        fd >> z.LastName;

        for (int j=1; j<=5; j++)
        {
            fd >> inputNd;
            z.nd.push_back(inputNd);
        }
        fd >> z.egz;
        z.Med_ar_Vid = 2;
        i++;
        A.push_back(z);
    }
   
    fd.close();
}

void CinAndCheck(auto *a)
{
    cin >> *a;
    do
    {
        try 
        {
            if (cin.fail()) 
            {
                throw std::runtime_error("Error, iveskite dar karta: ");
            }
        }
        catch (const std::runtime_error& e)
        {
            cout << e.what();
            cin.clear();
            cin.ignore(256, '\n');
            *a = -100;
        }

    }while(cin.fail());
}


void InsertData(vector <student> &A)
{
    cout << "Jei norite sukelti duomenis is failo spauskite 1, jei ne - 0: ";
    int a;
    cin >> a;

    int sk=0;

    if (a == 1)
    {
        InsertFromFile(A);        
    }
    else if (a == 0)
    {
        cout << "Iveskite mokiniu skaiciu: ";
        cin >> sk;

        cout << endl;

        student z;

        for(int i=1; i <= sk; i++)
        {
            z.nd.clear();
            cout << "Iveskite " << i << "-ojo mokinio duomenis" << endl;
            cout << "Vardas: "; 
            
            cin >> z.FirstName;
            cout << "Pavarde: ";
            cin >> z.LastName;
            cout << endl;
            
            int g;
            cout << "Pasirinkti generuoti pazymius atsitiktinai (1) arba ivesti paciam (0): ";
            cin >> g; 
           

            if (g == 1) Generuoti(A,z);
            else if (g == 0)
            {
                cout << "Pradekite vesti mokinio pazymius. Kai baigsite iveskite 0. " << endl;
                int j=1;
                int ans;

                while(true)
                {
                    cout << j <<"-uju namu darbu rezultatas: ";
                    cin >> ans;

                    if (ans == 0) break;
                    else
                    {
                        z.nd.push_back(ans);
                        j++;
                    }
                }

                cout << "Egzamino rezultatai: ";
                cin >> z.egz;
                cout << endl;
            }

            cout << "Pasirinkite skaiciuoti su mediana (0), vidurkiu (1), arba su abiem (2): ";
            cin >> z.Med_ar_Vid;
            cout << endl;
            cout << endl;
            A.push_back(z);
        }
    }
}

int main ()
{
    vector <student> A;
    
    InsertData(A);
    PrintData(A);

    return 0;
}