#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

/** Calcule et affiche le nombre de mariages un samedi entre 2010 et 2015 **/
int main() {
    ifstream fichier("donnees/statistiques-des-jours-des-mariages.txt");
    int year;
    string day;
    int mariage_nb; 
    int total = 0;        

    while(fichier >> year >> day >> mariage_nb){
        // verifie si Samedi est present
        if(day == "Samedi")
            total += mariage_nb;
    }    
    fichier.close();
    cout << "Le nombre total de mariages celebres un samedi a Paris entre 2010 et 2015 est " << total << endl; 
}

