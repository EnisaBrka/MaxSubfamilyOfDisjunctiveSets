#ifndef SKUP_H
#define SKUP_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Skup
{
    private:
        string naziv;
        int indeks;
        vector<Skup*> disjunktni;
    public:
        Skup();
        Skup(char,int);
        string dajNaziv(){return naziv;};
        vector<Skup*> dajDisjunktne(){return disjunktni;};
        int dajIndeks(){return indeks;};
        void DodajDisjunktne(Skup*);
        void IspisiDisjunktne();
        int DajBrojDisjunktnih();
        virtual ~Skup();
};

#endif // SKUP_H
