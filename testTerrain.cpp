#include "CAireJeux.h"
#include <iostream>
using namespace std; 
/*ce ficher, est le fichier test de la classe CAireJeux afin de tester toute ses methode  */

int main(){


	CAireJeux jeux; 
	jeux.printT(); 
	cout<<"Modifier une case en donnant sont indice :  ";
	int t_case; 
	int element_case; 
	cin>>t_case; 
	cout<<"entrer un chiffre soit 3  ou 2 : "; 
	cin>>element_case; 
	jeux.modifieCase(t_case,element_case); 
	jeux.printT();





return 1; 
}
