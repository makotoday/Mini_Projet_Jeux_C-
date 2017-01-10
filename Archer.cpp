#include "Archer.h"
#include <iostream>

using namespace std;

int Archer::prixUnite = 12;

Archer::Archer(CJoueur& jr) : Unite(jr)
{
    points_de_vie = 8;
    point_dAttaque = 3;
    porteeMax = 3;
}

Archer::~Archer()
{
    //dtor
}

void Archer::action(int numAction, CAireJeux& aireJeu)
{
    //l'archer attaque puis essaye d'avancer toujours
    switch(numAction)
    {
        case 0 : {
                Unite* ennemiProche = trouveEnnemiProche(aireJeu);
                attaquer(ennemiProche);break;
            }
        case 1 : {avancer(aireJeu); break;}
        case 2 : break;
        default : throw string("action inconnue pour l'archer");
    }
}


void Archer::print() const
{
    cout << "Archer" <<endl;
    Unite::print();
}

bool Archer::attaquer(Unite* ennemi) const
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
    }else return false;
}


