#pragma once
#include "Noeud.h"
#include <vector>

class ABR {
private:
    Noeud* racine;

public:
    ABR(Noeud* racine);

    ~ABR();

    void Inserer(Noeud*& racine, int d);

    void Supprimer(Noeud*& racine, int d);

    void Afficher_Arbre(Noeud*& racine);

    void Afficher_Arbre_R(Noeud*& racine, std::vector<int>* tableau, int current);

    int Afficher_hauteur(Noeud*& racine);

    int Desequilibre(Noeud*& racine);

    void Afficher_Ascendant(Noeud*& racine, int d);

    void Archiver(Noeud*& racine);
};