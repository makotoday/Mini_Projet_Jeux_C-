#ifndef SUPERSOLDAT_H
#define SUPERSOLDAT_H

#include <Fantassin.h>

/*Un super soldat possède les meme caracteristique d'un fantassin, le changement se déroule au moment des actions*/

class SuperSoldat : public Fantassin
{
    public:
        SuperSoldat(CJoueur& jr);
        virtual ~SuperSoldat();
        void action(int numAction, CAireJeux& aireJeu);
    private:
};

#endif // SUPERSOLDAT_H
