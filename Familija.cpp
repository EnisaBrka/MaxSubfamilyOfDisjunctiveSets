#include "Familija.h"
#include <fstream>

Familija::Familija()
{
    brojSkupova=0;
}

void Familija::DodajSkup(Skup* a)
{
    skupovi.push_back(a);
    brojSkupova=skupovi.size();
}

void Familija::IspisiSkupove()
{
    for(int i=0; i<skupovi.size(); i++)
    {
        Skup* s=skupovi[i];
        cout<<s->dajNaziv()<<endl;
    }
}


void Familija::UcitajDisjunktne()
{
    ifstream ucitaj;
    ucitaj.open("skupovi.txt");
    string linija;

    int brojLinije=0;
    int i=0;
    if(ucitaj.is_open())
    {
        while (getline(ucitaj,linija))
        {
            Skup* t=skupovi[i];
            for(int j=0; j<linija.length(); j++)
            {
                if(linija.at(j)=='0')
                {
                    t->DodajDisjunktne(NadjiDSkup(j));
                }
            }
            brojLinije++;
            i++;
            if(i>skupovi.size()) break;
        }
    }
    ucitaj.close();
  }

bool Familija::NadjiSkup(int indeks)
{
    for(int i=0; i<skupovi.size();i++)
    {
            if(indeks==i){
                Skup* s=skupovi[i];
                cout<<s->dajNaziv()<<endl;
            }
        return true;

    }
    return false;
}


Skup* Familija::NadjiDSkup(int indeks)
{
    for(int i=0; i<skupovi.size();i++)
    {
        if(indeks==i){
        Skup* s=skupovi[i];
        return s;
        }
    }
}


Familija::~Familija()
{
    //dtor
}
