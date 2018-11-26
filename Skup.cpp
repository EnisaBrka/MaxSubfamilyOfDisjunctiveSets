#include "Skup.h"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

Skup::Skup()
{

}

Skup::Skup(char a, int i)
{
    indeks=i;
    stringstream ss;
    ss<<a<<i;
    string s(ss.str());
    naziv=s;
}

void Skup::DodajDisjunktne(Skup* s)
{
    disjunktni.push_back(s);
}

void Skup::IspisiDisjunktne()
{
    for(int i=0; i<disjunktni.size(); i++)
    {
        Skup* s=disjunktni[i];
        cout<<s->dajNaziv()<<endl;
    }
}

int Skup::DajBrojDisjunktnih()
{
    return disjunktni.size();
}

Skup::~Skup()
{

}
