#include "Unite.h"
#include <iostream>
#include "CAireJeux.h"

using namespace std;

//int Unite::prixUnite;

Unite::Unite(CJoueur& jr , int pos): vivant(true)
{
    sonJoueur = jr;
    if(!EstDansAireDeJeu(pos)) throw string("ERREUR : mauvaise position");
    else{

        position = pos;
    }
}

Unite::~Unite()
{
    //dtor
}

void Unite::print() const
{
    //affichage des caracteristiques communs des unités
    cout << "PV : " << points_de_vie <<endl;
    cout << " points d attaque : "<<point_dAttaque << endl;
    cout << "porteeMax : " <<porteeMax <<endl;
}

bool Unite::avancer(/*CAireJeux& aireJeu*/)
{
    //verification que la case suivante est vide
 /*   if(aireJeu.getOccupation(position))
    {
       position++;
       return true;
    }else*/
     return false;
}
