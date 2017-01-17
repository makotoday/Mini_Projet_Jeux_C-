#include "CAireJeux.h"
#include "Unite.h"
#include "CJoueur.h"



int CAireJeux::piece_joueur=8;

CAireJeux::CAireJeux(): m_tailleT(12){

	m_t=new int [m_tailleT];
	for(int i=0;i<m_tailleT;i++)m_t[i]=0;
	m_joueur1= CJoueur("JOUEUR1",0,100,JOUEUR1);
	m_joueur2= CJoueur("JOUEUR2",0,100,JOUEUR2);


}

CAireJeux::~CAireJeux(){

	delete [] m_t;
	m_t=NULL;

}

void CAireJeux::printT(){


	for(int i =0; i<m_tailleT;i++){

		cout<<"|"<<m_t[i]<<" |";

	}

	cout<<endl;
	for(int i=0;i<m_tailleT;i++){

			Unite* unite=getUniteAt(i);
			if(unite==NULL)cout<<" | 0  | ";
			if(typeid(*unite)==typeid(Archer)){
				if(m_t[i]==1)cout<<" | A1 | ";
				if(m_t[i]==2)cout<<" | A2 | ";
				}
			if(typeid(*unite)==typeid(Catapulte)){
				if(m_t[i]==1)cout<<" | C1 | ";
				if(m_t[i]==2)cout<<" | C2 | ";
			}
			if(typeid(*unite)==typeid(Fantassin)){
				if(m_t[i]==1)cout<<" | F1 | ";
				if(m_t[i]==2)cout<<" | F2 | ";
			}
			if(typeid(*unite)==typeid(SuperSoldat)){
				if(m_t[i]==1)cout<<" | S1 | ";
				if(m_t[i]==2)cout<<" | S2 | ";
			}

	}
	cout<<endl<<endl;

}

void CAireJeux::modifieCase(int index,int joueur){
// on pourrait mettre une exception de depassement de case

	m_t[index]=joueur;


}

int  CAireJeux::getOccupation(int index)const
{
	return m_t[index];
}

Unite* CAireJeux::getUniteAt(int position) const
{
	int joueur=getOccupation(position);
	if(joueur==1) return m_joueur1.getUnitAt(position);
	if(joueur==2){

		int post=position-m_tailleT;
		if(post<0){
			post=post*-1;
			return m_joueur2.getUnitAt(post-1);

		}
		if(post==0)return m_joueur2.getUnitAt(post);
	}
	return NULL;
}


void CAireJeux::Run(){

	cout<<"--------------------------LANCEMENT DU JEUX ------------------------------------\n";
	cout<<"Abreviation : \n";
	cout<<" Le chiffre  represente  le joueur, 1 pour le joueur 1 et 2 pour le joueur 2.\n La lettre devant le chiffre represente l unite\n";
	cout<<"Fantassin : F \t\t";
	cout<<"Archer    : A \t\n";
	cout<<"Catapulte : C \t\t";
	cout<<"SuperSoldat: S\t\n";
	cout<<endl;
	bool fin_partie=false;
	int tour=0;
	cout<<"Etat du terrain  de jeux \n";
	printT();
	while(fin_partie==false){
		m_joueur1.gain(piece_joueur);
		m_joueur2.gain(piece_joueur);
		Tour();
		cout<<"-------------FIN DE TOUR "<<tour<<" -------------\n";
		tour++;
		if(tour==5)fin_partie=true;
	}



}


void CAireJeux::Tour(){
	cout<<"Les joueur recoivent "<<piece_joueur<<" d or \n ";
	cout<<"JOUEUR 1 : \n";
	play(m_joueur1);
	cout<<endl;
	diedUnite(m_joueur1);
	m_joueur1.creationSuperSoldat();
	cout<<"Joueur 2 : \n";
	play(m_joueur2);
	diedUnite(m_joueur2);
	m_joueur2.creationSuperSoldat();
	cout<<"Etat du terrain  de jeux en fin de Tour \n";
	printT();
}

void CAireJeux::diedUnite(CJoueur& joueur){

    vector<Unite*> m_unite = joueur.getTableauxUnite();
    int size = m_unite.size();
	// boucle pour mettre les poiteur � nulle
	for(int i=0; i<size; i++){
		if(m_unite[i]->getEtatUnite()==false){

			modifieCase(m_unite[i]->getPosition(),0);
			delete m_unite[i];
			m_unite[i]=nullptr;
		}

	}
	//boucle pour supprimer les unit� dans le vecteur
	for(vector<Unite*>::iterator it=m_unite.begin();it!=m_unite.end();++it){

		if(*it==nullptr){
			cout<<"sortie des perso"<<endl;
			m_unite.erase(it);
		}
	}
	if(m_unite.size()==1){

		if(m_unite[0]==nullptr)m_unite.erase(m_unite.begin());
	}else{

		int taille=m_unite.size();
		if(m_unite[taille-1]==nullptr)m_unite.erase(m_unite.end());
	}
}

void CAireJeux::play(CJoueur& joueur){

    vector<Unite*> m_unite = joueur.getTableauxUnite();
	if(m_unite.empty()){

		joueur.creationUnite(joueur.choixUnite());
	}else{

		action1(joueur);
		action2(joueur);
		action3(joueur);
		if(creerUnite_Pas(joueur)){
		  joueur.creationUnite(joueur.choixUnite());
		}
	}
}

bool CAireJeux::creerUnite_Pas(CJoueur& joueur){
    vector<Unite*> m_unite = joueur.getTableauxUnite();
	int occupation;
	if(joueur.getNumeroJoueur()==JOUEUR1)occupation=getOccupation(0);
	if(joueur.getNumeroJoueur()==JOUEUR2)occupation=getOccupation(m_tailleT-1);
	if(occupation==0){
	srand(time(NULL));
	int tmp=rand()%2;
	if(tmp==0)return true;
	if(tmp==1)return false;
	}
	return false;
}

void CAireJeux::action1(CJoueur& joueur){

    vector<Unite*> m_unite = joueur.getTableauxUnite();
	int size=m_unite.size()-1;
	cout<<"------ Phase 1: action 1 ------------------\n";
	for(int i=size; i>0; --i){
		m_unite[i]->action(0,joueur);
		cout<<"* ";
		m_unite[i]->print();
	}

}


void CAireJeux::action2(CJoueur& joueur){

    vector<Unite*> m_unite = joueur.getTableauxUnite();
	cout<<"------ Phase 2: action 2 ------------------\n";
	int size=m_unite.size();
	for(int i=0; i<size;i++){
		m_unite[i]->action(1,aire);
		cout<<"*  ";
		m_unite[i]->print();
	}
}

void CAireJeux::action3(CJoueur& joueur){

    vector<Unite*> m_unite = joueur.getTableauxUnite();
	cout<<"------ Phase 3: action 3 ------------------\n";
	int size=m_unite.size();
	for(int i=0;i<size;i++){
		m_unite[i]->action(2,aire);
		cout<<"*  ";
		m_unite[i]->print();
	}
}
