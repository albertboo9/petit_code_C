#ifndef GESTION_EDT_H
#define GESTION_EDT_H

#include "types.h"

// Fonction pour initialiser un EmploiDuTemps vide
EmploiDuTemps* initialiserEDT();

// Fonction pour ajouter une séance à l'emploi du temps
int ajouterSeance(EmploiDuTemps* edt, Seance* nouvelleSeance);

// Fonction pour libérer la mémoire de l'emploi du temps
void libererEDT(EmploiDuTemps* edt);

// Fonctions de recherche (déclarations pour plus tard)
void afficherEDTParEnseignant(EmploiDuTemps* edt, const char* enseignant);
void afficherEDTParClasse(EmploiDuTemps* edt, const char* classe);
void afficherEDTParSalle(EmploiDuTemps* edt, const char* salle);
void afficherEDTParDepartement(EmploiDuTemps* edt, const char* departement);
void afficherEDTParSiteEtJour(EmploiDuTemps* edt, const char* site, int jour);

// Fonctions de persistance (déclarations pour plus tard)
int sauvegarderEDT(EmploiDuTemps* edt, const char* nomFichier);
EmploiDuTemps* chargerEDT(const char* nomFichier);

// Fonction pour saisir une nouvelle séance depuis l'utilisateur
Seance* saisirSeanceUtilisateur();

#endif // GESTION_EDT_H