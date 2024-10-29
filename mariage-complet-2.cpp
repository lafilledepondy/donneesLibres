#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include "tableau-donnees.hpp"
#include "tableau-lecture.hpp"
using namespace std;

/** Infrastructure minimale de test **/
#define CHECK(test) if (!(test)) cerr << "Test failed in file " << __FILE__ << " line " << __LINE__ << ": " #test << endl

vector<string> annees = {"2010", "2011", "2012", "2013", "2014", "2015"};
vector<string> jours = {"Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi", "Samedi", "Dimanche"};


/** Construction du tableau des mariages par années à partir d'un
 * tableau de données 2D (de chaines de caractères)
 * Chaque ligne contient : l'année, le jour, puis le nombre de mariages
 * @param t un tableau de données 2D de chaines de caractère
 * @return un tableau d'entiers tel que dans chaque
 * case d'indice i, on trouve le nombre total de mariages de l'année 2010+i
 **/
vector<int> creeTableauAnnee(vector<vector<string>> data) {
    vector<int> tab = {0, 0, 0, 0, 0, 0};  

    tab[0] = somme(conversionInt(colonne(selectLignes(data, 0, "2010"), 2)));
    tab[1] = somme(conversionInt(colonne(selectLignes(data, 0, "2011"), 2)));
    tab[2] = somme(conversionInt(colonne(selectLignes(data, 0, "2012"), 2)));
    tab[3] = somme(conversionInt(colonne(selectLignes(data, 0, "2013"), 2)));
    tab[4] = somme(conversionInt(colonne(selectLignes(data, 0, "2014"), 2)));
    tab[5] = somme(conversionInt(colonne(selectLignes(data, 0, "2015"), 2)));

    return tab;
}

/** Test de la fonction CreeTableauAnnee **/
void testCreeTableauAnnee() {
    vector<vector<string>> data = litTableau("donnees/statistiques-des-jours-des-mariages.txt", 3);
    vector<int> t = creeTableauAnnee(data);
    CHECK(t[0] == 9195); // Nombre de mariages en 2010
    CHECK(t[3] == 9443); // Nombre de mariages en 2013
    CHECK(t[5] == 9046); // Nombre de mariages en 2015
}

/** Renvoie le numéro du jour correspondant à la chaîne de caractères
 * @param jour une chaine de caractères contenant un jour de la semaine (première lettre en majuscule)
 * @return un numéro entre 0 et 6 correspondant au jour de la semaine ou
 * -1 si le jour n'est pas valide
 **/
int indiceJour(string jour) {
    for(int i=0; i < jours.size(); i++) {
        if (jour == jours[i]) {
            return i;
        }
    }
    return -1;
}

void testIndiceJour() {
    CHECK(indiceJour("Lundi") == 0);
    CHECK(indiceJour("Samedi") == 5);
    CHECK(indiceJour("Dimanche") == 6);
    CHECK(indiceJour("samedi") == -1);
}

/** Construction du tableau des mariages à partir d'un
 * tableau de données 2D (de chaines de caractères)
 * suivi d'un jour, puis d'un nombre de mariages
 * Chaque ligne contient : l'année, le jour, puis le nombre de mariages
 * @param t un tableau de données 2D de chaines de caractère
 * @return un tableau d'entiers tel que dans chaque
 * case d'indice i, on trouve le nombre total de mariages célébrés le jour i
 **/
vector<int> creeTableauJours(vector<vector<string>> data) {
    vector<int> tab = {0, 0, 0, 0, 0, 0, 0};  

    tab[0] = somme(conversionInt(colonne(selectLignes(data, 1, "Lundi"), 2)));
    tab[1] = somme(conversionInt(colonne(selectLignes(data, 1, "Mardi"), 2)));
    tab[2] = somme(conversionInt(colonne(selectLignes(data, 1, "Mercredi"), 2)));
    tab[3] = somme(conversionInt(colonne(selectLignes(data, 1, "Jeudi"), 2)));
    tab[4] = somme(conversionInt(colonne(selectLignes(data, 1, "Vendredi"), 2)));
    tab[5] = somme(conversionInt(colonne(selectLignes(data, 1, "Samedi"), 2)));
    tab[6] = somme(conversionInt(colonne(selectLignes(data, 1, "Dimanche"), 2)));

    return tab;
}

/** Test de la fonction litTableauJours **/
void testCreeTableauJours() {
    vector<vector<string>> data = litTableau("donnees/statistiques-des-jours-des-mariages.txt", 3);
    vector<int> t = creeTableauJours(data);
    CHECK(t[0] == 4171); // Nombre de mariages le lundi
    CHECK(t[3] == 4393); // Nombre de mariages le jeudi
    CHECK(t[6] == 2); // Nombre de mariages le dimanche
}


/** Lance les fonctions de test puis affiche :
 * - le nombre total de mariages
 * - le nombre moyen de mariages célébrés par an
 * - l'année où l'on a célébré le plus de mariages (et leur nombre)
 * - le jour de la semaine où l'on célèbre le plus de mariages (et leur nombre)
 * - le pourcentage de mariages célébrés un samedi
 **/
int main() {
    testCreeTableauAnnee();
    testIndiceJour();
    testCreeTableauJours();

    vector<vector<string>> data = litTableau("donnees/statistiques-des-jours-des-mariages.txt", 3);
    vector<int> t = creeTableauAnnee(data);
    vector<int> annee = {2010, 2011, 2012, 2013, 2014, 2015};
    vector<string> jours = {"Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi", "Samedi", "Dimanche"};
    vector<vector<string>> data_j = litTableau("donnees/statistiques-des-jours-des-mariages.txt", 3);
    vector<int> t_j = creeTableauJours(data);

    cout << "Le nombre de total de mariages celebres entre 2010 et 2015 est de " << somme(t) << endl;
    cout << "Le nombre de mariages celebres en moyenne par an est de " << moyenne(t) << endl;
    cout << "L'annee ou l'on a celebre le plus de mariages est " << annee[indiceMax(t)] << " avec " << t[indiceMax(t)] << " mariages" << endl;
    cout << "Le jour de la semaine ou l'on a celebre le plus de mariages est le " << jours[indiceMax(t)] << " avec " << t[indiceMax(t)] << " mariages" << endl;
    cout << "Le pourcentage de mariages celebres le samedi est de " << ((t_j[indiceMax(t_j)]*100)/float(somme(t))) << "%" << endl;


    
}

