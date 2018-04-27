#include <iostream>
#include <time.h>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <stdio.h>
#include <windows.h>
#include <fstream>
using namespace std;

class Zawodnik
{
public:

    string nick;
    int dos;
    int sila;
    int tech;
    int dyn;
    int ment;
    int wybicie;
    int lot;
    int agr;
    float nota;


void loadusers();
void loadtactic();
void wyswietlanie();
public:
    friend void planica(Zawodnik u);
    friend void vikersund(Zawodnik u);
    friend void wyswietlanie(Zawodnik u);
};
void wyswietlanie();
void planica();
void vikersund();
