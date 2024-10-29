#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

/** Infrastructure minimale de test **/
#define CHECK(test) if (!(test)) cerr << "Test failed in file " << __FILE__ << " line " << __LINE__ << ": " #test << endl

vector<vector<string>> tableauTest = {
    { "M", "2011", "Bubulle", "3"},
    { "F", "2012", "Bichette", "4"},
    { "F", "2011", "Babouche", "7"},
    { "F", "2011", "Ziboulette", "1"}
};

/** Affiche le contenu d'un tableau de chaînes à deux dimensions
 * @param tableau un tableau à deux dimensions
 **/
void afficheTableau(vector<vector<string>> tableau) {
    // parcourt le tableau 2D en affichant les elements
    for ( int i = 0; i < tableau.size(); i++ ) {    
        for ( int j = 0; j < tableau[i].size(); j++) { 
            cout << tableau[i][j] << " " ;
        } cout << endl; 
    }
}

void testAfficheTableau() {
    afficheTableau(tableauTest);
}


/** Construction d'un tableau 2D de chaines de caractères lu depuis un fichier
 * @param fichier le nom d'un fichier contenant un nombre fixe
  * de colonnes séparées par des espaces
 * @param nb_colonnes le nombre de colonnes du fichier
 * @return un tableau de chaines de caractères à deux dimensions
 **/
vector<vector<string>> litTableau(string nom_fichier, int nb_colonnes) {
    ifstream fichier(nom_fichier);
    vector<vector<string>> tab = {};
    while (fichier ) {
        vector<string> lignes = {};
        // parcourt lignes par lignes en recuperant dans un sous-tableau (1D) les elements du lignes
        for (int i = 0; i < nb_colonnes; i++) {
            string word;
            if ( fichier >> word and word != "") {
                lignes.push_back(word);
            }
        }
        // ajoute dans un tableau 2D les sous-tableau recuperer
        if (lignes.size() == nb_colonnes) {
            tab.push_back(lignes);
        }
    }
    fichier.close();
    return tab;
}

/** Test de la fonction litTableau **/
void testLitTableau() {
    CHECK(litTableau("donnees/donnees-test.txt", 4) == tableauTest);
    vector<vector<string>> t = litTableau("donnees/liste_des_prenoms.txt", 4);
    CHECK(t.size() == 22994);
    CHECK(t[0][0] == "F");
    CHECK(t[4][2] == "Astrid");
    CHECK(t[5][3] == "12");
}

/** Extraction d'une colonne d'un tableau de données
 * @param t un tableau 2D de chaines de caractères
 * @param i un numéro de colonne
 * @return la colonne j, représentée par un vecteur de chaines de caractères
 **/
vector<string> colonne(vector<vector<string>> t, int j) {
    vector<string> final_list; 
    // parcourt la colonne en recuperant dans un tableau les elements
    for ( int i = 0; i < t.size() ; i++ )
        final_list.push_back(t[i][j]);       
    return final_list;  
}

/** Test de la fonction colonne **/
void testColonne() {
    CHECK(colonne(tableauTest, 0) == vector<string>({"M","F","F","F"}));
    CHECK(colonne(tableauTest, 1) == vector<string>({"2011","2012","2011","2011"}));
    CHECK(colonne(tableauTest, 2) == vector<string>({"Bubulle","Bichette","Babouche","Ziboulette"}));
    CHECK(colonne(tableauTest, 3) == vector<string>({"3","4","7","1"}));
}

/** Convertit un tableau de chaines de caractères en un tableau d'entiers
 * @param t, un vecteur de chaines de caractères
 * @return un vecteur d'entiers
 **/
vector<int> conversionInt(vector<string> t) {
    vector<int> resultat = vector<int>(t.size());
    for(int i =0; i < t.size(); i++) {
        istringstream(t[i]) >> resultat[i];
    }
    return resultat;
}

void testConversionInt() {
    CHECK(conversionInt({}) == vector<int>({}));
    CHECK(conversionInt({"1","2","3"}) == vector<int>({1,2,3}));
}

/** copier la fonction somme déjà écrite **/
int somme(vector<int> t) {
    int sum = 0;
    for (int i = 0; i < t.size(); i++) 
        sum += t[i];
    return sum; 
}

