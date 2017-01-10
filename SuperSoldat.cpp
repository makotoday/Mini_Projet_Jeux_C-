#include "SuperSoldat.h"

SuperSoldat::SuperSoldat(CJoueur& jr) : Fantassin(jr)
{
    //ctor
}

SuperSoldat::~SuperSoldat()
{
    //dtor
}

void SuperSoldat::action(int numAction, CAireJeux& aireJeu)
{
    switch(numAction)
    {
        case 0 : {
                //action attaquer
            Unite* ennemiProche = trouveEnnemiProche(aireJeu);
            action3possible = !attaquer(ennemiProche);break;}
        case 1 : avancer(aireJeu);break;
        case 2 : {
            Unite* ennemiProche = trouveEnnemiProche(aireJeu);
            //action 3 toujours possible
            attaquer(ennemiProche);break;}
        default : throw string("action inconnue pour le superSoldat");
    }
}
