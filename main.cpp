#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "Skup.h"
#include "Familija.h"
#include "Podfamilija.h"
using namespace std;


int main()
{
    Familija f;
    Podfamilija nova, podf, maximalna;
    vector<Podfamilija> podfamilije, disjunktnePodfamilije;

    int n=0;

    //ucitati broj skupova i dodijeliti nazive
    ifstream ucitaj;
    ucitaj.open("skupovi.txt");
    string linija;
    if(ucitaj.is_open())
    {
        while (getline(ucitaj,linija))
            {
                n++;
                Skup* s=new Skup('s',n);
                f.DodajSkup(s);
                podf.DodajSkup(s);
            }
    }
    ucitaj.close();

    cout<<endl<<"Zadani skupovi familije su:"<<endl;
    f.IspisiSkupove();
    cout<<endl;

    //spremiti disjunktne skupove za svaki skup
    f.UcitajDisjunktne();

    int brojSkupova=0;
    brojSkupova=f.dajBrojSkupova();
   // cout<<"broj skupova: "<<'\t'<<brojSkupova<<endl;

    int brojSkupovaPodf=0;
    brojSkupovaPodf=podf.dajBrojSkupova();
   // cout<<"broj skupova podfamilije: "<<'\t'<<brojSkupovaPodf<<endl;
    vector<Skup*> skupPodf;
    skupPodf=podf.dajElPodfamilije();
  //  podf.IspisiSkupove();

    //Određivanje najvecih podfamilija za pojedini skup
    for(int i=0; i<brojSkupova; i++)
    {
        skupPodf=podf.dajElPodfamilije();
        Podfamilija pf;
        pf=podf.OdrednjivanjePodfamilije(i, f, podf, skupPodf, brojSkupova, brojSkupovaPodf);
        podfamilije.push_back(pf);
    //    pf.IspisiSkupove();
    }

    //provjera disjunktnosti podfamilija
    for(int i=0; i<podfamilije.size(); i++)
    {
        Podfamilija temp=podfamilije.at(i);
        temp=temp.ProvjeraDisjunktnosti();
        disjunktnePodfamilije.push_back(temp);
       // temp.IspisiSkupove();
    }
    cout<<endl<<endl;
    maximalna=disjunktnePodfamilije.at(0);
    for(int i=0; i<disjunktnePodfamilije.size(); i++) //skupovi iz familije - kopirani i  u podfamiliju
    {
        Podfamilija temp=disjunktnePodfamilije.at(i);
        if(temp.dajBrojSkupova()>maximalna.dajBrojSkupova()) maximalna=temp;
     /*   cout<<endl<<endl;
        temp.IspisiSkupove();
        cout<<endl<<endl;*/
    }
    int maks=maximalna.dajBrojSkupova();
    vector<Skup*> disjunktni;
    disjunktni=maximalna.dajElPodfamilije();
    cout<<"Maksimalna podfamilija po praovima disjunktnih skupova je velièine: ";
    cout<<maks<<", a njeni elemnti su: "<<endl;
    maximalna.IspisiSkupove();

    return 0;
}
