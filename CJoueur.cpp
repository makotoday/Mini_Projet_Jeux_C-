#include "CJoueur.h"

CJoueur::CJoueur(string nom,int nombre_piece):m_nom(nom),m_nbPiece(nombre_piece){	}

void CJoueur::print()const{
	cout<<"Nom : "<<m_nom<<endl; 	
	cout<<"Argent: "<<m_nbPiece<<endl; 

}
