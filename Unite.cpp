#include "Unite.h"
#include <iostream>
#include "CAireJeux.h"

using namespace std;

//int Unite::prixUnite;

Unite::Unite(CJoueur& jr ): sonJoueur(jr), vivant(true)
{
if(jr.getNumeroJoueur()==JOUEUR1)
        position = 0;//case de la premeire base
else if(jr.getNumeroJoueur()==JOUEUR2)
    position = 11;//case de la seconde base
else throw string("ERREUR : mauvais numeroJoueur");
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
    cout << "position : " << position <<endl;
}

void Unite::avancer(CAireJeux& aireJeu)
{
    //verification que la case suivante est vide et selon le joueur avancer
    if(this->sonJoueur.getNumeroJoueur()==JOUEUR1&&aireJeu.getOccupation(position+1)==0)
    {
       position++;
    }else if(this->sonJoueur.getNumeroJoueur()==JOUEUR2&&aireJeu.getOccupation(position-1)==0)
    {
        position--;
    }
}

