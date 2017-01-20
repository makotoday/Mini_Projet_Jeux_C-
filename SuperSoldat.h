#ifndef SUPERSOLDAT_H
#define SUPERSOLDAT_H

#include "Fantassin.h"
#include <iostream>
using namespace std;

/*Un super soldat possède les meme caracteristique d'un fantassin, le changement se déroule au moment des actions*/

class SuperSoldat : public Fantassin
{
    public:
        SuperSoldat(int jr);
        virtual ~SuperSoldat();
        void action(int numAction, Unite* ennemie);
         bool attaquer(Unite* ennemi);
         void avancer();
    private:
};

#endif // SUPERSOLDAT_H
