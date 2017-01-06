#ifndef ARCHER_H
#define ARCHER_H

#include "Unite.h"


class Archer : public virtual Unite
{
    public:
        Archer(CJoueur& jr,int pos);
        virtual ~Archer();
        void action(int numAction, Unite& ennemiProche);
        void print() const;
        static int getPrixUnite(){return prixUnite;}

    protected:
    private:
        static int prixUnite;
        bool attaquer(Unite& ennemiProche) const;
};



#endif // ARCHER_H
