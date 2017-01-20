
#ifndef ARCHER_H
#define ARCHER_H
#include "Unite.h"

class Archer : public Unite
{
    public:
        Archer(int joueur);
        virtual ~Archer();
        void action(int numAction,Unite* ennemie);
        void print() const;
        static int getPrixUnite(){return prixUnite;}

    protected:
    private:
        static int prixUnite;
        bool attaquer(Unite* ennemi);
        void avancer();
};



#endif // ARCHER_H
