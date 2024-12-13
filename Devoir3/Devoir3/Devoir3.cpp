#include "ABR.h"
#include <string>
#include <iostream>
using namespace std;

int main() {
    Noeud* racine = nullptr; // Initialisation de la racine à nullptr
    ABR arbre(racine);
    string utilisateur;
    char commande;
    int valeur;

    while (true) {
        cout << "Choisissez parmis les options suivantes : " << endl;
        cout << "(I)nserer" << endl;
        cout << "(S)upprimer" << endl;
        cout << "(A)fficher" << endl;
        cout << "Voir la (H)auteur" << endl;
        cout << "Voir le (D)esequilibre" << endl;
        cout << "(G)" << endl;
        cout << "(T) Archiver" << endl;
        cout << "(Q)uitter le programme" << endl;
        cin >> utilisateur;

        commande = utilisateur[0];
        commande = toupper(commande);        

        switch (commande) {
        case 'I': // Insérer une valeur
            cout << "Entrez une valeur : ";
            cin >> valeur;
            arbre.Inserer(racine, valeur); // Passer la racine de l'arbre
            cout << "La valeur " << valeur << " a ete inseree" << endl;
            break;
        case 'S': // Supprimer une valeur
            cout << "Entrez une valeur : ";
            cin >> valeur;
            arbre.Supprimer(racine, valeur); // Passer la racine de l'arbre
            cout << "La valeur " << valeur << " a ete supprimee" << endl;
            break;
        case 'A': // Afficher l'arbre niveau par niveau
            arbre.Afficher_Arbre(racine); // Passer la racine de l'arbre
            cout << endl;
            break;
        case 'H': // Afficher la hauteur de l'arbre
            cout << "Hauteur : " << arbre.Afficher_hauteur(racine) << endl;
            break;
        case 'D': // Afficher le déséquilibre de l'arbre
            cout << "Desequilibre : " << arbre.Desequilibre(racine) << endl;
            break;
        case 'G': // Afficher les ascendants d'une valeur
            cout << "Entrez une valeur pour voir les noeuds ascendant : ";
            cin >> valeur;
            arbre.Afficher_Ascendant(racine, valeur); // Passer la racine de l'arbre
            cout << endl;
            break;
        case 'T': // Sauvegarder l'arbre (affiché ici comme exemple)
            cout << "Arbre sauvegarde !" << endl;
            arbre.Archiver(racine);
            break;
        case 'Q': // Quitter le programme
            return 0;
        default:
            cout << "Commande inconnue." << endl;
        }
    }

    return 0;
}