#include <iostream>
#include <string>
#ifndef CJOUEUR_H
#define CJOUEUR_H

using namespace std;

enum TypeUnite{Uarcher,Ufantassin,Ucatapulte};

class CJoueur{

    private :
        string m_nom;//
        int  m_nbPiece; //nombre de piece du  joueur
        //On definit le numeroJoueur soit 0 soit 1 avec 0 correspondant à la tour en position 0
        int numeroJoueur;
	public:

		CJoueur(string nom, int nombre_piece);
		string getNom()const{return m_nom;};// retourne le nom du joueur
		int getNombrePiece()const{return m_nbPiece;}; //retourne le nombre de piece du joueur
		void payeUnite(int prixUnite);// la methode  retire la somme dü pour la creation de l'unité
		void gain(int sommeRecu){m_nbPiece=m_nbPiece+sommeRecu;};// la methode permet d'augmenter le  nombre de piece  par le nombre gagner
		void setNom(string nom){m_nom=nom; };
		void setNombrePiece(int nb_piece){m_nbPiece=nb_piece;};
		void print()const;

        void creationUnite(TypeUnite type);


};


#endif
