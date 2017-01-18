#ifndef __UNITE_H__
#define __UNITE_H__

#define JOUEUR1 1
#define JOUEUR2 2
#define BASE 200
#define CODE_ERREUR 255
#define CASE_MAX 12

enum TypeUnite{Uarcher,Ufantassin,Ucatapulte,UPASSTOUR,USuperSoldat};
//enumeration pour differiencer le type des unités, upasstour servira pour la creation des unités

class Unite
{
    public:
        Unite(int joueur);
        virtual ~Unite();
        int getpoints_de_vie() const{ return points_de_vie; }
        void setpoints_de_vie(int val) { points_de_vie = val; }
        int getpoint_dAttaque() const{ return point_dAttaque; }
        int getPosition() const{return position;}
        int getporteeMax() const{ return porteeMax; }
        void setMort() {vivant = false;}
        void oterPV(int pv);
        bool getEtatUnit()const{return vivant;};
        void setPosition(int post){position=post;};
         //action renvoie faux si l'unité n'a pas pu executer l'action
        virtual void action(int numAction, Unite* ennemie) = 0;
        virtual void print() const;
        int getNumJoueur()const{return num_joueur;};
        bool getEvolution()const{return evolution;};
        bool getAttaquePossible()const{return action3possible;};
        virtual int getPosEnnemiProche(int plateau[]);// renvoie la position de l'ennemi proche qui peut etre attaqué
        int quelleType() const{return type;}//pour connaitre son type
    protected :
        int type;
        int points_de_vie;
        int point_dAttaque;
        int porteeMax;
        int num_joueur;
        bool evolution;
        bool action3possible;
        //attaquer et avancer renvoient faux si l'unité n'a pas pu executer l'action
        virtual bool attaquer(Unite* ennemi) = 0 ;
        void avancer(); //avancer est commun a toute les unités
        int valsAbsolue(int n) const{return (n >0 ? n : -n);}//calcul de la distance entre 2 unité
        bool vivant;//indique si l'unite est toujours vivante
        int position; //indique la position de l'unite sur le plateau dans [0 - 11]
        virtual bool peutAttaquerBase() const;// si il n'y a pas d'ennemi on cible la base

    private:
};


#endif // UNITE_H
