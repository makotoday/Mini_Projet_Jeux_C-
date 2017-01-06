#include "Archer.h"
#include <iostream>

using namespace std;

int Archer::prixUnite = 12;

Archer::Archer(CJoueur& jr, int pos) : Unite(jr,pos)
{
    points_de_vie = 8;
    point_dAttaque = 3;
    porteeMax = 3;
}

Archer::~Archer()
{
    //dtor
}

void Archer::action(int numAction, Unite& ennemiProche)
{
    //l'archer attaque puis essaye d'avancer toujours
    switch(numAction)
    {
        case 0 : {attaquer(ennemiProche);break;}
        case 1 : {avancer(); break;}
        case 2 : return;
        default : throw string("action inconnue pour l'archer");
    }
}

void Archer::print() const
{
    cout << "Archer" <<endl;
    Unite::print();
}

bool Archer::attaquer(Unite& ennemiProche) const
{
    if(valsAbsolue(position - ennemiProche.getPosition())<=porteeMax) //la distance avec l'ennemi doit etre <= � la port�e
    {
        ennemiProche.setpoints_de_vie(ennemiProche.getpoints_de_vie() - this->point_dAttaque);
        if(ennemiProche.getpoints_de_vie()<=0) ennemiProche.setMort();
        return true;
    }else return false;
}

