#ifndef TYPES_H
#define TYPES_H

#include <stdlib.h>
#include <string.h>

// Structure pour représenter une plage horaire
typedef struct {
    int heure_debut;  // Heure de début (0-23)
    int minute_debut; // Minute de début (0-59)
    int heure_fin;    // Heure de fin (0-23)
    int minute_fin;   // Minute de fin (0-59)
} PlageHoraire;

// Structure pour représenter un cours
typedef struct {
    char nom[100];     // Nom du cours
    char code[20];     // Code du cours (ex: "INFO101")
    char departement[50]; // Département (ex: "Informatique")
} Cours;

// Structure pour représenter une séance
typedef struct {
    Cours cours;           // Le cours associé
    PlageHoraire horaire;  // Plage horaire de la séance
    char salle[50];        // Salle (ex: "A101")
    char enseignant[100];  // Nom de l'enseignant
    char classe[50];       // Classe (ex: "L3 Info")
    char site[50];         // Site (ex: "Campus A")
    int jour;              // Jour de la semaine (0=Lundi, 1=Mardi, ..., 6=Dimanche)
} Seance;

// Structure pour l'emploi du temps (tableau dynamique de séances)
typedef struct {
    Seance** seances;  // Tableau de pointeurs vers Seance
    int taille;        // Nombre actuel de séances
    int capacite;      // Capacité actuelle du tableau
} EmploiDuTemps;

#endif // TYPES_H