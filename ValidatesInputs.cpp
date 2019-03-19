#include "functions.h"
#include "libraries.h"

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

    else if (choose == 2) //Turi buti ivedamas skaicius tarp 1 ir 10
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


int Choose(int choose)  //Inputs and validates integer (user's choice)
{
    if (choose == 2)  //Choose 1 or 2
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

    else if (choose == 3) //Choose 1 or 2 or 3
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