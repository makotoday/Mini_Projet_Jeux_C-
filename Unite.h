#ifndef UNITE_H
#define UNITE_H
#include "CJoueur.h"
#include "CAireJeux.h"


class Unite
{
    public:
        Unite(CJoueur& jr, int pos);
        virtual ~Unite();
        int getpoints_de_vie() const{ return points_de_vie; }
        void setpoints_de_vie(int val) { points_de_vie = val; }
        int getpoint_dAttaque() const{ return point_dAttaque; }
        int getPosition() const{return position;}
        int getporteeMax() const{ return porteeMax; }
        void setMort() {vivant = false;}
         //action renvoie faux si l'unité n'a pas pu executer l'action
        virtual void action(int numAction, Unite& ennemiProche) = 0;
        virtual void print() const;
    protected :
        int points_de_vie;
        int point_dAttaque;
        int porteeMax;
        CJoueur& sonJoueur;
        //attaquer et avancer renvoient faux si l'unité n'a pas pu executer l'action
        virtual bool attaquer(Unite& ennemiProche) const = 0 ;
        bool avancer(/*CAireJeux& aireJeu*/); //avancer est commun a toute les unités
        int valsAbsolue(int n) const{return (n >0 ? n : -n);}//calcul de la distance entre 2 unité
        bool vivant;//indique si l'unite est toujours vivante
        int position; //indique la position de l'unite sur le plateau dans [0 - 11]

    private:
};

inline bool EstDansAireDeJeu(int pos)
{
    return pos >=0 && pos <=11 ;
}



#endif // UNITE_H
