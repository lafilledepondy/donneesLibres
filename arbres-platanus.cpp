#include <stdexcept>
/** @file **/
#include <iostream>
#include "tableau-donnees.hpp"
#include "tableau-donnees-avance.hpp"
#include "tableau-lecture-csv.hpp"
using namespace std;

/** Affiche le nombre d'arbres du genre Platanus, et le nombre d'espèces
 *  différentes pour ce genre Platanus, parmi les "arbres remarquables"
 **/
int main() {
    vector<vector<string>> data = litTableauCSV("donnees/arbresremarquablesparis.csv");
    vector<vector<string>> platanus = selectLignes(data, 2, "Platanus");
    vector<string> species = distinct(platanus, 3);
    cout << "Il y a " << platanus.size() << " de genre de platanus d'ardres et " << species.size() << "d'especes differentes pour les platanus." << endl;

}