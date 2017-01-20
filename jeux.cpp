#include "CAireJeux.h"
#include <fstream>
#include <string.h>

using namespace std;

ofstream monFichier; //varialbe globale

void EcrireDans(CAireJeux& jeux,string nomF);

int main(){


    cout << "L'Affichage est dans resultat.txt"<< endl;
    // Redirection de std::cout vers le fichier resultat.txt
    ofstream Out("resultat.txt");
    streambuf* OldBuf = cout.rdbuf(Out.rdbuf());

    CAireJeux jeux;
	srand(time(NULL));
    jeux.Run();
	cout<<"\n------------------FIN DE JEUX -----------------\n";

    // Restauration du streambuf initial de std::cout (affichage sur la console)
    std::cout.rdbuf(OldBuf);


}
