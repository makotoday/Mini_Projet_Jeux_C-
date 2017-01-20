#ifndef SUPERSOLDAT_H
#define SUPERSOLDAT_H

#include "Fantassin.h"
#include <iostream>
using namespace std;

/*Un super soldat poss�de les meme caracteristique d'un fantassin, le changement se d�roule au moment des actions*/

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
