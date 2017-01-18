#include "Unite.h"
#include <iostream>


using namespace std;

//int Unite::prixUnite;

Unite::Unite(int joueur ): num_joueur(joueur), vivant(true)
{
if(num_joueur==JOUEUR1) position = 0;//case de la premeire base
if(num_joueur==JOUEUR2) position = 11;//case de la seconde base
//else throw string("ERREUR : mauvais numeroJoueur");
evolution=false;
action3possible=false;
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

void Unite::avancer()
{
    //verification que la case suivante est vide et selon le joueur avancer
    if(num_joueur==JOUEUR1)
    {
       position++;
    }else if(num_joueur==JOUEUR2)
    {
        position--;
    }
}

bool Unite::peutAttaquerBase() const//pour un fantassin et un archer
{
	if(num_joueur==JOUEUR1 && position +porteeMax >= 11) return true;
	if(num_joueur==JOUEUR1 && position +porteeMax <= 0) return true;
	return false;
}


 int Unite::getPosEnnemiProche(int plateau[])
 {
     int numero_ennemi = (num_joueur==JOUEUR1)? JOUEUR2 : JOUEUR1;//numero de l'ennemi
	if(numero_ennemi==JOUEUR2){
		for(int i=position+1;i<CASE_MAX-1;i++){

			if(plateau[i]==numero_ennemi) return i;
		}
		return BASE;//i =11
	}else if(numero_ennemi==JOUEUR1){
		for(int i=position-1;i>0;i--){

			if(plateau[i]==numero_ennemi) return i;
			}
            return BASE;//i = 0
	}
    else return CODE_ERREUR;
 }

void Unite::oterPV(int pv){
	points_de_vie=points_de_vie-pv;

}
