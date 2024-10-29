#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

/** Calcule et affiche le prénom le plus donné une année donnée
 * ainsi que le nombre de naissance cette année là **/
int main() {

    int choice;
    cout << "Entrez une année entre 2006 et 2021 : ";
    cin >> choice;

    ifstream fichier("donnees/liste_des_prenoms.csv");
    string header;
    getline(fichier, header);
    string given;
    string sexe;
    string year;
    string name;
    string nb;
    int occurence;
    
    int occurence_max = 0;
    int total = 0;
    string name_max;

    while(fichier) {
        getline(fichier, given, ';');
        getline(fichier, sexe, ';');
        getline(fichier, year, ';');
        getline(fichier, name, ';');
        getline(fichier, nb);

        if (nb.size() > 0 and nb[nb.length()-1] == '\r') {
            nb.resize(nb.length()-1);
        }
        istringstream(nb) >> occurence;
        if(fichier){
            if(stoi(year) == choice) { // convert into int
                total += occurence;
                if(occurence > occurence_max) {
                    name_max = name;
                    occurence_max = occurence;
                }
            }
        }
    }
    
    fichier.close();
    cout << "En " << choice << ", il y a eu " << total << " naissancess" << endl;
    cout << "Le prénom le plus donné a été : " << name_max << " (donné " << occurence_max << " fois)" << endl;
    return 0;
}

