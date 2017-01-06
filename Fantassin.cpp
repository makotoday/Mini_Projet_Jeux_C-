#include "Fantassin.h"
#include <iostream>

using namespace std;


int Fantassin::prixUnite = 10;


Fantassin::Fantassin(CJoueur& jr,int pos) : Unite(jr,pos)
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

void Fantassin::action(int numAction, Unite& ennemiProche)
{
    switch(numAction)
    {
        case 0 : {action3possible = !attaquer(ennemiProche);break;}
        case 1 : avancer();break;
        case 2 : {if(action3possible) attaquer(ennemiProche);break;}
        default : throw string("action inconnue pour le fantassin");
    }
}

bool Fantassin::attaquer(Unite& ennemiProche) const
{
    if(valsAbsolue(position - ennemiProche.getPosition())<=porteeMax) //la distance avec l'ennemi doit etre <= à la portée
    {
        ennemiProche.setpoints_de_vie(ennemiProche.getpoints_de_vie() - this->point_dAttaque);
        if(ennemiProche.getpoints_de_vie()<=0) ennemiProche.setMort();
        return true;
    }else return false;
}

