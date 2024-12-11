#pragma once
#include "Noeud.h"

class ABR {
private:
    Noeud* racine;

public:
    ABR(Noeud* racine);

    ~ABR();

    void Inserer(Noeud* racine, int d);

    void Supprimer(Noeud* racine, int d);

    void Afficher_Arbre(Noeud* racine);

    int Afficher_hauteur(Noeud* racine);

    int Desequilibre(Noeud* racine);

    void Afficher_Ascendant(Noeud* racine, int d);

    void Archiver(Noeud* racine);
};