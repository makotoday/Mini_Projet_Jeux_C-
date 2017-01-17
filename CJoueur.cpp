#include "CJoueur.h"
#include "CAireJeux.h"
#include "Archer.h"
#include "Fantassin.h"
#include "Catapulte.h"
#include "SuperSoldat.h"

CJoueur::CJoueur(string nom,int nombre_piece,int pointvie, int joueur):m_nom(nom),m_nbPiece(nombre_piece), numeroJoueur(joueur),m_PointVie(pointvie){}


CJoueur::CJoueur(){}
void CJoueur::print()const{
	cout<<"Nom : "<<m_nom<<"\t\t";
	cout<<"Argent: "<<m_nbPiece<<endl;
	if(m_unite.size()==0) cout<<"Le Joueur n a pas unite sur le terrain"<<endl;
	else{

		for(unsigned int i=0; i<m_unite.size(); i++){
		cout<<"------------------Unite "<<i+1<<"-------------------\n";
		m_unite[i]->print();
		}
	}

}

void CJoueur::payeUnite(int prixUnite)
{
    if(m_nbPiece>=prixUnite)
    {
        m_nbPiece=m_nbPiece-prixUnite;

    }else{
       throw string("pas assez d'argent pour acheter cette unité");
    }

}

void CJoueur::creationUnite(TypeUnite type)
{
   switch(type)
    {
        case Uarcher :

		m_unite.push_back(new Archer(*this));
		break;

        case Ufantassin :
			m_unite.push_back(new Fantassin(*this));
			break;
        case Ucatapulte :
			m_unite.push_back(new Catapulte(*this));
			break;
	default : throw string("creation unite pas realiser");
    }
}


Unite* CJoueur::getUnitAt(int position)const{

	int size=m_unite.size();
	for(int i=0; i<size; i++){

		if(m_unite[i]->getPosition()==position) return m_unite[i];
	}
	return NULL;
}


void CJoueur::oterPV(int pv){

	m_PointVie=m_PointVie-pv;
}


TypeUnite CJoueur::choixUnite(){

	TypeUnite unite;
	srand(time(NULL));
	bool sortie=false;
	while(sortie==false){
		int tmp=rand()%3;
		if(tmp==0&&m_nbPiece>=Archer::getPrixUnite()){
			unite=Uarcher;
			payeUnite(Archer::getPrixUnite());
			sortie=true;

		}
		if(tmp==1&& m_nbPiece>=Fantassin::getPrixUnite()){
			unite=Ufantassin;
			payeUnite(Fantassin::getPrixUnite());
			sortie=true;
		}
		if(tmp==2&&m_nbPiece>=Catapulte::getPrixUnite()){
			unite=Ucatapulte;
			payeUnite(Catapulte::getPrixUnite());
			sortie=true;

		}
	}
	return unite;
}



CJoueur& CJoueur::operator=(const CJoueur& joueur){


	m_nom=joueur.m_nom;
	m_nbPiece=joueur.m_nbPiece;
	numeroJoueur=joueur.numeroJoueur;
	m_PointVie=joueur.m_PointVie;
	for(int i=0; i<m_unite.size();i++){
		delete m_unite[i];
	}
	m_unite.clear();
	for(int i=0; i<joueur.m_unite.size();i++){

		m_unite.push_back(joueur.m_unite[i]);
	}

	return *this;
}

void CJoueur::creationSuperSoldat(){
	int size=m_unite.size();
	for(int i=0;i<size;i++){

		if(typeid(*m_unite[i])==typeid(Fantassin)){
			Fantassin* soldat=dynamic_cast<Fantassin*>(m_unite[i]);
			if(soldat->getEvolution()==true){
				int position=soldat->getPosition();
				int pv=soldat->getpoints_de_vie();
				SuperSoldat* sup_soldat=new SuperSoldat(*this);
				sup_soldat->setpoints_de_vie(pv);
				sup_soldat->setPosition(position);
				m_unite.erase(m_unite.begin()+i);
				m_unite.emplace(m_unite.begin()+i,sup_soldat);
			}
		}

	}
}







