#include <stdexcept>
/** @file **/
#include <fstream>
#include <sstream>
#include "tableau-donnees-avance.hpp"

int chercheIndice(vector<string> t, string valeur) {
    int max = -1;
    for (int i = 0; i<t.size(); i++){
        if (t[i] == valeur)
        max = i;
    }
    return max;
}

vector<string> distinct(vector<vector<string>> data, int j) {
    vector<string> final_list;
    for (int i = 0; i < data.size(); i++) {
        if (chercheIndice(final_list, data[i][j]) == -1) {
            final_list.push_back(data[i][j]);
        }    
    }
    return final_list;
}

vector<double> conversionDouble(vector<string> t) {
    vector<double> list;
    for (int i =0; i<t.size(); i++) {
        list.push_back(stod(t[i]));
    }
    return list;
}

vector<int> groupByInt(vector<vector<string>> data, vector<string> valeurs, int j1, int j2) {
    vector<int> final_list(valeurs.size(), 0);
    for (int i = 0; i < data.size(); i++) { // for pour ligne de data 
        int indice = chercheIndice(valeurs, data[i][j1]);
        if (indice != -1){
            final_list[indice] += stoi(data[i][j2]);
        }
    //indice != -1: si oui on doit regourper sinon non
    // final_list iindice 1 += ij2  
    }
    return final_list ;
}

vector<double> groupByDouble(vector<vector<string>> data, vector<string> valeurs, int j1, int j2) {
    vector<double> final_list(valeurs.size(), 0);
    for (int i = 0; i < data.size(); i++) { // for pour ligne de data 
        int indice = chercheIndice(valeurs, data[i][j1]);
        if (indice != -1){
            final_list[indice] += stoi(data[i][j2]);
        }
    }
    return final_list ;
}

template<class T>
vector<T> conversion(vector<string> t) {
    
}

template<class T>
vector<T> groupBy(vector<vector<string>> data, vector<string> valeurs, int j1, int j2) {
//*(typeId(T).name())   
}

// Force l'instanciation des templates
template vector<int> conversion<int>(vector<string> t);
template vector<double> conversion<double>(vector<string> t);
template vector<int> groupBy<int>(vector<vector<string>> data, vector<string> valeurs, int j1, int j2);
template vector<double> groupBy<double>(vector<vector<string>> data, vector<string> valeurs, int j1, int j2);