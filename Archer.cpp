#include "Archer.h"
#include <iostream>

using namespace std;

int Archer::prixUnite = 12;

Archer::Archer(int joueur) : Unite(joueur)
{
    points_de_vie = 8;
    point_dAttaque = 3;
    porteeMax = 3;
    type = Uarcher;
}

Archer::~Archer()
{
    //dtor
    cout<<"UNITE ARCHER DETRUITR \n";
}

void Archer::action(int numAction,Unite* ennemie)
{
    //l'archer attaque puis essaye d'avancer toujours
    switch(numAction)
    {
        case 0 : {

                action3possible=attaquer(ennemie);
                break;
            }
        case 1 : {//avancer
            if(ennemie==nullptr) avancer(AUCUN_ENNEMI);
            else avancer(ennemie->getPosition()); break;}
        case 2 : break;
       // default : throw string("action inconnue pour l'archer");
    }
}


void Archer::print() const
{
    cout << "Archer" <<endl;
    Unite::print();
}

bool Archer::attaquer(Unite* ennemi)
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
    if(valsAbsolue(position - ennemi->getPosition())<=porteeMax) //la distance avec l'ennemi doit etre <= à la portée
    {
        ennemi->setpoints_de_vie(ennemi->getpoints_de_vie() - this->point_dAttaque);
        if(ennemi->getpoints_de_vie()<=0) ennemi->setMort();
        cout<<"Archer "<<num_joueur<<" attaque ennemi\n";
        cout<<"position : "<<position<<"\t\t\t position ennemi "<<ennemi->getPosition()<<endl;
        cout<<"PV : "<<points_de_vie<<"\t\t\t PV ennemi : "<<ennemi->getpoints_de_vie()<<endl;
        return true;
    }else return false;
}



void Archer::print_avance(){

cout<<"Unite Archer avance \n";

}

