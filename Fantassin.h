#ifndef FANTASSIN_H
#define FANTASSIN_H

#include "Unite.h"


class Fantassin : public Unite
{
    public:
        Fantassin(CJoueur& jr,int pos);
        virtual ~Fantassin();
        void action(int numAction, Unite& ennemiProche);
        void print() const;
        static int getPrixUnite(){return prixUnite;}

    private:
        static int prixUnite;
        bool attaquer(Unite& ennemiProche) const;
        bool action3possible;//vrai : l'action 3 est possible
};

#endif // FANTASSIN_H
