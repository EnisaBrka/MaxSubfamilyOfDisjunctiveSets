#ifndef PODFAMILIJA_H
#define PODFAMILIJA_H
#include "Skup.h"
#include "Familija.h"
#include <vector>

class Podfamilija
{
    private:
        vector<Skup*> skupovi;
        int brojSkupova;
    public:
        Podfamilija();
        int dajBrojSkupova(){return brojSkupova;};
        vector<Skup*> dajElPodfamilije(){return skupovi;};
        void DodajSkup(Skup*);
        bool NadjiElemenatUskupuPodf(int);
        Podfamilija OdrednjivanjePodfamilije(int, Familija&, Podfamilija&, vector<Skup*>&, int&, int&);
        Podfamilija ProvjeraDisjunktnosti();
        void IspisiSkupove();
        virtual ~Podfamilija();
};

#endif // PODFAMILIJA_H
