#include "CJoueur.h"

int main(){

CJoueur joueur("Max",120); 
joueur.print(); 

cout<<"---------test des accesseur et modificateur----------------"<<endl; 
string nom; 
int somme; 
cout<< "entrer un nom : "; 
cin>>nom; 
cout<<"entrer une somme d argent : "; 
cin>>somme; 
joueur.setNom(nom); 
joueur.setNombrePiece(somme); 
cout<<"apres modification nous avons : \n\n"; 
cout<<"Nom du joueur : "<<joueur.getNom()<<endl; 
cout<<"Argent du joueur: "<<joueur.getNombrePiece()<<endl; 

cout<<"-------------test paye unite et gain --------------------------------\n\n\n\n\n"; 
cout<<"Donnez le cout de l unite : "; 
int paye; 
cin>>paye; 
joueur.payeUnite(paye); 
joueur.print(); 
cout<<"\n\n\n\nDonner le gain apres victoire d une unite : "; 
cin>>paye; 
joueur.gain(paye); 
joueur.print(); 





return 1; 
}
