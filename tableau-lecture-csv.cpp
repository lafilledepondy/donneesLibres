#include <stdexcept>
/** @file **/
#include <iostream>
#include <fstream>
#include <sstream>
#include "tableau-lecture-csv.hpp"


vector<vector<string>> litTableauCSV(string nom_fichier, int nb_colonnes) {

    ifstream fichier(nom_fichier);
    vector<vector<string>> tab;
    string line;
    getline(fichier, line);
    while (fichier) {
        vector<string> line_tab;
        string value;
        for(int i=0; i<nb_colonnes-1 ; i++) {
            getline(fichier, value, ';');
            line_tab.push_back(value);
        }
        getline(fichier, value);
        if (value.size() > 0 and value[value.length()-1] == '\r' )
            value.resize(value.length() - 1);
        line_tab.push_back(value);
        if(fichier) 
            tab.push_back(line_tab);
    }
    return tab;
}

vector<vector<string>> litTableauCSV(string nom_fichier) {

    ifstream fichier(nom_fichier);
    vector<vector<string>> tab;
    string line;
    getline(fichier, line);
    while (getline(fichier, line)) {
        istringstream sl(line);
        vector<string> line_tab;
        string value;
        while(getline(sl, value, ';')) {
                if(value.size() > 0 and value[value.length()-1] == 'r')
                    value.resize(value.length()-1);
                line_tab.push_back(value);
        }
        tab.push_back(line_tab);
    }
    return tab;
}




