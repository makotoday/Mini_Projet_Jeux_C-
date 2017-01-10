
#ifndef ARCHER_H
#define ARCHER_H
#include "Unite.h"

class Archer : public Unite
{
    public:
        Archer(CJoueur& jr);
        virtual ~Archer();
        void action(int numAction, CAireJeux& aireJeu);
        void print() const;
        static int getPrixUnite(){return prixUnite;}

    protected:
    private:
        static int prixUnite;
        bool attaquer(Unite& ennemiProche) const;
        Unite* trouveEnnemiProche(CAireJeux& aireJeu);
};



#endif // ARCHER_H
