#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include "tableau-donnees.hpp"
#include "tableau-lecture.hpp"
using namespace std;


/**
 * Demande à l'utilisateur un prénom et calcule
 * - le nombre de garçons et filles à qui l'on a donné ce prénom
 * - la meilleure année pour ce prénom pour les garçons et filles
 **/
int main() {
    string prenom;
    cout << "Nombre total de naissance : " << somme(conversionInt(colonne(litTableau("donnees/liste_des_prenoms.txt", 4), 3))) << endl;
    cout << "Choisissez un prenom : " ;
    cin >> prenom;

    if (somme(conversionInt(colonne(selectLignes(selectLignes(litTableau("donnees/liste_des_prenoms.txt", 4), 2, prenom), 0, "M"), 3))) != 0){
        cout << "Le prenom " << prenom << " a ete donne a " << somme(conversionInt(colonne(selectLignes(selectLignes(litTableau("donnees/liste_des_prenoms.txt", 4), 2, prenom), 0, "M"), 3))) << " garcon entre 2006 et 2021 " << endl;
        string x = colonne(selectLignes(selectLignes(litTableau("donnees/liste_des_prenoms.txt", 4), 2, prenom), 0, "M"), 3)[indiceMax(conversionInt(colonne(selectLignes(selectLignes(litTableau("donnees/liste_des_prenoms.txt", 4), 2, prenom), 0, "M"), 3)))];
        vector<vector<string>> y = selectLignes(selectLignes(selectLignes(litTableau("donnees/liste_des_prenoms.txt", 4), 2, prenom), 0, "M"), 3, x); 
        cout << "L'annee la plus forte est " << y[0][1] << " avec " << colonne(selectLignes(selectLignes(litTableau("donnees/liste_des_prenoms.txt", 4), 2, prenom), 0, "M"), 3)[indiceMax(conversionInt(colonne(selectLignes(selectLignes(litTableau("donnees/liste_des_prenoms.txt", 4), 2, prenom), 0, "M"), 3)))] << " enfants" << endl;
    } else
        cout << "Le prenom " << prenom << " n'a ete donne a aucun garcon entre 2006 et 2021";

    if (somme(conversionInt(colonne(selectLignes(selectLignes(litTableau("donnees/liste_des_prenoms.txt", 4), 2, prenom), 0, "F"), 3))) != 0){
        cout << "Le prenom " << prenom << " a ete donne a " << somme(conversionInt(colonne(selectLignes(selectLignes(litTableau("donnees/liste_des_prenoms.txt", 4), 2, prenom), 0, "F"), 3))) << " fille entre 2006 et 2021 " << endl;
        string x = colonne(selectLignes(selectLignes(litTableau("donnees/liste_des_prenoms.txt", 4), 2, prenom), 0, "F"), 3)[indiceMax(conversionInt(colonne(selectLignes(selectLignes(litTableau("donnees/liste_des_prenoms.txt", 4), 2, prenom), 0, "F"), 3)))];
        vector<vector<string>> y = selectLignes(selectLignes(selectLignes(litTableau("donnees/liste_des_prenoms.txt", 4), 2, prenom), 0, "F"), 3, x); 
        cout << "L'annee la plus forte est " << y[0][1] << " avec " << colonne(selectLignes(selectLignes(litTableau("donnees/liste_des_prenoms.txt", 4), 2, prenom), 0, "F"), 3)[indiceMax(conversionInt(colonne(selectLignes(selectLignes(litTableau("donnees/liste_des_prenoms.txt", 4), 2, prenom), 0, "F"), 3)))] << " enfants" << endl;
    } else
        cout << "Le prenom " << prenom << " n'a ete donne a aucun fille entre 2006 et 2021"; 

}

