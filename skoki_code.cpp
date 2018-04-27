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


/*void Zawodnik::wczytywanie()
{
    string a;
    fstream plik;
    plik.open("dane_zawodnika.txt",ios::in);

    while(getline(plik,a))
    {
        plik >> nick;
        plik >> sila;
        plik >> dos;
        plik >> tech;
        plik >> dyn;
        plik >> ment;
    }





}*/


void Zawodnik::loadusers()
{
    cout<<endl<<"Witaj! ";
    cout<<"Podaj swoj nick: ";
    cin>>nick;
    cout<<"Uzupelnij umiejetnosci Twojego skoczka, w skali od 0 do 20."<<endl;
    cout<<"Podaj sile skoczka: ";
    cin>>sila;
    cout<<"Podaj doswiadczenie skoczka: ";
    cin>>dos;
    cout<<"Podaj technike skoczka: ";
    cin>>tech;
    cout<<"Podaj dynamike skoczka: ";
    cin>>dyn;
    cout<<"Podaj mentalnosc skoczka: ";
    cin>>ment;
}

void Zawodnik::loadtactic()
{
    cout<<"------------TAKTYKA!------------"<<endl;
    cout<<"Odpowiednia taktyka, ma wplyw na odleglosc Twojego skoczka. Znajdz optymalna, aby skakac jak najdalej!"<<endl<<endl;
    cout<<"Podawaj wartosci od 0 do 100. Im lepiej ustawisz taktyke, tym dalej skoczek bedzie latal"<<endl<<endl;
    cout<<"Wybicie z progu: 0-wczesnie, 100- pozno  ";
    cin>>wybicie;
    cout<<"Parabola lotu: 0-wysoka, 100- niska  ";
    cin>>lot;
    cout<<"Agresywnosc w locie:  ";
    cin>>agr;
}
void planica(Zawodnik u)
{
    int a,n1,n2,n3,jump,t,k=0;
    float wind,wind_war,comp,score,ws,od,w1,l1,a1,w2,l2,a2,bonus,od1,od1a,od2,od2a,od3,od3a,x;
    float wyniki[50];



    for(int i=0; i<2; i++)
    {
        cout<<endl<<endl<<"Wcisnij 1 i zatwierdz ENTER, aby zasymulowac skok  ";
        cin>>t;
        //taktyka
        if(u.wybicie<=72)
        {
            w1=u.wybicie*18/72;
            od1=u.wybicie*5/72;
        }
        else
        {
            w2=u.wybicie*18/72-18;
            w1=18-w2;

            od1a=u.wybicie*5/72-5;
            od1=5-od1a;
        }

        if(u.lot<=91)
        {
            l1=u.lot*18/91;
            od2=u.lot*5/91;
        }
        else
        {
            l2=u.lot*18/91-18;
            l1=18-l2;

            od2a=u.lot*5/91-5;
            od2=5-od2a;
        }

        if(u.agr<=88)
        {
            a1=u.agr*18/88;
            od3=u.agr*5/88;
        }
        else
        {
            a2=u.agr*18/88-18;
            a1=18-a2;

            od3a=u.agr*5/88-5;
            od3=5-od3a;
        }


        bonus=(w1+l1+a1)/100+1;


        wind=rand()%30;
        if(t==1)
        {

            wind_war=wind*50/30;
            ws=(((u.sila*3+u.tech*5+u.dyn*4)*bonus)+wind_war)/110;

            comp=((wind/12)*10.4/0.8)*-1;
            od=50+od1+od2+od3+u.dos*2/20+u.ment*2/20+rand()%2;
            jump=ws*od;
            if(jump<=200)
            {
                n1=rand()%3+14;
                n2=rand()%3+14;
                n3=rand()%3+14;
            }
            else if(jump>200&&jump<=245)
            {
                n1=rand()%3+17;
                n2=rand()%3+17;
                n3=rand()%3+17;

            }
            else if(jump>245)
            {
                n1=rand()%3+15;
                n2=rand()%3+15;
                n3=rand()%3+15;
            }



            score=(jump-200)*1.2+60+comp+n1+n2+n3;

            x+=score;
            u.nota=x;
            cout<<endl<<"-------------WYNIK!-------------"<<endl;
            cout<<"Wiatr: "<<wind/12<<"m/s"<<endl;
            cout<<"Rekompensata :"<< comp<<endl;
            cout<<"Odleglosc: "<<jump<<endl;
            cout<<"Noty: "<<n1<<", "<<n2<<", "<<n3<<endl;
            cout<<"Punkty: "<<score<<endl;
            cout<<"Laczna nota: "<<x<<endl;


        }
        wyniki[k]=x;
        k++;

        if(i==1)
        {
            fstream plik;
            plik.open("Wyniki.txt", ios::in | ios::app);
            if(plik.good()==true)
            {
                plik<<u.nick<<" Seria pierwsza: "<<score<<" Seria druga: "<<x-score<<" Laczna nota: "<<x<<endl;


                plik.close();
            }


        }
    }
}
void vikersund(Zawodnik u)
{
    int a,n1,n2,n3,jump,t,k=0,i;
    float wind,wind_war,comp,score,ws,od,w1,l1,a1,w2,l2,a2,bonus,od1,od1a,od2,od2a,od3,od3a,x;
    float wyniki[50];



    for(i=0; i<2; i++)
    {
        cout<<endl<<endl<<"Wcisnij 1 i zatwierdz ENTER, aby zasymulowac skok  ";
        cin>>t;
        //taktyka
        if(u.wybicie<=63)
        {
            w1=u.wybicie*18/63;
            od1=u.wybicie*5/63;
        }
        else
        {
            w2=u.wybicie*18/63-18;
            w1=18-w2;

            od1a=u.wybicie*5/63-5;
            od1=5-od1a;
        }

        if(u.lot<=89)
        {
            l1=u.lot*25/89;
            od2=u.lot*5/89;
        }
        else
        {
            l2=u.lot*25/89-25;
            l1=25-l2;

            od2a=u.lot*5/89-5;
            od2=5-od2a;
        }

        if(u.agr<=78)
        {
            a1=u.agr*11/78;
            od3=u.agr*5/78;
        }
        else
        {
            a2=u.agr*11/78-11;
            a1=11-a2;

            od3a=u.agr*5/78-5;
            od3=5-od3a;
        }


        bonus=(w1+l1+a1)/100+1;


        wind=rand()%30;
        if(t==1)
        {

            wind_war=wind*45/30;
            ws=(((u.sila*4+u.tech*6+u.dyn*2)*bonus)+wind_war)/112;

            comp=((wind/12)*10.4/0.8)*-1;
            od=50+od1+od2+od3+u.dos*2/20+u.ment*2/20+rand()%2;
            jump=ws*od;
            if(jump<=200)
            {
                n1=rand()%3+14;
                n2=rand()%3+14;
                n3=rand()%3+14;
            }
            else if(jump>200&&jump<=245)
            {
                n1=rand()%3+17;
                n2=rand()%3+17;
                n3=rand()%3+17;

            }
            else if(jump>245)
            {
                n1=rand()%3+15;
                n2=rand()%3+15;
                n3=rand()%3+15;
            }



            score=(jump-200)*1.2+60+comp+n1+n2+n3;

            x+=score;
            cout<<endl<<"-------------WYNIK!-------------"<<endl;
            cout<<"Wiatr: "<<wind/12<<"m/s"<<endl;
            cout<<"Rekompensata :"<< comp<<endl;
            cout<<"Odleglosc: "<<jump<<endl;
            cout<<"Noty: "<<n1<<", "<<n2<<", "<<n3<<endl;
            cout<<"Punkty: "<<score<<endl;
            if(i)
            {
                cout<<"Laczna nota: "<<x<<endl;
            };
            u.nota=x;

        }
        wyniki[k]=x;
        k++;

        if(i==1)
        {
            fstream plik;
            plik.open("Wyniki.txt", ios::in | ios::app);
            if(plik.good()==true)
            {
                plik<<u.nick<<" Seria pierwsza: "<<score<<" Seria druga: "<<x-score<<" Laczna nota: "<<x<<endl;


                plik.close();
            }


        }
    }

    /*void wynik(Zawodnik u)
         for(int i=0; i<=50; i++)
        {
            for( int j=1; j<=49;  j++)
            {
                if(u.wyniki[j]>u.wyniki[j-1])
                {
                    swap(u.wyniki[j],u.wyniki[j-1]);
                }
            }
        }

        cout<<endl<<"--------NAJLEPSZE WYNIKI--------"<<endl;
        for(int i=0;i<=49;i++)
        {
           cout<<i+1<<". "<<u.wyniki[i]<<endl;
        }
    */

    cout<<endl<<"**Wyniki zostaly zapisane do pliku tekstowego 'Wyniki.txt' w katalogu gry**"<<endl;
}

xxcxcxcxcxz
