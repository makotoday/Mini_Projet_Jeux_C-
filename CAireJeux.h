#ifndef __CAireJeux_h__
#define __CAireJeux_h__

#include <iostream>
#include <string>
#include "CJoueur.h"


#define JOUEUR1 1
#define JOUEUR2 2
#define CODE_ERREUR 255
#define BASE 200
#define MAXCASE 12

using namespace std;
class Unite;

class CAireJeux{
        friend class CJoueur;

	int m_tailleT;// taille du terrain
	int* m_t;// ce poiteur sera un tableau qui ne contiendra que des 1 et des 2  afin de garder en mémoir la présance d'unité sur le terrain
    CJoueur m_joueur1;
	CJoueur m_joueur2;
	static int piece_joueur;
	public:
	CAireJeux();
	~CAireJeux();
	void printT();// affiche le terrain avec l'emplacement des unité;
	int  getOccupation(int indix)const;// return selon l'indice  qui est sur la case 1 pour la base1 et 2 pour la base2 et 0 si la case est vide
	/* la methode permet de modifier l'information de la case.
	 l'indice doit etre compris dans [1 ; m_taille] */
	void modifieCase(int index, int joueur);// la methode prendra juste une joueur, le joueur 1 ou le joueur 2
	int getTailleTerrain()const{return m_tailleT;};
	CJoueur getJoueur1()const{return m_joueur1;};
	CJoueur getJoueur2()const{return m_joueur2;};
    void diedUnite();// la méthode supprime  toutes les unites mortes , donc les unite à 0 point de vie et libère les cases
    void oterPV_Joueur1(int pv){m_joueur1.oterPV(pv);};
	void oterPV_Joueur2(int pv){m_joueur2.oterPV(pv);};

    /* les classes suivantes sont pour le joueur*/
	void diedUnite(CJoueur& joueur);// enleve toutes les unités morts
	void play(CJoueur& joueur);// toutes les action que fait le joueur durant son tour
    bool creerUnite_Pas(CJoueur& joueur);//  le methode retourne aléatoirement un boolean pour savoir s'il creer une unite ou pas
    void actions(int numAction, CJoueur& joueur);
    /*void action1(CJoueur& joueur);//le joueur applique l'action 1 sur  toute les unites
    void action2(CJoueur& joueur);//le joueur applique l'action 2 sur  toute les unites
    void action3(CJoueur& joueur);//le joueur applique l'action 3 sur  toute les unites*/

	void Run();
	void Tour();


};


#endif
