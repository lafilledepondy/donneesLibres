#include <stdexcept>
/** @file **/
#include <fstream>
#include <sstream>
#include "tableau-lecture.hpp"


vector<vector<string>> litTableau(string nom_fichier, int nb_colonnes) {
    ifstream fichier(nom_fichier);

    vector<vector<string>> tab = {};

    while (fichier ) {
        vector<string> lignes = {};
        // parcourt lignes par lignes en recuperant dans un sous-tableau (1D) les elements du lignes
        for (int i = 0; i < nb_colonnes; i++) {
            string word;
            if ( fichier >> word and word != "") 
                lignes.push_back(word);
        }
        // ajoute dans un tableau 2D les sous-tableau recuperer
        if (lignes.size() == nb_colonnes)
            tab.push_back(lignes);
    }
    fichier.close();
    return tab;
}

