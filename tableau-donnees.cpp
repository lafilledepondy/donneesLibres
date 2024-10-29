#include <stdexcept>
/** @file **/
#include <fstream>
#include <sstream>
#include "tableau-donnees.hpp"

void afficheTableau(vector<vector<string>> tableau) {
    // parcourt le tableau 2D en affichant les elements
    for ( int i = 0; i < tableau.size(); i++ ) {    
        for ( int j = 0; j < tableau[i].size(); j++) { 
            cout << tableau[i][j] << " " ;
        } cout << endl; 
    }
}

int moyenne(vector<int> t) {
    return somme(t)/t.size();
}

int somme(vector<int> t) {
    int sum = 0;
    for (int i = 0; i < t.size(); i++) 
        sum += t[i];
    return sum; 
}


int indiceMax(vector<int> t) {
    int max = 0;
    if(t.size() == 0)
        return -1;
    for (int i = 0; i<t.size(); i++){
        if (t[i] > t[max])
            max = i;
    }
    return max;
}

vector<string> colonne(vector<vector<string>> t, int j) {
    vector<string> final_list; 
    // parcourt la colonne en recuperant dans un tableau les elements
    for ( int i = 0; i < t.size() ; i++ )
        final_list.push_back(t[i][j]);       
    return final_list;  
}


vector<int> conversionInt(vector<string> t) {
    vector<int> resultat = vector<int>(t.size());
    for(int i =0; i < t.size(); i++) {
        istringstream(t[i]) >> resultat[i];
    }
    return resultat;
}

vector<vector<string>> selectLignes(vector<vector<string>> t, int j, string valeur) {
    vector<vector<string>> tab;
    // parcourt les lignes en verifiant au ligne j si la valeur donne est presente
    for ( int i = 0; i < t.size(); i++) { 
        if ( (t[i][j]) == valeur)
            tab.push_back(t[i]);
    } 
    return tab; 
}

