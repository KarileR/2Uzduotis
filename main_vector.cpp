#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <cstdlib>

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
        for (int i=1; i<=nd.size(); i++)
        {
            s = s + nd[i];
        }
        return 0.4 * s/nd.size() + 0.6 * egz;
    }

    double Finale_suMediana()
    {
        
        //sorting an array in ascending order
	    std::sort(nd.begin(), nd.end());

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

void PrintData(int &sk, student A[])
{
    int const num = 17;

    cout<< left << setfill(' ') << setw(num) << "Pavarde";
    cout<< left << setfill(' ') << setw(num) << "Vardas";
    cout<< left << setfill(' ') << setw(num) << "Galutinis (Vid.)";
    cout<< left << setfill(' ') << setw(num) << "/ Galutinis (Med.)" << endl;

    const std::string bruksnys(num*4,'_');
    cout<<bruksnys<<endl;

    for(int i=1; i<=sk; i++)
    {
        cout << left << setfill(' ')<< setw(num) <<A[i].LastName;
        cout << left << setfill(' ')<< setw(num) <<A[i].FirstName;
        
        if(A[i].Med_ar_Vid == 1)
        {
            cout << std::fixed;
            cout << left << setfill(' ')<< setw(num) << std::setprecision(2) << A[i].Finale_suVidurkiu();
        }

        cout << left << setfill(' ')<< setw(num) << " ";

        if(A[i].Med_ar_Vid == 0)
        {
            cout << std::fixed;
            cout << "  ";
            cout << left << setfill(' ')<< setw(num) << std::setprecision(2) << A[i].Finale_suMediana();
        }
        cout << endl;
    }
}

void Generuoti(student A[], int i)
{
    std::srand (std::time(NULL));
    for(int j=1; j<=6; j++)
    {
        A[i].nd.push_back(rand() % 10 + 1);
    }
    A[i].egz = rand() % 10 + 1;
}

void Error()
{
    cout <<" Klaida. Iveskite is naujo! " <<endl;
    cin.ignore();
    cin.clear();
}

void InsertData(int &sk, student A[])
{
    for(int i=1; i <= sk; i++)
    {
        cout << "Iveskite " << i << "-ojo mokinio duomenis" << endl;
        cout << "Vardas: "; 
        cin >> A[i].FirstName;
        cout << "Pavarde: ";
        cin >> A[i].LastName;
        cout << endl;
        
        int g;
        cout << "Pasirinkti generuoti pazymius atsitiktinai (1) arba ivesti paciam (0): ";
        cin >> g;

        if (g == 1) Generuoti(A,i);
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
                    A[i].nd.push_back(ans);
                    j++;
                }
            }

            cout << "Egzamino rezultatai: ";
            cin >> A[i].egz;
            cout << endl;
        }

        cout << "Pasirinkite skaiciuoti su mediana (0) arba vidurkiu (1): " << endl;
        cin >> A[i].Med_ar_Vid;
        cout << endl;
        cout << endl;
    }

}


int main ()
{
    int sk;
    cout << "Iveskite mokiniu skaiciu: ";
    cin >> sk;
    cout << endl;
    student A[N];
    
    InsertData(sk,A);
    PrintData(sk, A);

    return 0;
}