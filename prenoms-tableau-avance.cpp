#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include "tableau-lecture.hpp"
#include "tableau-donnees.hpp"
#include "tableau-donnees-avance.hpp"
using namespace std;


/**
 * Calcule et affiche :
 * - le nombre total de naissances de garçons et de naissances de filles
 * - l'année qui a eu le plus de naissances (garçons et filles confondus), avec leur nombre
 * - le nombre de naissances en moyenne par an
 * - les nombres de prénoms féminins et masculins différents
 * - le prénom masculin et le prénom féminin le plus populaire
 **/
int main() {

    //int nb = somme(conversionInt(colonne(litTableau("donnees/liste_des_prenoms.txt", 4), 3)));
    int data_g = somme(conversionInt(colonne(selectLignes(litTableau("donnees/liste_des_prenoms.txt", 4), 0, "M"), 3)));
    int data_fe = somme(conversionInt(colonne(selectLignes(litTableau("donnees/liste_des_prenoms.txt", 4), 0, "F"), 3)));

    vector<int> garcon = conversionInt(colonne(selectLignes(litTableau("donnees/liste_des_prenoms.txt", 4), 0, "M"), 3));
    vector<int> fille = conversionInt(colonne(selectLignes(litTableau("donnees/liste_des_prenoms.txt", 4), 0, "F"), 3));

    //vector<vector<string>> garcon_string = colonne(selectLignes(litTableau("donnees/liste_des_prenoms.txt", 4), 0, "M"), 3);
    //vector<vector<string>> fille_string = colonne(selectLignes(litTableau("donnees/liste_des_prenoms.txt", 4), 0, "F"), 3);

    vector<vector<string>> data = litTableau("donnees/liste_des_prenoms.txt", 4);

    vector<string> annee_naissance = distinct(data, 1);
    string male(1, 'M');
    string female(1, 'F');
    vector<vector<string>> data_m = selectLignes(data, 0, male);
    vector<vector<string>> data_f = selectLignes(data, 0, female);

    vector<string> name_m = distinct(data_m, 2);
    vector<string> name_f = distinct(data_f, 2);

    vector<int> nb_naissance_annee = groupByInt(data, annee_naissance, 1, 3);
    vector<int> nb_naissance_m = groupByInt(data_m, name_m, 0, 3);
    vector<int> nb_naissance_f = groupByInt(data_f, name_f, 0, 3);
    int indiceMax_annee = indiceMax(nb_naissance_annee);
    int indiceMax_m = indiceMax(nb_naissance_m);
    int indiceMax_f = indiceMax(nb_naissance_f);


    cout << "Il y a eu " << data_g << " naissance de garcon et " << data_fe << " naissance de filles" << endl;

    cout << "L'annee qui a eu le plus de naissance est " << annee_naissance[indiceMax_annee] << " avec " << nb_naissance_annee[indiceMax_annee] << " naissances" << endl;
    cout << "En moyenne naissent " << moyenne(nb_naissance_annee) << " enfants par an" << endl; 

    cout << "Il y a eu " << name_f.size() << " prenoms de fille differents et " << name_m.size() << " prenoms de garcons" << endl;

    cout << "Le prenoms feminin le plus populaire est "<< name_f[indiceMax_f] << nb_naissance_f[indiceMax_f] << " naissances" << endl;

    cout << "Le prenoms masculin le plus populaire est " << name_m[indiceMax_m] << " avec " << nb_naissance_m[indiceMax_m] << " naissances " << endl;    
    
}
