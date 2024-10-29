#include <stdexcept>
/** @file **/
#include <iostream>
#include "tableau-donnees.hpp"
#include "tableau-donnees-avance.hpp"
#include "tableau-lecture-csv.hpp"
using namespace std;

/** Affiche l'année avec le plus de naissances et l'année avec le plus de mariages
 **/
int main() {
    vector<vector<string>> data = litTableauCSV("donnees/statistiques_de_creation_d_actes_d_etat_civil_par_arrondissement.csv", 4);
    vector<string> years = distinct(data, 1);
    vector<vector<string>> births = selectLignes(data, 0, "Naissances");
    vector<int> nb = groupBy<int>(births, years, 1, 3); // problème
    int max = indiceMax(nb);
    cout << "Il y eu le plus de declaration de naissance en " << years[max] << endl;

    
    vector<vector<string>> mariages = selectLignes(data, 0, "Mariages");
    nb = groupBy<int>(mariages, years, 1, 3);
    max = indiceMax(nb);
    cout << "Il y eu le plus de declaration de mariages en " << years[max] << endl;
}

