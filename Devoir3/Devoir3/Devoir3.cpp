#include "ABR.h"
#include <iostream>
using namespace std;

int main() {
    Noeud* racine = nullptr; // Initialisation de la racine � nullptr
    ABR arbre(racine);
    char commande;
    int valeur;

    while (true) {
        cout << "Entrez une commande : ";
        cin >> commande;

        switch (commande) {
        case 'I': // Ins�rer une valeur
            cout << "Entrez une valeur : ";
            cin >> valeur;
            arbre.Inserer(racine, valeur); // Passer la racine de l'arbre
            break;
        case 'S': // Supprimer une valeur
            cout << "Entrez une valeur : ";
            cin >> valeur;
            arbre.Supprimer(racine, valeur); // Passer la racine de l'arbre
            break;
        case 'A': // Afficher l'arbre niveau par niveau
            arbre.Afficher_Arbre(racine); // Passer la racine de l'arbre
            cout << endl;
            break;
        case 'H': // Afficher la hauteur de l'arbre
            cout << "Hauteur : " << arbre.Afficher_hauteur(racine) << endl;
            break;
        case 'D': // Afficher le d�s�quilibre de l'arbre
            cout << "D�s�quilibre : " << arbre.Desequilibre(racine) << endl;
            break;
        case 'G': // Afficher les ascendants d'une valeur
            cin >> valeur;
            arbre.Afficher_Ascendant(racine, valeur); // Passer la racine de l'arbre
            cout << endl;
            break;
        case 'T': // Sauvegarder l'arbre (affich� ici comme exemple)
            cout << "Arbre sauvegard� :\n";
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