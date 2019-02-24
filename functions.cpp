#include "functions.h"
#include "libraries.h"

bool Compare_By_FirstName(const student &a, const student &b) 
{
    return a.FirstName < b.FirstName;
}

void Sort_By_FirstName(vector<student> &A) 
{
    std::sort(A.begin(), A.end(), Compare_By_FirstName);
}

void InsertData(vector <student> &A)
{
    cout << "Jei norite sukelti duomenis is failo spauskite 1, jei ne - 2: ";
    int a = Choose(2);

    if (a == 1)
    {
        InsertFromFile(A);        
    }
    else if (a == 2)
    {
        cout << "Iveskite mokiniu skaiciu: ";
        int sk = InputInteger(1); 
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
            
            cout << "Pasirinkti generuoti pazymius atsitiktinai (1) arba ivesti paciam (2): ";
            int g = Choose(2);  

            if (g == 1) Generuoti(A,z);
            else if (g == 2)
            {
                cout << "Pradekite vesti mokinio pazymius. Kai baigsite iveskite 0. " << endl;
                int j=1;

                while(true)
                {
                    cout << j <<"-uju namu darbu rezultatas: ";
                    int ans = InputInteger(2);

                    if (ans == 0) break;
                    else
                    {
                        z.nd.push_back(ans);
                        j++;
                    }
                }

                cout << "Egzamino rezultatai: ";
                z.egz = InputInteger(2);
                cout << endl;
            }

            cout << "Pasirinkite skaiciuoti su mediana (0), vidurkiu (1), arba su abiem (2): ";
            z.Med_ar_Vid = Choose(3);
            cout << endl;
            cout << endl;
            A.push_back(z);
        }
    }
}

int Choose(int choose)  //Inputs and validates integer (user's choice)
{
    if (choose = 2)
    {
        int a;
        cin >> a;
        while (true)
        {
            if (a == 2 || a == 1) break;
            do
            {
                try
                {
                    if (std::cin.fail()) throw std::runtime_error("Input is not an integer\n");

                }
                catch (...)
                {
                        cin.clear();
                        cin.ignore(256, '\n');
                }
                cout << "Iveskite dar karta: ";
                cin >> a;
            }while(std::cin.fail());
        }
        return a;
    }

    if (choose = 3)
    {
        int a;
        cin >> a;
        while (true)
        {
            if (a == 1 || a == 2 || a == 3) break;
            do
            {
                try
                {
                    if (std::cin.fail()) throw std::runtime_error("Input is not an integer\n");

                }
                catch (...)
                {
                        cin.clear();
                        cin.ignore(256, '\n');
                }
                cout << "Iveskite dar karta: ";
                cin >> a;
            }while(std::cin.fail());
        }
        return a;
    }
}

void InsertFromFile(vector <student> &A)
{
    std::ifstream fd("kursiokai.txt");
     
    if(!fd)
	{
		cout << "Cannot open the File : "<<endl;
	}

    int inputNd;
    student z;
    
    while(!fd.eof())
    {
        z.nd.clear();
        fd >> z.FirstName;
        fd >> z.LastName;

        for (int j=1; j<=5; j++)
        {
            fd >> inputNd;
                if (inputNd <= 0 || inputNd > 10 || fd.fail())
                {
                    z.CorrectData = false;
                    inputNd = 0;
                }
                else
                {
                    z.CorrectData = true;
                }
                
            z.nd.push_back(inputNd);
        }
        fd >> z.egz;
            if (z.egz <= 0 || z.egz > 10 || fd.fail())
                {
                    z.CorrectData = false;
                    z.egz = 0;
                }
                else
                {
                    z.CorrectData = true;
                }

        z.Med_ar_Vid = 2;
        A.push_back(z);
    }
    fd.close();
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

int InputInteger(int choose) //Inputs and validates integer
{

    if (choose == 1)   //Turi buti ivedamas teigiamas skaicius
    {
        int a;
        cin >> a;
        while (true)
        {
            if (a > 0) break;
            do
            {
                try
                {
                    if (std::cin.fail()) throw std::runtime_error("Input is not an integer\n");

                }
                catch (...)
                {
                        cin.clear();
                        cin.ignore(256, '\n');
                }
                cout << "Iveskite dar karta: ";
                cin >> a;
            }while(std::cin.fail());
        }
        return a;
    }

    if (choose == 2) //Turi buti ivedamas skaicius tarp 1 ir 10
    {
        int a;
        cin >> a;
        while (true)
        {
            if (a >= 0 && a < 10) break;
            do
            {
                try
                {
                    if (std::cin.fail()) throw std::runtime_error("Input is not an integer\n");

                }
                catch (...)
                {
                        cin.clear();
                        cin.ignore(256, '\n');
                }
                cout << "Iveskite dar karta: ";
                cin >> a;
            }while(std::cin.fail());
        }
        return a;
    }
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

        if (i.CorrectData == true)
        {
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
        }

        else if (i.CorrectData == false)
        {
                cout << std::fixed;
                cout << left << setfill(' ')<< setw(num2) << "Wrong Data";
                cout << left << setfill(' ')<< setw(num2) << "Wrong data";
        }
        cout << endl;
    }
}