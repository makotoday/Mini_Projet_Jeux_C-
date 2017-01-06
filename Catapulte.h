#ifndef CATAPULTE_H
#define CATAPULTE_H

#include "Unite.h"


class Catapulte : public Unite
{
    public:
        Catapulte(CJoueur& jr,int pos);
        static int porteeMin;
        virtual ~Catapulte();
        void print() const;
        void action(int numAction, Unite& ennemiProche);
        static int getPrixUnite(){return prixUnite;}
    private:
        static int prixUnite;
        bool attaquer(Unite& ennemiProche) const;
        bool action3possible;// vrai si la premiere action a reussi
};

#endif // CATAPULTE_H
