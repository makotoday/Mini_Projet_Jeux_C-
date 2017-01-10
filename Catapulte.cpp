#include "Catapulte.h"
#include <iostream>

using namespace std;

int Catapulte::prixUnite = 20;
int Catapulte::porteeMin = 2;

Catapulte::Catapulte(CJoueur& jr) :Unite(jr)
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

void Catapulte::action(int numAction, CAireJeux& aireJeu)
{
    switch(numAction)
    {
        case 0 : {
                    Unite* ennemiProche = trouveEnnemiProche(aireJeu);
                    if(ennemiProche !=NULL)
                     action3possible = attaquer(*ennemiProche);//verifie si il est à portée puis attaque
                     break;
                }
        case 1 : return;// l'action 2 n'existe pas pour la catapulte
        case 2 : {if(action3possible) avancer(aireJeu);break;}
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
        return true;//attaque reussie
    }
    else return false;//attaque impossible
}

 Unite* Catapulte::trouveEnnemiProche(CAireJeux& aireJeu)
{
     if(sonJoueur.getNumeroJoueur()==JOUEUR1)
     {
        for(int i = position+2;i <11;i++)
        {
            if(aireJeu.getOccupation(i)==JOUEUR2)
            {
                return &(aireJeu.getUniteAt(i));
            }
        }
        action3possible = true; //pas d'ennemi sur le plateau donc la catapulte avance
        return NULL;
    }
    else
    {
        for(int i = position-2;i >0;i--)
        {
            if(aireJeu.getOccupation(i)==JOUEUR1)
            {
                return &(aireJeu.getUniteAt(i));
            }
        }
        action3possible = true;
        return NULL;
    }
}
