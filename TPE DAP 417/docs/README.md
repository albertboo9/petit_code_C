# Gestion d'Emploi du Temps (EDT) - Faculté des Sciences

Un programme C modulaire pour la gestion et la diffusion de l'emploi du temps de la faculté des sciences. Les données sont saisies manuellement et stockées en mémoire avec possibilité de persistance sur disque.

## Fonctionnalités

### Gestion Dynamique des Données
- **Initialisation** : Création d'un emploi du temps vide avec allocation dynamique
- **Ajout de séances** : Ajout illimité de séances avec redimensionnement automatique du tableau
- **Gestion mémoire** : Allocation et libération propre de la mémoire

### Recherche et Diffusion (Emploi du Temps Personnel)
- **Emploi du temps hebdomadaire** pour un **Enseignant** (trié par jour et heure)
- **Emploi du temps hebdomadaire** pour une **Classe/Étudiant** (trié par jour et heure)
- **Emploi du temps hebdomadaire** d'une **Salle**
- **Emploi du temps hebdomadaire** d'un **Département**
- **Emploi du temps journalier** par **Site + Jour**
- **Emploi du temps journalier** par **Campus** (ex: "CAMPUS 2 (NDOGBONG)")

### Persistance
- **Sauvegarde** : Export des données au format CSV
- **Chargement** : Import des données depuis un fichier CSV

### Interface Utilisateur
- Menu interactif simple dans le terminal
- Saisie guidée des nouvelles séances

## Architecture

Le projet suit une architecture modulaire avec séparation en fichiers `.h` et `.c` conserver respectivement dans les dossiers **functions** et **code** :

- [`types.h`](/functions/types.h) : Définitions des structures de données
- [`gestion_edt.h`](/functions/gestion_edt.h) : Déclarations des fonctions
- [`gestion_edt.c`](/code/gestion_edt.c) : Implémentations des fonctions
- [`main.c`](/code/main.c) : Programme principal avec menu interactif

## Structures de Données

### PlageHoraire
```c
typedef struct {
    int heure_debut;  // 0-23
    int minute_debut; // 0-59
    int heure_fin;    // 0-23
    int minute_fin;   // 0-59
} PlageHoraire;
```

### Cours
```c
typedef struct {
    char nom[100];     // Nom du cours
    char code[20];     // Code (ex: "INFO101")
    char departement[50]; // Département
} Cours;
```

### Seance
```c
typedef struct {
    Cours cours;           // Cours associé
    PlageHoraire horaire;  // Horaire de la séance
    char salle[50];        // Salle
    char enseignant[100];  // Enseignant
    char classe[50];       // Classe
    char site[50];         // Site
    int jour;              // 0=Lundi, 1=Mardi, ..., 6=Dimanche
} Seance;
```

### EmploiDuTemps
```c
typedef struct {
    Seance** seances;  // Tableau dynamique de pointeurs vers Seance
    int taille;        // Nombre actuel de séances
    int capacite;      // Capacité actuelle du tableau
} EmploiDuTemps;
```

## Compilation et Exécution

### Compilation
```bash
gcc -o edt main.c gestion_edt.c -std=c99
```

### Exécution
```bash
./edt
```

## Utilisation

1. **Ajouter une séance** : Saisir manuellement les informations de la séance
2. **Rechercher** : Filtrer l'emploi du temps selon différents critères
3. **Sauvegarder/Charger** : Persister les données dans un fichier CSV

## Contraintes Techniques

- **Langage** : C99/C11 uniquement
- **Bibliothèques** : Uniquement `stdlib.h`, `stdio.h`, `string.h`
- **Mémoire** : Gestion dynamique avec `malloc`, `realloc`, `free`
- **Persistance** : Format CSV simple pour la compatibilité

## Gestion de la Mémoire

Le programme utilise une gestion rigoureuse de la mémoire :
- Allocation dynamique pour les séances
- Redimensionnement automatique du tableau (doublement de capacité)
- Libération complète en fin de programme

## Format CSV

Le système prend en charge le format CSV réel de la faculté des sciences :
```
Jour,Heure_Debut,Heure_Fin,Code_Cours,Departement,Enseignants,Salle,Site,Classe
```

Exemple réel (salle RDM 004) :
```
Jour,Heure_Debut,Heure_Fin,Code_Cours,Departement,Enseignants,Salle,Site,Classe
LUNDI,07h00,10h00,PHY 233,PH,"Dr Kemgang /Pr Wembe",RDM 004,CAMPUS 2 (NDOGBONG),CM/TD
LUNDI,10h00,13h00,PHY 263,PH,"Dr Ateba B. /Dr Maza",RDM 004,CAMPUS 2 (NDOGBONG),CM/TD
```

**Jours supportés** : LUNDI, MARDI, MERCREDI, JEUDI, VENDREDI, SAMEDI, DIMANCHE
**Format heure** : HHhMM (ex: 07h00, 15h30)

## Auteur

Développé pour la gestion de l'emploi du temps de la faculté des sciences.

## Licence

Ce projet est fourni tel quel pour des fins éducatives.