#include <iostream>
#include <time.h>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <stdio.h>
#include <windows.h>
#include <fstream>
#include "skoki.h"

using namespace std;











int main()
{
    srand(time(NULL));
    int wybor,hill;

    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), FOREGROUND_RED | FOREGROUND_INTENSITY );

    cout << "----------SKI JUMPING!---------- by Krzysztof Zapart" << endl;
    cout <<"--------------MENU--------------"<<endl;
    cout<<"1.Tryb Turniejowy <niedostepny>"<<endl;
    cout<<"2.Tryb PvP"<<endl;
    cout<<"3.Trening"<<endl;
    cout<<"Wybor: ";
    cin>>wybor;
    switch(wybor)
    {
    case 1:
    {
        cout<<"Tryb niedostepny";
        break;
    }
    case 2:
    {



        Zawodnik u1;
        u1.loadusers();
        u1.loadtactic();
        vikersund(u1);



        Zawodnik u2;
        u2.loadusers();
        u2.loadtactic();
        vikersund(u2);

        /*cout<<"---------WYNIKI---------"<<endl;
        wyswietlanie(u1);
        wyswietlanie(u2);*/


        break;
    }
    case 3:
    {


        Zawodnik u3;


        cout<<"Wybierz skocznie: "<<endl;
        cout<<"1.Planica K-200 HS-240"<<endl;
        cout<<"2.Vikersund K-200 HS-240"<<endl;
        cout<<"Wybor";
        cin>>hill;

        switch(hill)
        {
        case 1:
            {
            //u3.wczytywanie();
            u3.loadusers();
            u3.loadtactic();
            planica(u3);
            break;

            }
        case 2:
            {
             u3.loadusers();
             u3.loadtactic();
             vikersund(u3);
             break;
            }
        }

        break;
    }

    }





    return 0;
}
