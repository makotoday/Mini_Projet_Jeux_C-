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


}

void CAireJeux::printT(){

    for(int i =0; i<m_tailleT;i++){

		cout<<"|"<<m_t[i]<<" |";

	}
	cout<<endl;
	for(int i=0;i<m_tailleT;i++){
            //affichage : une case est soit vide, soit au joueur 1 , soit au joueur 2
            Unite* unite=m_joueur1.getUnitAt(i);
			if(unite==NULL)unite = m_joueur2.getUnitAt(i);
			if(unite==NULL)cout<<" | 0  | ";

			else{
                int num = unite->getNumJoueur();
                switch(unite->quelleType()){
                    case Uarcher :{
                    if(num==JOUEUR1)cout<<" | A1 | ";
                    if(num==JOUEUR2)cout<<" | A2 | ";
                    break;
                    }
               case Ucatapulte : {
                    if(num==JOUEUR1)cout<<" | C1 | ";
                    if(num==JOUEUR2)cout<<" | C2 | ";
                    break;
                }
                case Ufantassin :{
                    if(num==JOUEUR1)cout<<" | F1 | ";
                    if(num==JOUEUR2)cout<<" | F2 | ";
                    break;
                }
                case USuperSoldat :{
                    if(num==JOUEUR1)cout<<" | S1 | ";
                    if(num==JOUEUR2)cout<<" | S2 | ";
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
if(index<0||index>MAXCASE) return;
	m_t[index]=joueur;


}

int  CAireJeux::getOccupation(int index)const
{
	return m_t[index];
}




void CAireJeux::Run(){

	cout<<"--------------------------LANCEMENT DU JEUX ------------------------------------\n";
	cout<<"Abreviation : \n";
	cout<<" Les chiffres  representes  les joueurs, 1 pour le JOUEUR 1 et 2 pour le JOUEUR 2.\n La lettre devant le chiffre represente le type d unite\n";
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
		char lu;
		cin >> lu;
		if(lu=='d')
		tour++;
		if(tour==30)fin_partie=true;
	}



}


void CAireJeux::Tour(){
	cout<<"Les joueurs recoivent "<<piece_joueur<<" d or \n ";
	cout<<"JOUEUR 1 : \n";
	play(m_joueur1);
	diedUnite(m_joueur2);
	m_joueur1.creationSuperSoldat();
	UpDateT();
	cout<<"Fin de tour Joueur 1 \n\n";
	cout<<"Joueur 2 : \n";
	play(m_joueur2);
	diedUnite(m_joueur1);
	m_joueur2.creationSuperSoldat();
	UpDateT();
	cout<<"Fin de tour du Joueur 2 \n\n";
	cout<<"Etat du terrain  de jeux en fin de Tour \n";
	printT();

}

void CAireJeux::diedUnite(CJoueur& joueur)
{
  /*  vector<Unite*> m_unite = joueur.getTableauxUnite();
    if(m_unite.size()==0) return;//rien a faire
	//boucle pour supprimer les unités dans le vecteur
	int i =0;
	for(vector<Unite*>::iterator it=m_unite.begin();it!=m_unite.end();it++)
    {
		if(!(m_unite[i]->getEtatUnit()))
        {
			cout<<"sortie des perso"<<endl;
			modifieCase(m_unite[i]->getPosition(),0);
			m_unite.erase(it);//retire l'unité
		}
		i++;
	}*/
	joueur.diedUnite();
}

void CAireJeux::play(CJoueur& joueur){

    vector<Unite*> m_unite = joueur.getTableauxUnite();
	if(m_unite.empty()){
		joueur.creationUnite(joueur.choixUnite());
	}else{
	    //deroulement des phases d'action 1, 2 et 3
        for(int i = 0;i<3;i++) actions(i,joueur);

		if(creerUnite_Pas(joueur)){
		  joueur.creationUnite(joueur.choixUnite());
		}
	}
}

bool CAireJeux::creerUnite_Pas(CJoueur& joueur){

        int num_j=joueur.getNumeroJoueur();
        Unite* unite;
        if(num_j==JOUEUR1)unite=joueur.getUnitAt(0);
        if(num_j==JOUEUR2)unite=joueur.getUnitAt(11);
        if(unite==NULL){
        int tmp=rand()%2;
        if(tmp==0)return true;
        if(tmp==1){
        cout<<"Le joueur a choisi de ne pas creer d unite \n";
        return false;
        }
        }else return false;
        //return false;

   /* vector<Unite*> m_unite = joueur.getTableauxUnite();
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
	return false;*/

}


void CAireJeux::actions(int numAction, CJoueur& joueur){

    vector<Unite*> m_unite = joueur.getTableauxUnite();
    int num_j=joueur.getNumeroJoueur();
    CJoueur c;//joueur adverse
    if(num_j==JOUEUR1) c=m_joueur2;
    else c=m_joueur1;
    switch(numAction)
    {
        case 0 :     cout<<"------ Phase 1: action 1  ATTAQUER ------------------\n* ";break;
        case 1 :     cout<<"------ Phase 2: action 2  AVANCER------------------\n* ";break;
        case 2 :     cout<<"------ Phase 3: action 3  ATTAQUER/AVANCER ------------------\n* ";break;
        default : throw string("action inconnue");

    }


	for(int i=m_unite.size()-1; i>=0; --i){
		int position_ennemi = m_unite[i]->getPosEnnemiProche(m_t);
		//cout<<"valeur de position ennemie "<<position_ennemi<<endl;
		if(position_ennemi==CODE_ERREUR) m_unite[i]->action(numAction,nullptr);//aucun ennemi
		if(m_unite[i]->AttaqueBase()){

        c.oterPV(m_unite[i]->getpoint_dAttaque());
        cout<<"Attaque de la base par l unite ";

		}
         else m_unite[i]->action(numAction,c.getUnitAt(position_ennemi));
        modifieCase(m_unite[i]->getPosition(),num_j);
        // l'affichage de la position sur le plateau de jeu
        if(num_j==JOUEUR1) modifieCase(m_unite[i]->getPosition() -1,0);
        else if(num_j==JOUEUR2) modifieCase(m_unite[i]->getPosition()+1,0);

		//m_unite[i]->print();

	}

}


void CAireJeux::UpDateT(){

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
