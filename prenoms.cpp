#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

/** Calcule et affiche le prénom le plus utilisé une année donnée
 * ainsi que le nombre de naissances cette année là **/
int main() {
    int choice;
    cout << "Entrez une année entre 2006 et 2021 : ";
    cin >> choice;
    
    ifstream fichier("donnees/liste_des_prenoms.txt");
    string sexe;
    int year;
    string name;
    int occurence;
    
    int occurence_max = 0;
    int total = 0;
    string name_max;
    
    while (fichier >> sexe >> year >> name >> occurence) {
        // verifie si choice est present
        if (year == choice) {
            total += occurence;
            // echange les valeurs si la condition est verifie
            if (occurence > occurence_max){
                name_max = name;
                occurence_max = occurence;
            }
        }
        
    }
    fichier.close();
    cout << "En " << choice << ", il y a eu " << total << " naissancess" << endl;
    cout << "Le prenom le plus donne a ete : " << name_max << " (donne " << occurence_max << " fois)." << endl;
    return 0;
}

