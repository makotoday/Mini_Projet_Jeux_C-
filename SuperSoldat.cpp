#include "SuperSoldat.h"

SuperSoldat::SuperSoldat(int jr) : Fantassin(jr)
{
    type = USuperSoldat;
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
        case 1 :
            if(ennemie==nullptr) avancer(AUCUN_ENNEMI);
            else avancer(ennemie->getPosition());
            break;
        case 2 : {
            //action 3 toujours possible
            attaquer(ennemie);break;}
        //default : throw string("action inconnue pour le superSoldat");
    }
}
