#include "ABR.h"
#include <iostream>
#include <vector>
#include <fstream> 
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
void ABR::Inserer(Noeud*& racine, int d) {
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
void ABR::Supprimer(Noeud*& racine, int d) {
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

void ABR::Afficher_Arbre(Noeud*& racine)
{
    if (racine == nullptr) return;
    int hauteur = Afficher_hauteur(racine);
    int taille = pow(2, hauteur) - 1;
    vector<int> tableau(taille, -1);
    int current = 1;

    Afficher_Arbre_R(racine, &tableau, current);

    int etage = (taille + 1)/2;
    int compteur = 0;
    for (int i = taille - 1; i >= 0; i--)
    {
        cout << tableau[i] << " ";
        compteur++;
        if (compteur == etage)
        {
            cout << endl;
            compteur = 0;
            etage = etage / 2;
        }
    }
}

// Fonction pour afficher l'arbre
void ABR::Afficher_Arbre_R(Noeud*& racine, vector<int>* tableau, int current) {
    if (racine == nullptr) return;
    (*tableau)[current - 1] = racine->valeur;
    Afficher_Arbre_R(racine->gauche, tableau, current*2);
    Afficher_Arbre_R(racine->droite, tableau, current*2 + 1);
}

// Fonction pour afficher la hauteur de l'arbre
int ABR::Afficher_hauteur(Noeud*& racine) {
    if (racine == nullptr) return 0;
    int hauteurGauche = Afficher_hauteur(racine->gauche);
    int hauteurDroite = Afficher_hauteur(racine->droite);
    return max(hauteurGauche, hauteurDroite) + 1;
}

// Fonction pour afficher le déséquilibre de l'arbre
int ABR::Desequilibre(Noeud*& racine) {
    if (racine == nullptr) return 0;
    return Afficher_hauteur(racine->gauche) - Afficher_hauteur(racine->droite);
}

// Fonction pour afficher les ascendants d'une valeur
void ABR::Afficher_Ascendant(Noeud*& racine, int d) {
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
void ABR::Archiver(Noeud*& racine) {
    if (racine == nullptr)return;
    int hauteur = Afficher_hauteur(racine);
    int taille = pow(2, hauteur) - 1;
    vector<int> tableau(taille, -1);
    int current = 1;
    string nomFichier = "archive.txt";
    ofstream fichier;

    fichier.open(nomFichier, std::ios::out);

    Afficher_Arbre_R(racine, &tableau, current);

    int etage = 1;
    int compteur = 0;
    for (int i = 0; i < taille; i++)
    {
        fichier << tableau[i] << " ";
        compteur++;
        if (compteur == etage)
        {
            fichier << endl;
            compteur = 0;
            etage = etage * 2;
        }
    }

    fichier.close();
}
