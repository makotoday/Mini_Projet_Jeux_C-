#ifndef CATAPULTE_H
#define CATAPULTE_H

#include "Unite.h"


class Catapulte : public Unite
{
    public:
        Catapulte(int joueur);
        static int porteeMin;
        virtual ~Catapulte();
        void print() const;
        void action(int numAction,Unite* ennemie);
        static int getPrixUnite(){return prixUnite;}
    private:
        static int prixUnite;
        bool attaquer(Unite* ennemi);
       // bool action3possible;// vrai si la premiere action a reussi
        //Unite* trouveEnnemiProche(CAireJeux& aireJeu) ;
        bool peutAttaquerBase() const;// si il n'y a pas d'ennemi on cible la base
};

#endif // CATAPULTE_H
