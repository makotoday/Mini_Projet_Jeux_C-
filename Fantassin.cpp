#include "Fantassin.h"
#include <iostream>

using namespace std;


int Fantassin::prixUnite = 10;


Fantassin::Fantassin(CJoueur& jr) : Unite(jr)
{
    points_de_vie = 10;
    point_dAttaque = 4;
    porteeMax = 1;
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


void Fantassin::action(int numAction, CAireJeux& aireJeu)
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
            if(action3possible&&ennemiProche!=NULL) attaquer(ennemiProche);break;}
        default : throw string("action inconnue pour le fantassin");
    }
}

bool Fantassin::attaquer(Unite* ennemi) const
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
        if(ennemiProche.getpoints_de_vie()<=0) ennemiProche.setMort();
        return true;
    }
    else return false;
}
