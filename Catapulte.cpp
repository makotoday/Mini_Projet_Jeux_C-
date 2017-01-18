#include "Catapulte.h"
#include <iostream>

using namespace std;

int Catapulte::prixUnite = 20;
int Catapulte::porteeMin = 2;

Catapulte::Catapulte(int joueur) :Unite(joueur)
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

void Catapulte::action(int numAction,Unite *ennemie)
{
    switch(numAction)
    {
        case 0 : {
                    //trouve l'ennemi 2 ou 3 cases plus loin :
                    
                    //verifie si il est à portée puis attaque :
                     action3possible = attaquer(ennemie);
                     //attaque sur la case à coté (selon le joueur)
                    /* if(m_num_joueur==1){
                     action3possible += attaquer(ennemie);
                     } else*/  action3possible += attaquer(ennemie);
                     break;
                }
        case 1 : break;// l'action 2 n'existe pas pour la catapulte
        case 2 : {if(action3possible) avancer();break;}
       // default : throw string("action inconnue pour la catapulte");
    }
}

bool Catapulte::attaquer(Unite* ennemi)
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
    
    if(num_joueur==JOUEUR1 && (position+porteeMax >= 11 && position + porteeMin <=11 )) return true; 
     if(num_joueur==JOUEUR1 && (position-porteeMax <= 0 && position -porteeMin >=0 )) return true;
	return false; 
}

/*Unite* Catapulte::trouveEnnemiProche(CAireJeux& aireJeu)
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
*/
