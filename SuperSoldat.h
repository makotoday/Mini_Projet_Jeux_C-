#ifndef SUPERSOLDAT_H
#define SUPERSOLDAT_H

#include <Fantassin.h>

/*Un super soldat poss�de les meme caracteristique d'un fantassin, le changement se d�roule au moment des actions*/

class SuperSoldat : public Fantassin
{
    public:
        SuperSoldat(CJoueur& jr);
        virtual ~SuperSoldat();
        void action(int numAction, CAireJeux& aireJeu);
    private:
};

#endif // SUPERSOLDAT_H
