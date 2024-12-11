#include "ABR.h"
#include <iostream>
using namespace std;

// Constructeur
ABR::ABR(Noeud* racine) {
    this->racine = racine;
}

// Destructeur
ABR::~ABR() {
    // Supprime récursivement tous les nœuds
    while (racine != nullptr) {
        Supprimer(racine, racine->valeur);
    }
}

// Fonction pour insérer une valeur
void ABR::Inserer(Noeud* racine, int d) {
    if (racine == nullptr) {
        racine = new Noeud{d, nullptr, nullptr};
    } else if (d < racine->valeur) {
        if (racine->gauche == nullptr) {
            racine->gauche = new Noeud{d, nullptr, nullptr};
        } else {
            Inserer(racine->gauche, d);
        }
    } else {
        if (racine->droite == nullptr) {
            racine->droite = new Noeud{d, nullptr, nullptr};
        } else {
            Inserer(racine->droite, d);
        }
    }
}

// Fonction pour supprimer une valeur
void ABR::Supprimer(Noeud* racine, int d) {
    if (racine == nullptr) return;

    if (d < racine->valeur) {
        Supprimer(racine->gauche, d);
    } else if (d > racine->valeur) {
        Supprimer(racine->droite, d);
    } else {
        // Cas 1: Aucun enfant
        if (racine->gauche == nullptr && racine->droite == nullptr) {
            delete racine;
            racine = nullptr;
        } 
        // Cas 2: Un seul enfant
        else if (racine->gauche == nullptr) {
            Noeud* temp = racine;
            racine = racine->droite;
            delete temp;
        } else if (racine->droite == nullptr) {
            Noeud* temp = racine;
            racine = racine->gauche;
            delete temp;
        } 
        // Cas 3: Deux enfants
        else {
            Noeud* temp = racine->droite;
            while (temp->gauche != nullptr) {
                temp = temp->gauche;
            }
            racine->valeur = temp->valeur;
            Supprimer(racine->droite, temp->valeur);
        }
    }
}

// Fonction pour afficher l'arbre en parcours infixe
void ABR::Afficher_Arbre(Noeud* racine) {
    if (racine == nullptr) return;
    Afficher_Arbre(racine->gauche);
    cout << racine->valeur << " ";
    Afficher_Arbre(racine->droite);
}

// Fonction pour afficher la hauteur de l'arbre
int ABR::Afficher_hauteur(Noeud* racine) {
    if (racine == nullptr) return 0;
    int hauteurGauche = Afficher_hauteur(racine->gauche);
    int hauteurDroite = Afficher_hauteur(racine->droite);
    return max(hauteurGauche, hauteurDroite) + 1;
}

// Fonction pour afficher le déséquilibre de l'arbre
int ABR::Desequilibre(Noeud* racine) {
    if (racine == nullptr) return 0;
    return Afficher_hauteur(racine->gauche) - Afficher_hauteur(racine->droite);
}

// Fonction pour afficher les ascendants d'une valeur
void ABR::Afficher_Ascendant(Noeud* racine, int d) {
    if (racine == nullptr) return;
    if (racine->valeur == d) {
        cout << racine->valeur << " ";
        return;
    } else if (d < racine->valeur) {
        cout << racine->valeur << " ";
        Afficher_Ascendant(racine->gauche, d);
    } else {
        cout << racine->valeur << " ";
        Afficher_Ascendant(racine->droite, d);
    }
}

// Fonction pour archiver (sauvegarder) l'arbre
void ABR::Archiver(Noeud* racine) {
    if (racine == nullptr) return;
    // Par exemple, écrire dans un fichier (ici, sortie console comme exemple)
    Archiver(racine->gauche);
    cout << racine->valeur << "\n";
    Archiver(racine->droite);
}
