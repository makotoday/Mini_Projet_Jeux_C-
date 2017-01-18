#ifndef SUPERSOLDAT_H
#define SUPERSOLDAT_H

#include "Fantassin.h"

/*Un super soldat possède les meme caracteristique d'un fantassin, le changement se déroule au moment des actions*/

class SuperSoldat : public Fantassin
{
    public:
        SuperSoldat(int jr);
        virtual ~SuperSoldat();
        void action(int numAction, Unite* ennemie);
    private:
};

#endif // SUPERSOLDAT_H
