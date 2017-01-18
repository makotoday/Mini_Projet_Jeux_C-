
#ifndef __CJOUEUR_H__
#define __CJOUEUR_H__


#include <string>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <typeinfo>
#include "Unite.h"
#include <iostream>


using namespace std;


//enum TypeUnite{Uarcher,Ufantassin,Ucatapulte,UPASSTOUR};


class CJoueur {
    //friend class CAireJeux;
    private :
        string m_nom;//
        int  m_nbPiece; //nombre de piece du  joueur
        //On definit le numeroJoueur soit 1 (base en case 0) soit 2 (base en case 11)
        int numeroJoueur;
		int m_PointVie;// le nombre de point de vie du joueur, il baissera quand sa tour sera attaqué
		vector<Unite*> m_unite;// un tableau dynamique permetant de stocker les unitées

	public:

        CJoueur();
		CJoueur(string nom, int nombre_piece,int pointvie,int numero);
		CJoueur(const CJoueur &joueur);
		string getNom()const{return m_nom;};// retourne le nom du joueur
		int getNombrePiece()const{return m_nbPiece;}; //retourne le nombre de piece du joueur
		void payeUnite(int prixUnite);// la methode  retire la somme dü pour la creation de l'unité
		void gain(int sommeRecu){m_nbPiece=m_nbPiece+sommeRecu;};// la methode permet d'augmenter le  nombre de piece  par le nombre gagner
		void setNom(string nom){m_nom=nom; };
		void setNombrePiece(int nb_piece){m_nbPiece=nb_piece;};

		void print()const;
        void creationUnite(TypeUnite type);
		int getNumeroJoueur()const{return numeroJoueur;};
		vector<Unite*> getTableauxUnite(){return m_unite; };
		Unite* getUnitAt(int position);
		void oterPV(int pv);// la methode permet de retirer  les points de vie du joueur, uniquement quand l'adversaire l'attaque directement
		int getPointVie()const{return m_PointVie;};// permet de voir la constante

		TypeUnite choixUnite();// la methode  permet de choisir aléatoirement l'unité à créer

		CJoueur& operator=(const CJoueur& joueur);
		void creationSuperSoldat();//la méthode permet de verifier si  on un soldat peut devenir un super soldat


};

#endif
