#ifndef FAMILIJA_H
#define FAMILIJA_H
#include "Skup.h"
#include <vector>
class Skup;
class Familija
{
    private:
        vector<Skup*> skupovi;
        int brojSkupova;
    public:
        Familija();
        int dajBrojSkupova(){return brojSkupova;};
        void DodajSkup(Skup*);
        void IspisiSkupove();
        void UcitajDisjunktne();
        bool NadjiSkup(int);
        Skup* NadjiDSkup(int);
        virtual ~Familija();
};

#endif // FAMILIJA_H
