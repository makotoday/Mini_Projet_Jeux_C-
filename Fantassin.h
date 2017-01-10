#ifndef FANTASSIN_H
#define FANTASSIN_H

#include "Unite.h"


class Fantassin : public Unite
{
    public:
        Fantassin(CJoueur& jr);
        virtual ~Fantassin();
           void action(int numAction, CAireJeux& aireJeu);
        void print() const;
        static int getPrixUnite(){return prixUnite;}
    protected :
        virtual bool attaquer(Unite* ennemi) const;
        bool action3possible;//vrai : l'action 3 est possible
    private:
        static int prixUnite;

};

#endif // FANTASSIN_H
