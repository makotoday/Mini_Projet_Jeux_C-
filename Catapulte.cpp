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
    type = Ucatapulte;
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
        case 2 : {if(!action3possible){
            if(ennemie==nullptr) avancer(AUCUN_ENNEMI);
            else avancer(ennemie->getPosition());break;}
        }
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
    int distance = valsAbsolue(position-ennemi->getPosition());
    if(distance >= porteeMin &&distance <=porteeMax)
    {
        ennemi->setpoints_de_vie(ennemi->getpoints_de_vie()-point_dAttaque);
        if(ennemi->getpoints_de_vie()<=0) ennemi->setMort();
        return true;//attaque reussie
    }
    else return false;//ennemi trop loin ou trop pres
}

bool Catapulte::peutAttaquerBase() const
{
    //Comme il y a pas d'ennemi, la catapulte attaque la base seulement si elle est a portée de la base adverse

    if(num_joueur==JOUEUR1 && (position+porteeMax >= 11 && position + porteeMin <=11 )) return true;
     if(num_joueur==JOUEUR2 && (position-porteeMax <= 0 && position -porteeMin >=0 )) return true;
	return false;
}

  int Catapulte::getPosEnnemiProche(int plateau[])
 {
      int numero_ennemi = (num_joueur==JOUEUR1)? JOUEUR2 : JOUEUR1;
	if(numero_ennemi==JOUEUR2){
		for(int i=position+porteeMin;i<CASE_MAX-1;i++){//portee minimale pris en compte pour la catapulte

			if(plateau[i]==numero_ennemi) return i;
		}
		return BASE;
	}else if (numero_ennemi==JOUEUR1){
		for(int i=position-1;i>0;i--){

			if(plateau[i]==numero_ennemi) return i;
			}
			return BASE;
	}
    else return CODE_ERREUR;
 }
