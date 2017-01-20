#include "CAireJeux.h"
#include "Unite.h"


CAireJeux:: CAireJeux():m_tailleT(12){

	m_t=new int [m_tailleT];
	for(int i=0;i<m_tailleT;i++)m_t[i]=0;

}

CAireJeux::~CAireJeux(){

	delete [] m_t;

}

void CAireJeux::printT(){


	for(int i =0; i<m_tailleT;i++){

		cout<<"|"<<m_t[i]<<" |";

	}

	cout<<endl;


}

void CAireJeux::modifieCase(int index,int occupant){
// on pourrait mettre une exception de depassement de case

	m_t[index-1]=occupant;


}

int  CAireJeux::getOccupation(int indix)
{

}

Unite* CAireJeux::getUniteAt(int position) const
{

    return NULL;
}
