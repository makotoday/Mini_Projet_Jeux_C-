#include "SuperSoldat.h"

SuperSoldat::SuperSoldat(int jr) : Fantassin(jr)
{
    type = USuperSoldat;
}

SuperSoldat::~SuperSoldat()
{
    //dtor
    if(num_joueur==JOUEUR1)cout<<"UNITE SUPERSOLDAT DETRUITE PAR LE JOUEUR 2 \n";
    if(num_joueur==JOUEUR2)cout<<"UNITE SUPERSOLDAT DETRUITE PAR LE JOUEUR 1 \n";
}

void SuperSoldat::action(int numAction, Unite* ennemie)
{
    switch(numAction)
    {
        case 0 : {
                //action attaquer
            action3possible = !attaquer(ennemie);break;}
        case 1 :
            if(ennemie==nullptr) avancer(AUCUN_ENNEMI);
            else avancer(ennemie->getPosition());
            break;
        case 2 : {
            //action 3 toujours possible
            attaquer(ennemie);break;}
        //default : throw string("action inconnue pour le superSoldat");
    }
}


bool SuperSoldat::attaquer(Unite* ennemi)
{
    if(ennemi==NULL)//pas d'unité ennemi
    {
        if(peutAttaquerBase())
        {
            //enlever pv a la base
            return true;
        }
        else return false;// rien à attaquer
    }
    if(valsAbsolue(position - ennemi->getPosition())<=porteeMax) //la distance avec l'ennemi doit etre <= à la portée
    {
        ennemi->setpoints_de_vie(ennemi->getpoints_de_vie() - this->point_dAttaque);
        if(ennemi->getpoints_de_vie()<=0){
			 ennemi->setMort();
			 evolution=true;
		 }
		 cout<<"SuperSoldat "<<num_joueur<<" attaque ennemi\n";
        cout<<"position : "<<position<<"\t\t\t position ennemi "<<ennemi->getPosition()<<endl;
        cout<<"PV : "<<points_de_vie<<"\t\t\t PV ennemi : "<<ennemi->getpoints_de_vie()<<endl;

        return true;
    }
    else return false;
}




void SuperSoldat::print_avance(){

cout<<"Unite SuperSoldat avance \n";

}
