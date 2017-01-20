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
	for(unsigned int i=0; i<joueur.m_unite.size();i++){

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
		cout<<"CREATION UNITE ARCHER\n";
		break;

        case Ufantassin :
			m_unite.push_back(new Fantassin(this->numeroJoueur));
			this->payeUnite(Fantassin::getPrixUnite());
			cout<<"CREATION UNITE FANTASSIN\n";
			break;
        case Ucatapulte :
			m_unite.push_back(new Catapulte(this->numeroJoueur));
			this->payeUnite(Catapulte::getPrixUnite());
			cout<<"CREATION UNITE CATAPULTE\n";
			break;
	default : cout<<"PAS DE CREATION D UNITE \n";break;
    }
}


Unite* CJoueur::getUnitAt(int position){
	for(unsigned int i=0; i<m_unite.size(); i++){
		if(m_unite[i]->getPosition()==position) return m_unite[i];
	}
	return NULL;
}


void CJoueur::oterPV(int pv){

	m_PointVie=m_PointVie-pv;
}


TypeUnite CJoueur::choixUnite(){
    // strategie : l'IA tente d'acheter une unité au hasard, si il y arrive pas alors il passe son tour

	TypeUnite unite;
	//srand(time(NULL));


		int tmp=rand()%4;//entre 0 et 3
		if(tmp==0&&m_nbPiece>=Archer::getPrixUnite()){
			unite=Uarcher;
			payeUnite(Archer::getPrixUnite());

		}
		else if(tmp==1&& m_nbPiece>=Fantassin::getPrixUnite()){
			unite=Ufantassin;
			payeUnite(Fantassin::getPrixUnite());
		}
		else if(tmp==2&&m_nbPiece>=Catapulte::getPrixUnite()){
			unite=Ucatapulte;
			payeUnite(Catapulte::getPrixUnite());

		}
		else unite=UPASSTOUR;

	return unite;
}



CJoueur& CJoueur::operator=(const CJoueur& joueur){


	m_nom=joueur.m_nom;
	m_nbPiece=joueur.m_nbPiece;
	numeroJoueur=joueur.numeroJoueur;
	m_PointVie=joueur.m_PointVie;
	for(unsigned int i=0; i<m_unite.size();i++){
		delete m_unite[i];
	}
	m_unite.clear();
	for(unsigned int i=0; i<joueur.m_unite.size();i++){

		m_unite.push_back(joueur.m_unite[i]);
	}

	return *this;
}

void CJoueur::creationSuperSoldat(){
	int size=m_unite.size();
	for(int i=0;i<size;i++){

		if(m_unite[i]->quelleType()==Ufantassin){
			Fantassin* soldat=dynamic_cast<Fantassin*>(m_unite[i]);
			if(soldat->getEvolution()==true){
				int position=soldat->getPosition();
				int pv=soldat->getpoints_de_vie();
				SuperSoldat* sup_soldat=new SuperSoldat(this->getNumeroJoueur());
				sup_soldat->setpoints_de_vie(pv);
				sup_soldat->setPosition(position);
				if(i==size-1){
                    m_unite.erase(m_unite.end());
                    m_unite.push_back(sup_soldat);
				}else{
				m_unite.erase(m_unite.begin()+i);
				m_unite.emplace(m_unite.begin()+i,sup_soldat);
				}

			}
		}

	}
}



void CJoueur::printProfile(){

cout<<"Nom :"<<m_nom;
cout<<"\t\t PV : "<<m_PointVie;
cout<<"\t\tNombre de Piece : "<<m_nbPiece;
cout<<"\t\tNombre Unite : "<<m_unite.size()<<endl;


}



