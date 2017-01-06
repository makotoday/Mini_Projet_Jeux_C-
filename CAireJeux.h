#include <iostream>
#include <string>
using namespace std; 


#ifndef __CAireJeux_h__
#define __CAireJeux_h__
#define base1  1
#define base2  2

class CAireJeux{


	int m_tailleT;// taille du terrain
	int* m_t;// ce poiteur sera un tableau qui ne contiendra que des 3 et des 2  afin de garder en mémoir la présance d'unité sur le terrai 
	

	public: 
	CAireJeux(); 
	~CAireJeux(); 
	void printT();// affiche le terrain avec l'emplacement des unité; 
	int  getOccupation(int indix);// return celon l'indice  qui est sur la case 1 pour la base1 et 2 pour la base2 et 0 si la case est vide 
	/* la methode permet de modifier l'information de la case.
	 l'indice doit etre compris dans [1 ; m_taille] */
	void modifieCase(int index, int occupant);
	
	 










}; 

#endif
