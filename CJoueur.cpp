#include "CJoueur.h"

CJoueur::CJoueur(string nom,int nombre_piece):m_nom(nom),m_nbPiece(nombre_piece){}

void CJoueur::print()const{
	cout<<"Nom : "<<m_nom<<endl;
	cout<<"Argent: "<<m_nbPiece<<endl;

}

void CJoueur::payeUnite(int prixUnite)
{
    if(m_nbPiece>=prixUnite)
    {
        m_nbPiece=m_nbPiece-prixUnite;

    }else{
        cout << "pas assez d'argent pour acheter cette unité" <<endl;
    }

}

void CJoueur::creationUnite(TypeUnite type)
{
    switch(type)
    {
  /*      case Uarcher :
        case Ufantassin :
        case Ucatapulte :*/
    }
}
