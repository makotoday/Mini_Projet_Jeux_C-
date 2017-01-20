#ifndef FANTASSIN_H
#define FANTASSIN_H

#include "Unite.h"
#include <iostream>
using namespace std;


class Fantassin : public Unite
{
    public:
        Fantassin(int joueur);
        virtual ~Fantassin();
           void action(int numAction,Unite* ennemie);
        void print() const;
        static int getPrixUnite(){return prixUnite;}
    protected :
        virtual bool attaquer(Unite* ennemi);
void print_avance();
        //bool action3possible;//vrai : l'action 3 est possible
    private:
        static int prixUnite;

};

#endif // FANTASSIN_H
