#include "CAireJeux.h"
#include "Archer.h"
#include "Fantassin.h"
#include "SuperSoldat.h"
#include "Catapulte.h"

int CAireJeux::piece_joueur=8;

CAireJeux::CAireJeux(): m_tailleT(MAXCASE){

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
            //affichage : une case est soit vide, soit au joueur 1 , soit au joueur 2
			Unite* unite=m_joueur1.getUnitAt(i);
			if(unite==NULL) unite = m_joueur2.getUnitAt(i);
			if(unite==NULL)cout<<" | 0  | ";
			else{
                switch(unite->quelleType()){
                    case Uarcher :{
                    if(m_t[i]==JOUEUR1)cout<<" | A1 | ";
                    if(m_t[i]==JOUEUR2)cout<<" | A2 | ";
                    break;
                    }
               case Ucatapulte : {
                    if(m_t[i]==JOUEUR1)cout<<" | C1 | ";
                    if(m_t[i]==JOUEUR2)cout<<" | C2 | ";
                    break;
                }
                case Ufantassin :{
                    if(m_t[i]==JOUEUR1)cout<<" | F1 | ";
                    if(m_t[i]==JOUEUR2)cout<<" | F2 | ";
                    break;
                }
                case USuperSoldat :{
                    if(m_t[i]==JOUEUR1)cout<<" | S1 | ";
                    if(m_t[i]==JOUEUR2)cout<<" | S2 | ";
                    break;
                    }
                }
			}

	}
	cout<<endl<<endl;
    m_joueur1.printProfile();
    m_joueur2.printProfile();
}

void CAireJeux::modifieCase(int index,int joueur)
{
if(index<0||index>MAXCASE) throw string("Erreur : index pas dans le tableau");
	m_t[index]=joueur;


}

int  CAireJeux::getOccupation(int index)const
{
	return m_t[index];
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
	while(!fin_partie){
		m_joueur1.gain(piece_joueur);
		m_joueur2.gain(piece_joueur);
		Tour();
		cout<<"-------------FIN DE TOUR "<<tour<<" -------------\n";

		tour++;
		if(tour==15)fin_partie=true;
	}



}


void CAireJeux::Tour(){
	cout<<"Les joueurs recoivent "<<piece_joueur<<" piece d or \n ";
	cout<<"JOUEUR 1 : \n";
	play(m_joueur1);
	cout<<endl;
	diedUnite(m_joueur2);
	m_joueur1.creationSuperSoldat();
	cout<<"Joueur 2 : \n";
	play(m_joueur2);
	diedUnite(m_joueur1);
	m_joueur2.creationSuperSoldat();
	cout<<"Etat du terrain  de jeux en fin de Tour \n";
	upDateT();
	printT();

}

void CAireJeux::diedUnite(CJoueur& joueur){

    vector<Unite*> unite=joueur.getTableauxUnite();
	if(unite.empty()!=true){

		for(int i=0;i<unite.size();i++){
			if(unite[i]->getEtatUnit()==false){
			modifieCase(unite[i]->getPosition(),0);
			delete unite[i];
			unite.erase(unite.begin()+i);

			}

		}


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
	//srand(time(NULL));
	int tmp=rand()%2;
	if(tmp==0)return true;
	if(tmp==1){
		cout<<"CHOISIT DE NE PAS CREER UNITE\n";
		return false;
		}
	}
	return false;
}

void CAireJeux::action1(CJoueur& joueur){

    vector<Unite*> m_unite = joueur.getTableauxUnite();
    int num_j=joueur.getNumeroJoueur();
    CJoueur c;
    if(num_j==JOUEUR1) c=m_joueur2;
    else c=m_joueur1;
	int size=m_unite.size()-1;

	cout<<"------ Phase 1: action 1  ATTAQUER ------------------\n";
	for(int i=size; i>0; --i){
		int position_ennemi=m_unite[i]->getPosEnnemiProche(m_t);
		if(position_ennemi!=CODE_ERREUR){
		m_unite[i]->action(0,c.getUnitAt(position_ennemi));
		if(position_ennemi==BASE){
			if(m_unite[i]->getAttaquePossible()==true){
                m_unite[i]->print();
                cout<<"ATTAQUE BASE "<<endl;
                if(joueur.getNumeroJoueur()==JOUEUR1)m_joueur2.oterPV(m_unite[i]->getpoint_dAttaque());
                if(joueur.getNumeroJoueur()==JOUEUR2)m_joueur1.oterPV(m_unite[i]->getpoint_dAttaque());
			}
		}

		//cout<<"* ";
		//m_unite[i]->print();

			}

	}

}


