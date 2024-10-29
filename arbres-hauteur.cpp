#include <stdexcept>
/** @file **/
#include <iostream>
#include "tableau-donnees.hpp"
#include "tableau-lecture-csv.hpp"
using namespace std;

/** Affiche le genre et l'espece de l'arbre le plus haut de Paris
 * parmi les "arbres remarquables"
 **/
int main() {
    vector<vector<string>> data = litTableauCSV("donnees/arbresremarquablesparis.csv");
    vector<int> heigth = conversionInt(colonne(data, 12));
    int i = indiceMax(heigth);
    vector<string> tree = data[i];
    cout << "Nom francais : " << tree[1] << ", genre : " << tree[2] << ", espece de l'arbre le plus haut de Paris : " << tree[3] << " avec hauteur : " << heigth[i] << "metre(s)." << endl;
}

