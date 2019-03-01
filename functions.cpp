#include "functions.h"
#include "libraries.h"

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

void PrintData(vector <student> A)
{
        int num = 0;
        int num2 = 20;
        num = GetLongestString(A) + 7;

        Sort_by_FirstName(A);
       
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

void Print_Gen_List(vector <student> &A)
{
    
    std::ofstream write("GeneratedLists/List2/Full_list.txt");
    
    int num = 15;
    int num2 = 20;
    int num3 = 5;

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

    for(auto &i : A)
    {
        write << left << setfill(' ')<< setw(num) << i.LastName;
        write << left << setfill(' ')<< setw(num) << i.FirstName;
        for (int j=0; j<5; j++)
        {
             write << left << setfill(' ') << setw(num3) << i.nd[j];
        }
        write << std::fixed;
        write << left << setfill(' ') << setw(7) <<i.egz;
        write << left << setfill(' ')<< setw(num2) << std::setprecision(2) << i.Finale_suVidurkiu();
        write << left << setfill(' ')<< setw(num2) << std::setprecision(2) << i.Finale_suMediana();
        write << endl;  
    }
    write << endl;
    write.close();
}

void GroupStudents(vector <student> &A)
{
    for(auto &i : A)
    {
        if (i.Finale_suVidurkiu() >= 5) i.Group = true;
        else i.Group = false;
    }

    Sort_by_Results(A);

    std::ofstream write1("GeneratedLists/List2/kietiakai.txt");
    std::ofstream write2("GeneratedLists/List2/vargsiukai.txt");
  
    int num = 15;
    int num2 = 20;
    int num3 = 5;
    
    write1 << left << setfill(' ') << setw(num) << "Pavarde";
    write1 << left << setfill(' ') << setw(num) << "Vardas";
    write1 << left << setfill(' ') << setw(num3) << "ND1";
    write1 << left << setfill(' ') << setw(num3) << "ND2";
    write1 << left << setfill(' ') << setw(num3) << "ND3";
    write1 << left << setfill(' ') << setw(num3) << "ND4";
    write1 << left << setfill(' ') << setw(num3) << "ND5";
    write1 << left << setfill(' ') << setw(7) << "EGZ";
    write1 << left << setfill(' ') << setw(num2) << "Galutinis (Vid.)";
    write1 << left << setfill(' ') << setw(num2) << "Galutinis (Med.)" << endl; 

    write2 << left << setfill(' ') << setw(num) << "Pavarde";
    write2 << left << setfill(' ') << setw(num) << "Vardas";
    write2 << left << setfill(' ') << setw(num3) << "ND1";
    write2 << left << setfill(' ') << setw(num3) << "ND2";
    write2 << left << setfill(' ') << setw(num3) << "ND3";
    write2 << left << setfill(' ') << setw(num3) << "ND4";
    write2 << left << setfill(' ') << setw(num3) << "ND5";
    write2 << left << setfill(' ') << setw(7) << "EGZ";
    write2 << left << setfill(' ') << setw(num2) << "Galutinis (Vid.)";
    write2 << left << setfill(' ') << setw(num2) << "Galutinis (Med.)" << endl; 

    const std::string bruksnys(num*4+num3*5+14,'_');
    write1 << bruksnys << endl;

    for(auto &i : A)
    {
        if (i.Group == true)
        {
            write1 << left << setfill(' ')<< setw(num) << i.LastName;
            write1 << left << setfill(' ')<< setw(num) << i.FirstName;
            for (int j=0; j<5; j++)
            {
                write1 << left << setfill(' ') << setw(num3) << i.nd[j];
            }
            write1 << std::fixed;
            write1 << left << setfill(' ') << setw(7) <<i.egz;
            write1 << left << setfill(' ')<< setw(num2) << std::setprecision(2) << i.Finale_suVidurkiu();
            write1 << left << setfill(' ')<< setw(num2) << std::setprecision(2) << i.Finale_suMediana();
            write1 << endl; 
        }
        else if (i.Group == false)
        {
            write2 << left << setfill(' ')<< setw(num) << i.LastName;
            write2 << left << setfill(' ')<< setw(num) << i.FirstName;
            for (int j=0; j<5; j++)
            {
                write2 << left << setfill(' ') << setw(num3) << i.nd[j];
            }
            write2 << std::fixed;
            write2 << left << setfill(' ') << setw(7) <<i.egz;
            write2 << left << setfill(' ')<< setw(num2) << std::setprecision(2) << i.Finale_suVidurkiu();
            write2 << left << setfill(' ')<< setw(num2) << std::setprecision(2) << i.Finale_suMediana();
            write2 << endl; 
        }
    }
    write1 << endl;
    write2 << endl;
    write1.close();
    write2.close();
}

void GenerateList(vector <student> &A)
{
    std::srand (std::time(NULL));
    int num = 100;

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
        A.push_back(z);
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



