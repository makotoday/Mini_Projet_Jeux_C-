#ifndef SUPERSOLDAT_H
#define SUPERSOLDAT_H

#include "Fantassin.h"

/*Un super soldat poss�de les meme caracteristique d'un fantassin, le changement se d�roule au moment des actions*/

class SuperSoldat : public Fantassin
{
    public:
        SuperSoldat(int jr);
        virtual ~SuperSoldat();
        void action(int numAction, Unite* ennemie);
    private:
};

#endif // SUPERSOLDAT_H
