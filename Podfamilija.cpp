#include "Podfamilija.h"
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>


Podfamilija::Podfamilija()
{
    brojSkupova=0;
}

void Podfamilija::DodajSkup(Skup* a)
{
    skupovi.push_back(a);
    brojSkupova=skupovi.size();
}

bool Podfamilija::NadjiElemenatUskupuPodf(int indeks)
{
    for(int i=0; i<skupovi.size();i++)
    {
        Skup* s=skupovi[i];
        if(indeks==s->dajIndeks()) return true;
    }
    return false;
}


Podfamilija Podfamilija::OdrednjivanjePodfamilije(int i, Familija &f, Podfamilija &podf, vector<Skup*> &skupPodf, int &brojSkupova, int &brojSkupovaPodf)
{
    Podfamilija pf;
    vector<Skup*> disj;
    Skup* s=skupPodf.at(i);

    if(NadjiElemenatUskupuPodf(s->dajIndeks())==true)
    {

      //  s->IspisiDisjunktne();
        disj=s->dajDisjunktne();

        vector<Skup*> konacni(brojSkupova+brojSkupovaPodf);
        vector<Skup*>::iterator it;

        it=set_difference(skupPodf.begin(), skupPodf.end(), disj.begin(), disj.end(), konacni.begin());
        konacni.resize(it-konacni.begin());
        //for(it=konacni.begin(); it!=konacni.end(); ++it) cout<<'\t'<<*it;
        //konaèni sadrže elemente koji nisu disjunktni sa ostalima, pa ih treba izbaciti iz podfamilije
        vector<Skup*>::iterator itt;
        it=konacni.begin();
        itt=skupPodf.begin();
        if(konacni.size()!=0)
        {
            while(it<konacni.end() || itt<skupPodf.end())
            {
                if(*itt==*it)
                    {
                        itt=skupPodf.erase(itt);
                        if(i>0) i--;
                        if(konacni.size()==1) break;
                        else ++it;
                    }
                else ++itt;
            }
        }
    }

    for(int i=0; i<skupPodf.size(); i++)
        {
            pf.DodajSkup(skupPodf.at(i));
        }
    i++;
    if(i<skupPodf.size())
    {
        pf=podf.OdrednjivanjePodfamilije(i, f, podf, skupPodf, brojSkupova, brojSkupovaPodf);
    }
    if(i==skupPodf.size()-1)
    {
        pf=podf.OdrednjivanjePodfamilije(i, f, podf, skupPodf, brojSkupova, brojSkupovaPodf);
    }

    return pf;
}

Podfamilija Podfamilija::ProvjeraDisjunktnosti()
{
    Podfamilija pf1;
    vector<Skup*> skup;
    skup=this->dajElPodfamilije();
   // this->IspisiSkupove();
   // cout<<"---------"<<endl;

    for(int i=0; i<skup.size(); i++)
    {
        Skup* s=skup.at(i);
        vector<Skup*> disj;
        disj=s->dajDisjunktne();

        vector<Skup*> konacni(skup.size());
        vector<Skup*>::iterator it;

        it=set_difference(skup.begin(), skup.end(), disj.begin(), disj.end(), konacni.begin());
        konacni.resize(it-konacni.begin());
        //for(it=konacni.begin(); it!=konacni.end(); ++it) cout<<'\t'<<*it;
        //konaèni sadrže elemente koji nisu disjunktni sa ostalima, pa ih treba izbaciti iz podfamilije
        vector<Skup*>::iterator itt;
        it=konacni.begin();
        itt=skup.begin();
        if(konacni.size()!=0)
        {
            while(it<konacni.end() || itt<skup.end())
            {
                if(*itt==*it)
                    {
                        itt=skup.erase(itt);
                        if(i>0) i--;
                        if(konacni.size()==1) break;
                        else ++it;
                    }
                else ++itt;
            }
        }
    }
    for(int i=0; i<skup.size(); i++)
        {
            pf1.DodajSkup(skup.at(i));
        }
    return pf1;
}


void Podfamilija::IspisiSkupove()
{
    for(int i=0; i<skupovi.size(); i++)
    {
        Skup* s=skupovi[i];
        cout<<s->dajNaziv()<<endl;
    }
}

Podfamilija::~Podfamilija()
{
    //dtor
}