/** copier la fonction moyenne déjà écrite **/
int moyenne(vector<int> t) {
    return somme(t)/t.size();
}

/** copier la fonction indiceMax déjà écrite **/
int indiceMax(vector<int> t) {
    int max = 0;
    if (t.size() == 0) 
        return -1;
    for (int i = 0; i<t.size(); i++) {
        if (t[i] > t[max])
            max = i;
    } 
    return max;
}

/** Sélection des lignes d'un tableau de données
 * Sélectionne un ensemble de lignes en fonction d'un critère donné
 * @param t, un tableau contenant des lignes de données
 * @param j, l'indice de la colonne à vérifier
 * @param valeur, une chaine de caractères correspondant au critère
 * @return un tableau de données ne contenant que les lignes de t telles
 *  que la colonne j ait la valeur correspondant au critère
 **/
vector<vector<string>> selectLignes(vector<vector<string>> t, int j, string valeur) {
    vector<vector<string>> tab;
    // parcourt les lignes en verifiant au ligne j si la valeur donne est presente
    for ( int i = 0; i < t.size(); i++) { 
        if ( (t[i][j]) == valeur)
            tab.push_back(t[i]);
    } 
    return tab; 
}

/** Test de la fonction selectLignes **/
void testSelectLignes() {
    CHECK(selectLignes(tableauTest, 0, "M") == vector<vector<string>>({{ "M", "2011", "Bubulle", "3"}}));
    CHECK(selectLignes(tableauTest, 1, "2011") == vector<vector<string>>({{ "M", "2011", "Bubulle", "3"}, { "F", "2011", "Babouche", "7"}, { "F", "2011", "Ziboulette", "1"}}));
}

/** Lance les tests de litTableau, selectLignes et colonne puis
 * affiche le nombre total de naissances puis
 * demande à l'utilisateur un prénom et calcule et affiche
 * - le nombre de garçons et filles à qui l'on a donné ce prénom
 * - la meilleure année pour ce prénom pour les garçons et filles
 **/
int main() {

    //cout << "Lancement des test de afficheTableau :" << endl;
    //testAfficheTableau();
    //cout << "Lancement des test de litTableau" << endl;
    testLitTableau();
    //cout << "Lancement des test de colonne" << endl;
    testColonne();
    //cout << "Lancement des test de selectLignes " << endl;
    testSelectLignes();
    //cout << "Lancement des test de conversionInt " << endl;
    testConversionInt();


 
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
        cout << "Le prenom " << prenom << " n'a ete donne a aucun garcon entre 2006 et 2021" << endl;

    if (somme(conversionInt(colonne(selectLignes(selectLignes(litTableau("donnees/liste_des_prenoms.txt", 4), 2, prenom), 0, "F"), 3))) != 0){
        cout << "Le prenom " << prenom << " a ete donne a " << somme(conversionInt(colonne(selectLignes(selectLignes(litTableau("donnees/liste_des_prenoms.txt", 4), 2, prenom), 0, "F"), 3))) << " fille entre 2006 et 2021 " << endl;
        string x = colonne(selectLignes(selectLignes(litTableau("donnees/liste_des_prenoms.txt", 4), 2, prenom), 0, "F"), 3)[indiceMax(conversionInt(colonne(selectLignes(selectLignes(litTableau("donnees/liste_des_prenoms.txt", 4), 2, prenom), 0, "F"), 3)))];
        vector<vector<string>> y = selectLignes(selectLignes(selectLignes(litTableau("donnees/liste_des_prenoms.txt", 4), 2, prenom), 0, "F"), 3, x); 
        cout << "L'annee la plus forte est " << y[0][1] << " avec " << colonne(selectLignes(selectLignes(litTableau("donnees/liste_des_prenoms.txt", 4), 2, prenom), 0, "F"), 3)[indiceMax(conversionInt(colonne(selectLignes(selectLignes(litTableau("donnees/liste_des_prenoms.txt", 4), 2, prenom), 0, "F"), 3)))] << " enfants" << endl;
    } else
        cout << "Le prenom " << prenom << " n'a ete donne a aucun fille entre 2006 et 2021"; 

    
   
}

