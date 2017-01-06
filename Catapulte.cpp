#include "Catapulte.h"
#include <iostream>

using namespace std;

int Catapulte::prixUnite = 20;
int Catapulte::porteeMin = 2;

Catapulte::Catapulte(CJoueur& jr,int pos) :Unite(jr,pos)
{
    points_de_vie = 10;
    point_dAttaque = 3;
    porteeMax = 3;
}

Catapulte::~Catapulte()
{

}

void Catapulte::print() const
{
    cout << "Catapulte" <<endl;
    Unite::print();
}

void Catapulte::action(int numAction, Unite& ennemiProche)
{
    switch(numAction)
    {
        case 0 : {action3possible = !attaquer(ennemiProche);break;}
        case 1 : return;// l'action 2 n'existe pas pour la catapulte
        case 2 : {if(action3possible) avancer();break;}
        default : throw string("action inconnue pour la catapulte");
    }
}

bool Catapulte::attaquer(Unite& ennemiProche) const
{
    int distance = valsAbsolue(position-ennemiProche.getPosition());
    if(distance >= porteeMin &&distance <=porteeMax)
    {
        ennemiProche.setpoints_de_vie(ennemiProche.getpoints_de_vie()-point_dAttaque);
        if(ennemiProche.getpoints_de_vie()<=0) ennemiProche.setMort();
        return true;
    }
    else return false;
}

