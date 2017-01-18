#include "Fantassin.h"
#include <iostream>

using namespace std;


int Fantassin::prixUnite = 10;


Fantassin::Fantassin(int joueur) : Unite(joueur)
{
    points_de_vie = 10;
    point_dAttaque = 4;
    porteeMax = 1;
    type = Ufantassin;
}

Fantassin::~Fantassin()
{
    //dtor
}

void Fantassin::print() const
{
    cout << "Fantassin" <<endl;
    Unite::print();
}


void Fantassin::action(int numAction,Unite* ennemie)
{
    switch(numAction)
    {
        case 0 : {
                //action attaquer
                //Unite* ennemiProche = trouveEnnemiProche(aireJeu);
            action3possible = !attaquer(ennemie);break;}
        case 1 : avancer();break;
        case 2 : {
            Unite* ennemiProche = ennemie;
            if(action3possible&&ennemiProche!=NULL) attaquer(ennemiProche);break;}
        //default : throw string("action inconnue pour le fantassin");
    }
}

bool Fantassin::attaquer(Unite* ennemi)
{
    if(ennemi==NULL)//pas d'unité ennemi
    {
        if(peutAttaquerBase())
        {
            //enlever pv a la base
            return true;
        }
        else return false;// rien à attaquer
    }
    Unite& ennemiProche = *ennemi;
    if(valsAbsolue(position - ennemiProche.getPosition())<=porteeMax) //la distance avec l'ennemi doit etre <= à la portée
    {
        ennemiProche.setpoints_de_vie(ennemiProche.getpoints_de_vie() - this->point_dAttaque);
        if(ennemiProche.getpoints_de_vie()<=0){
			 ennemiProche.setMort();
			 evolution=true;
		 }
        return true;
    }
    else return false;
}
