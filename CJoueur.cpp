#include "CJoueur.h"
#include "Archer.h"
#include "Fantassin.h"
#include "Catapulte.h"
#include "SuperSoldat.h"

CJoueur::CJoueur(string nom,int nombre_piece,int pointvie, int joueur):m_nom(nom),m_nbPiece(nombre_piece), numeroJoueur(joueur),m_PointVie(pointvie){ }

CJoueur::CJoueur(const CJoueur& joueur){
	
	m_nom=joueur.m_nom; 
	m_nbPiece=joueur.m_nbPiece; 
	numeroJoueur=joueur.numeroJoueur; 
	m_PointVie=joueur.m_PointVie; 
	for(int i=0; i<joueur.m_unite.size();i++){

		m_unite.push_back(joueur.m_unite[i]);
	}
	
}

CJoueur::CJoueur(){ }
void CJoueur::print()const{
	cout<<"Nom : "<<m_nom<<"\t\t";
	cout<<"Argent: "<<m_nbPiece<<endl;
	if(m_unite.size()==0) cout<<"Le Joueur n a pas unite sur le terrain"<<endl;
	else{
		cout<<"----------------------------------------------LES UNITES DU JOUEUR -------------------------------------------\n"; 
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

    }
    /*else{
       throw string("pas assez d'argent pour acheter cette unité");
    }*/

}

void CJoueur::creationUnite(TypeUnite type)
{
   switch(type)
    {
        case Uarcher :

		m_unite.push_back(new Archer(this->numeroJoueur));
		this->payeUnite(Archer::getPrixUnite()); 
		break;

        case Ufantassin :
			m_unite.push_back(new Fantassin(this->numeroJoueur));
			this->payeUnite(Fantassin::getPrixUnite()); 
			break;
        case Ucatapulte :
			m_unite.push_back(new Catapulte(this->numeroJoueur));
			this->payeUnite(Catapulte::getPrixUnite()); 
			break;
	default : cout<<"PAS DE CREATION D UNITE \n";break; 
    }
}


Unite* CJoueur::getUnitAt(int position){

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
	int tentative=0; 
	while(sortie==false){
		int tmp=rand()%6;
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
		if(tmp==3){
			
		unite=UPASSTOUR;
		sortie=true; 
		}  
		if(tmp==4){
		unite=UPASSTOUR;
		sortie=true; 
		}
		if(tmp==5){
		unite=UPASSTOUR;
		sortie=true;
		}  
		tentative++; 
		if(tentative==10){
			 
		unite=UPASSTOUR;
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
				SuperSoldat* sup_soldat=new SuperSoldat(this->getNumeroJoueur());
				sup_soldat->setpoints_de_vie(pv);
				sup_soldat->setPosition(position);
				m_unite.erase(m_unite.begin()+i);
				m_unite.emplace(m_unite.begin()+i,sup_soldat);
			}
		}

	}
}







