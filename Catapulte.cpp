#include "Catapulte.h"
#include <iostream>

using namespace std;

int Catapulte::prixUnite = 20;
int Catapulte::porteeMin = 2;

Catapulte::Catapulte(CJoueur& jr) :Unite(jr)
{
    points_de_vie = 10;
    point_dAttaque = 3;
    porteeMax = 3;//portée réelle de 4 car elle tire 4 cases plus loin en visant 3
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
                    //trouve l'ennemi 2 ou 3 cases plus loin :
                    Unite* ennemiProche = trouveEnnemiProche(aireJeu);
                    //verifie si il est à portée puis attaque :
                     action3possible = attaquer(ennemiProche);
                     //attaque sur la case à coté (selon le joueur)
                     if(sonJoueur.getNumeroJoueur()==1){
                     action3possible += attaquer(aireJeu.getUniteAt(position+1));
                     } else  action3possible += attaquer(aireJeu.getUniteAt(position-1));
                     break;
                }
        case 1 : break;// l'action 2 n'existe pas pour la catapulte
        case 2 : {if(action3possible) avancer(aireJeu);break;}
        default : throw string("action inconnue pour la catapulte");
    }
}

bool Catapulte::attaquer(Unite* ennemi) const
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
    int distance = valsAbsolue(position-ennemiProche.getPosition());
    if(distance >= porteeMin &&distance <=porteeMax)
    {
        ennemiProche.setpoints_de_vie(ennemiProche.getpoints_de_vie()-point_dAttaque);
        if(ennemiProche.getpoints_de_vie()<=0) ennemiProche.setMort();
        return true;//attaque reussie
    }
    else return false;//ennemi trop loin ou trop pres
}

bool Catapulte::peutAttaquerBase() const
{
    //Comme il y a pas d'ennemi, la catapulte attaque la base seulement si elle est a portée de la base adverse
    return (sonJoueur.getNumeroJoueur()==1&&(position+porteeMax >= 11 && position + porteeMin <=11 ))
    || (sonJoueur.getNumeroJoueur()==2&&(position-porteeMax <= 0 && position - porteeMin >=0 ));
}

Unite* Catapulte::trouveEnnemiProche(CAireJeux& aireJeu)
{
     if(sonJoueur.getNumeroJoueur()==JOUEUR1)
     {
        for(int i = position+2;i <=11;i++)
        {
            if(aireJeu.getOccupation(i)==JOUEUR2)
            {
                return aireJeu.getUniteAt(i);
            }
        }
        action3possible = true; //pas d'ennemi sur le plateau donc la catapulte avance
        return NULL;
    }
    else
    {
        for(int i = position-2;i >=0;i--)
        {
            if(aireJeu.getOccupation(i)==JOUEUR1)
            {
                return aireJeu.getUniteAt(i);
            }
        }
        action3possible = true;
        return NULL;
    }
}
