#ifndef CATAPULTE_H
#define CATAPULTE_H

#include "Unite.h"


class Catapulte : public Unite
{
    public:
        Catapulte(CJoueur& jr);
        static int porteeMin;
        virtual ~Catapulte();
        void print() const;
        void action(int numAction, CAireJeux& aireJeu);
        static int getPrixUnite(){return prixUnite;}
    private:
        static int prixUnite;
        bool attaquer(Unite& ennemiProche) const;
        bool action3possible;// vrai si la premiere action a reussi
        Unite* trouveEnnemiProche(CAireJeux& aireJeu) ;
};

#endif // CATAPULTE_H
