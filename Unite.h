#ifndef __UNITE_H__
#define __UNITE_H__
#include "CJoueur.h"
#include "CAireJeux.h"


class Unite
{
    public:
        Unite(CJoueur& jr);
        virtual ~Unite();
        int getpoints_de_vie() const{ return points_de_vie; }
        void setpoints_de_vie(int val) { points_de_vie = val; }
        int getpoint_dAttaque() const{ return point_dAttaque; }
        int getPosition() const{return position;}
        int getporteeMax() const{ return porteeMax; }
        void setMort() {vivant = false;}
         //action renvoie faux si l'unité n'a pas pu executer l'action
        virtual void action(int numAction, CAireJeux& aireJeu) = 0;
        virtual void print() const;
    protected :
        int points_de_vie;
        int point_dAttaque;
        int porteeMax;
        CJoueur& sonJoueur;
        //attaquer et avancer renvoient faux si l'unité n'a pas pu executer l'action
        virtual bool attaquer(Unite& ennemiProche) const = 0 ;
        void avancer(CAireJeux& aireJeu); //avancer est commun a toute les unités
        int valsAbsolue(int n) const{return (n >0 ? n : -n);}//calcul de la distance entre 2 unité
        bool vivant;//indique si l'unite est toujours vivante
        int position; //indique la position de l'unite sur le plateau dans [0 - 11]
        virtual Unite* trouveEnnemiProche(CAireJeux& aireJeu) =0;// renvoie la position de l'ennemi proche qui peut etre attaqué

    private:
};


#endif // UNITE_H
