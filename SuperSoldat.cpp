#include "SuperSoldat.h"

SuperSoldat::SuperSoldat(int jr) : Fantassin(jr)
{
    //ctor
}

SuperSoldat::~SuperSoldat()
{
    //dtor
}

void SuperSoldat::action(int numAction, Unite* ennemie)
{
    switch(numAction)
    {
        case 0 : {
                //action attaquer
            action3possible = !attaquer(ennemie);break;}
        case 1 : avancer();break;
        case 2 : {
            Unite* ennemiProche = ennemie;
            //action 3 toujours possible
            attaquer(ennemie);break;}
        //default : throw string("action inconnue pour le superSoldat");
    }
}