void CAireJeux::action2(CJoueur& joueur){

    vector<Unite*> m_unite = joueur.getTableauxUnite();
    int num_j=joueur.getNumeroJoueur();
	cout<<"------ Phase 2: action 2  AVANCER------------------\n";
	int size=m_unite.size();
	for(int i=0; i<size;i++){
		if(num_j==JOUEUR1){
		if(getOccupation(m_unite[i]->getPosition()+1)==0){
			m_unite[i]->action(1,nullptr);
		   //cout<<"*  ";
            modifieCase(m_unite[i]->getPosition(),num_j);
            //modifieCase(m_unite[i]->getPosition()-1,0);
		  // m_unite[i]->print();

			}else {
			if(m_unite[i]->quelleType()==Ufantassin)cout<<"L UNITE FANTASSIN NE PEUT PAS AVANCER \n";
			if(m_unite[i]->quelleType()==Ucatapulte)cout<<"L UNITE CATAPULTE NE PEUT PAS AVANCER \n";
			if(m_unite[i]->quelleType()==Uarcher)cout<<"L UNITE ARCHER  NE PEUT PAS AVANCER \n";
			if(m_unite[i]->quelleType()==USuperSoldat)cout<<"L UNITE SUPERSOLDAT NE PEUT PAS AVANCER \n";
			}
		}
		else{
			if(getOccupation(m_unite[i]->getPosition()-1)==0){
			m_unite[i]->action(1,nullptr);
		    //cout<<"*  ";
            modifieCase(m_unite[i]->getPosition(),num_j);
            modifieCase(m_unite[i]->getPosition()+1,0);
		   // m_unite[i]->print();
			}
			else{
			if(m_unite[i]->quelleType()==Ufantassin)cout<<"L UNITE FANTASSIN NE PEUT PAS AVANCER \n";
			if(m_unite[i]->quelleType()==Ucatapulte)cout<<"L UNITE CATAPULTE NE PEUT PAS AVANCER \n";
			if(m_unite[i]->quelleType()==Uarcher)cout<<"L UNITE ARCHER  NE PEUT PAS AVANCER \n";
			if(m_unite[i]->quelleType()==USuperSoldat)cout<<"L UNITE SUPERSOLDAT NE PEUT PAS AVANCER \n";
			}
		}
	}
}

void CAireJeux::action3(CJoueur& joueur){

    vector<Unite*> m_unite = joueur.getTableauxUnite();
    int num_j=joueur.getNumeroJoueur();
    CJoueur c;
    if(num_j==JOUEUR1) c=m_joueur2;
    else c=m_joueur1;
	int size=m_unite.size()-1;
	cout<<"------ Phase 3: action 3  ATTAQUER ------------------\n";
	for(int i=size; i>0; --i){
		int position_ennemi=m_unite[i]->getPosEnnemiProche(m_t);
		if(position_ennemi!=CODE_ERREUR){
		m_unite[i]->action(2,c.getUnitAt(position_ennemi));
		if(position_ennemi==BASE){
			if(m_unite[i]->getAttaquePossible()==true) m_unite[i]->print();
		}

		//cout<<"* ";
       // modifieCase(m_unite[i]->getPosition(),num_j);
		//m_unite[i]->print();


			}

	}
}


void CAireJeux::upDateT(){

    vector<Unite*> unite=m_joueur1.getTableauxUnite();
    vector<Unite*> unite1=m_joueur2.getTableauxUnite();
    for(int i=0;i<unite.size();i++){

        m_t[unite[i]->getPosition()]=1;

    }
    for(int i=0;i< unite1.size();i++){

        m_t[unite1[i]->getPosition()]=2;

    }
    for(int i=0;i<m_tailleT;i++){

    if(m_joueur1.getUnitAt(i)==m_joueur2.getUnitAt(i))m_t[i]=0;

    }


}
