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

void PrintData(vector <student> &A)
{
        int num = 0;
        int num2 = 20;
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
                if(i.Med_ar_Vid == 3)  //Spausdina ir ta, ir ta
                {
                    cout << std::fixed;
                    cout << left << setfill(' ')<< setw(num2) << std::setprecision(2) << i.Finale_suVidurkiu();
                    cout << left << setfill(' ')<< setw(num2) << std::setprecision(2) << i.Finale_suMediana();
                }

                else if(i.Med_ar_Vid == 2) //Spausdina tik su vidurkiu
                {
                    cout << std::fixed;
                    cout << left << setfill(' ')<< setw(num2) << std::setprecision(2) << i.Finale_suVidurkiu();
                }

                else if (i.Med_ar_Vid == 1) //Spausdina tik su mediana
                {
                    cout << std::fixed;
                    cout << "                    ";
                    cout << left << setfill(' ')<< setw(num2);
                    cout << left << setfill(' ')<< setw(num2) << std::setprecision(2) << i.Finale_suMediana();
                }
            }

            else if (i.CorrectData == false)
            {
                cout << left << setfill(' ')<< setw(num2) << "Wrong Data";
                cout << left << setfill(' ')<< setw(num2) << "Wrong data";
            }
            cout << endl;
        }
}


void PrintData_From_Gen_List(vector <vector <student>> &AA)
{
    std::ofstream write("temp.txt"); 
    int fileNR = 1;
    for(int i=0; i< AA.size(); i++)
        {
            std::string sk = std::to_string(fileNR);

            std::string file = "GeneratedLists/List" + sk + "/list.txt";
            fileNR++;

            std::ofstream write(file);
        
            int num = 15;
            int num2 = 20;
            int num3 = 5;
            //num = GetLongestString(A) + 7;

            write << left << setfill(' ') << setw(num) << "Pavarde";
            write << left << setfill(' ') << setw(num) << "Vardas";
            write << left << setfill(' ') << setw(num3) << "ND1";
            write << left << setfill(' ') << setw(num3) << "ND2";
            write << left << setfill(' ') << setw(num3) << "ND3";
            write << left << setfill(' ') << setw(num3) << "ND4";
            write << left << setfill(' ') << setw(num3) << "ND5";
            write << left << setfill(' ') << setw(7) << "EGZ";
            write << left << setfill(' ') << setw(num2) << "Galutinis (Vid.)";
            write << left << setfill(' ') << setw(num2) << "Galutinis (Med.)" << endl; 

            const std::string bruksnys(num*4+num3*5+14,'_');
            write << bruksnys << endl;

            for(int h=0; h < AA[i].size(); h++)
            {
                write << left << setfill(' ')<< setw(num) << AA[i][h].LastName;
                write << left << setfill(' ')<< setw(num) << AA[i][h].FirstName;
                for (int j=0; j<5; j++)
                {
                    write << left << setfill(' ') << setw(num3) << AA[i][h].nd[j];
                }
                write << std::fixed;
                write << left << setfill(' ') << setw(7) <<AA[i][h].egz;
                write << left << setfill(' ')<< setw(num2) << std::setprecision(2) << AA[i][h].Finale_suVidurkiu();
                write << left << setfill(' ')<< setw(num2) << std::setprecision(2) << AA[i][h].Finale_suMediana();
                write << endl;  
            }
            write << endl;
            write.close();
        }
}


void GenerateList(vector <vector <student>> &AA)
{
    std::srand (std::time(NULL));
    int num = 10;
    for (int k=0; k<5; k++)
    {
        vector<student> a;
        student z;
        for(int i=0; i<num; i++)
        {
            z.nd.clear();
            std::string sk = std::to_string(i+1);

            std::string vardas = "Vardas" + sk;
            std::string pavarde = "Pavarde" + sk;

            z.FirstName = vardas;
            z.LastName = pavarde;

            for(int j=0; j<5; j++)
            {
                z.nd.push_back(rand() % 10 + 1);
            }
            z.egz = rand() % 10 + 1;
            a.push_back(z);
        }
        num = num * 10;
        AA.push_back(a);
    }

}



void Sort_by_Grades(vector <vector <student>> &AA)
{
    for(int i=0; i<10; i++)
    {
        
    }

}



void InsertYourself(vector <student> &A)
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
            cout << "Pasirinkite skaiciuoti su mediana (1), vidurkiu (2), arba su abiem (3): ";
            z.Med_ar_Vid = Choose(3);
            cout << endl;
            cout << endl;
            A.push_back(z);
        }

}

void MENU(vector <student> &A, vector <vector <student>> &AA)
{
    cout << endl;
    cout << "Paspausti atitinkamus skaicius, jeigu norite:" << endl << endl;
    cout << "1. Sukelti duomenis is esamo failo" << endl;
    cout << "2. Generuoti atsitiktinius 5 sarasus" << endl; 
    cout << "3. Ivesti duomenis ranka" << endl << endl;
    cout << "Jusu pasirinkimas: ";
    int a = Choose(3);

    if (a == 1) 
    {
        InsertFromFile(A); 
        PrintData(A);
    }       
    else if (a == 2) 
    {
        GenerateList(AA);
        PrintData_From_Gen_List(AA);
        Sort_by_Grades(AA);
    }
    else if (a == 3)
    {
        InsertYourself(A);
        PrintData(A);
    } 
}

int Choose(int choose)  //Inputs and validates integer (user's choice)
{
    if (choose == 2)
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

    else if (choose == 3)
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
    std::ifstream read("data/kursiokai.txt");
     
    if(!read)
	{
		cout << "Cannot open the File! Make sure that your file is in 'data' folder "<< endl;
	}

    int inputNd;
    student z;
    while(!read.eof())
    {
        z.nd.clear();
        read >> z.FirstName;
        read >> z.LastName;

        bool CorrectND = true;
        bool CorrectEGZ = true;

        for (int j=1; j<=5; j++)
        {
            read >> inputNd;
                if(read.fail())
                {
                    read.clear();
                    read.ignore(256,' ');
                    inputNd = 1;
                    CorrectND = false;
                }
                else if (inputNd <= 0 || inputNd > 10) CorrectND = false;
                
            z.nd.push_back(inputNd);
        }
        read >> z.egz;
                if(read.fail())
                {
                    read.clear();
                    read.ignore(256,' ');
                    z.egz = 1;
                    CorrectEGZ = false;
                }
                else if (z.egz <= 0 || z.egz > 10)
                {
                    CorrectEGZ = false;
                }
                else CorrectEGZ = true;

        z.Med_ar_Vid = 3;

        if (CorrectEGZ == false || CorrectND == false) z.CorrectData = false;
        else z.CorrectData = true;
        A.push_back(z);
    }
    read.close();
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


