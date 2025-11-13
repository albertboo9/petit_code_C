#include "../functions/gestion_edt.h"
#include <stdio.h>
#include <stdlib.h>

// 1) Fonction pour initialiser un EmploiDuTemps vide
EmploiDuTemps* initialiserEDT() {
    EmploiDuTemps* edt = (EmploiDuTemps*)malloc(sizeof(EmploiDuTemps));
    if (edt == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire pour EmploiDuTemps\n");
        return NULL;
    }
    edt->seances = NULL;  // Initialement, pas de séances
    edt->taille = 0;
    edt->capacite = 0;    // Capacité initiale à 0, on allouera dynamiquement
    return edt;
}

// 2) Fonction pour ajouter une séance à l'emploi du temps
int ajouterSeance(EmploiDuTemps* edt, Seance* nouvelleSeance) {
    if (edt == NULL || nouvelleSeance == NULL) {
        return -1;  // Erreur : pointeurs nuls
    }

    // Vérifier si on doit redimensionner le tableau
    if (edt->taille >= edt->capacite) {
        // Doubler la capacité ou commencer à 10 si c'est la première fois
        int nouvelleCapacite = (edt->capacite == 0) ? 10 : edt->capacite * 2;
        Seance** nouveauTableau = (Seance**)realloc(edt->seances, nouvelleCapacite * sizeof(Seance*));
        if (nouveauTableau == NULL) {
            fprintf(stderr, "Erreur de réallocation mémoire pour le tableau de séances\n");
            return -1;
        }
        edt->seances = nouveauTableau;
        edt->capacite = nouvelleCapacite;
    }

    // Allouer de la mémoire pour la nouvelle séance
    edt->seances[edt->taille] = (Seance*)malloc(sizeof(Seance));
    if (edt->seances[edt->taille] == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire pour une nouvelle séance\n");
        return -1;
    }

    // Copier les données de la nouvelle séance
    *(edt->seances[edt->taille]) = *nouvelleSeance;

    edt->taille++;
    return 0;  // Succès
}

// 3) Fonction pour libérer la mémoire de l'emploi du temps
void libererEDT(EmploiDuTemps* edt) {
    if (edt == NULL) return;

    for (int i = 0; i < edt->taille; i++) {
        free(edt->seances[i]);
    }
    free(edt->seances);
    free(edt);
}

// 4) Fonction auxiliaire pour afficher l'emploi du temps hebdomadaire trié par heure
void afficherEDTHebdomadaire(Seance** seances, int nbSeances, const char* titre) {
    if (nbSeances == 0) {
        printf("Aucune séance trouvée pour %s.\n", titre);
        return;
    }

    // Trier les séances par jour puis par heure de début
    for (int i = 0; i < nbSeances - 1; i++) {
        for (int j = i + 1; j < nbSeances; j++) {
            int jourI = seances[i]->jour;
            int jourJ = seances[j]->jour;
            int heureI = seances[i]->horaire.heure_debut * 60 + seances[i]->horaire.minute_debut;
            int heureJ = seances[j]->horaire.heure_debut * 60 + seances[j]->horaire.minute_debut;

            if (jourI > jourJ || (jourI == jourJ && heureI > heureJ)) {
                Seance* temp = seances[i];
                seances[i] = seances[j];
                seances[j] = temp;
            }
        }
    }

    printf("\n=== EMPLOI DU TEMPS HEBDOMADAIRE ===\n");
    printf("%s\n", titre);
    printf("=====================================\n\n");

    const char* jours[] = {"Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi", "Samedi", "Dimanche"};
    int jourCourant = -1;

    for (int i = 0; i < nbSeances; i++) {
        Seance* s = seances[i];
        if (s->jour != jourCourant) {
            jourCourant = s->jour;
            printf("%s :\n", jours[jourCourant]);
            printf("--------\n");
        }
        printf("  %02d:%02d - %02d:%02d | %s | Salle: %s | %s\n",
               s->horaire.heure_debut, s->horaire.minute_debut,
               s->horaire.heure_fin, s->horaire.minute_fin,
               s->cours.nom, s->salle, s->site);
    }
    printf("\n");
}

// 5) Implémentations des fonctions de recherche (emploi du temps personnel hebdomadaire)
void afficherEDTParEnseignant(EmploiDuTemps* edt, const char* enseignant) {
    if (edt == NULL || enseignant == NULL) return;

    Seance** seancesFiltrees = (Seance**)malloc(edt->taille * sizeof(Seance*));
    if (seancesFiltrees == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        return;
    }

    int nbSeances = 0;
    for (int i = 0; i < edt->taille; i++) {
        if (strcmp(edt->seances[i]->enseignant, enseignant) == 0) {
            seancesFiltrees[nbSeances++] = edt->seances[i];
        }
    }

    char titre[150];
    sprintf(titre, "Enseignant: %s", enseignant);
    afficherEDTHebdomadaire(seancesFiltrees, nbSeances, titre);

    free(seancesFiltrees);
}

void afficherEDTParClasse(EmploiDuTemps* edt, const char* classe) {
    if (edt == NULL || classe == NULL) return;

    Seance** seancesFiltrees = (Seance**)malloc(edt->taille * sizeof(Seance*));
    if (seancesFiltrees == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        return;
    }

    int nbSeances = 0;
    for (int i = 0; i < edt->taille; i++) {
        if (strcmp(edt->seances[i]->classe, classe) == 0) {
            seancesFiltrees[nbSeances++] = edt->seances[i];
        }
    }

    char titre[150];
    sprintf(titre, "Classe: %s", classe);
    afficherEDTHebdomadaire(seancesFiltrees, nbSeances, titre);

    free(seancesFiltrees);
}

// 6) Fonction pour saisir une nouvelle séance depuis l'utilisateur
Seance* saisirSeanceUtilisateur() {
    Seance* nouvelleSeance = (Seance*)malloc(sizeof(Seance));
    if (nouvelleSeance == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire pour nouvelle séance\n");
        return NULL;
    }

    printf("Saisie d'une nouvelle séance :\n");

    printf("Nom du cours : ");
    fgets(nouvelleSeance->cours.nom, sizeof(nouvelleSeance->cours.nom), stdin);
    nouvelleSeance->cours.nom[strcspn(nouvelleSeance->cours.nom, "\n")] = 0; // Supprimer le \n

    printf("Code du cours : ");
    fgets(nouvelleSeance->cours.code, sizeof(nouvelleSeance->cours.code), stdin);
    nouvelleSeance->cours.code[strcspn(nouvelleSeance->cours.code, "\n")] = 0;

    printf("Département : ");
    fgets(nouvelleSeance->cours.departement, sizeof(nouvelleSeance->cours.departement), stdin);
    nouvelleSeance->cours.departement[strcspn(nouvelleSeance->cours.departement, "\n")] = 0;

    printf("Salle : ");
    fgets(nouvelleSeance->salle, sizeof(nouvelleSeance->salle), stdin);
    nouvelleSeance->salle[strcspn(nouvelleSeance->salle, "\n")] = 0;

    printf("Enseignant : ");
    fgets(nouvelleSeance->enseignant, sizeof(nouvelleSeance->enseignant), stdin);
    nouvelleSeance->enseignant[strcspn(nouvelleSeance->enseignant, "\n")] = 0;

    printf("Classe : ");
    fgets(nouvelleSeance->classe, sizeof(nouvelleSeance->classe), stdin);
    nouvelleSeance->classe[strcspn(nouvelleSeance->classe, "\n")] = 0;

    printf("Site : ");
    fgets(nouvelleSeance->site, sizeof(nouvelleSeance->site), stdin);
    nouvelleSeance->site[strcspn(nouvelleSeance->site, "\n")] = 0;

    printf("Jour (0=Lundi, 1=Mardi, ..., 6=Dimanche) : ");
    scanf("%d", &nouvelleSeance->jour);
    getchar(); // Consommer le \n restant

    printf("Heure de début (heure minute) : ");
    scanf("%d %d", &nouvelleSeance->horaire.heure_debut, &nouvelleSeance->horaire.minute_debut);
    getchar();

    printf("Heure de fin (heure minute) : ");
    scanf("%d %d", &nouvelleSeance->horaire.heure_fin, &nouvelleSeance->horaire.minute_fin);
    getchar();

    return nouvelleSeance;
}

void afficherEDTParSalle(EmploiDuTemps* edt, const char* salle) {
    if (edt == NULL || salle == NULL) return;

    Seance** seancesFiltrees = (Seance**)malloc(edt->taille * sizeof(Seance*));
    if (seancesFiltrees == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        return;
    }

    int nbSeances = 0;
    for (int i = 0; i < edt->taille; i++) {
        if (strcmp(edt->seances[i]->salle, salle) == 0) {
            seancesFiltrees[nbSeances++] = edt->seances[i];
        }
    }

    char titre[150];
    sprintf(titre, "Salle: %s", salle);
    afficherEDTHebdomadaire(seancesFiltrees, nbSeances, titre);

    free(seancesFiltrees);
}

void afficherEDTParDepartement(EmploiDuTemps* edt, const char* departement) {
    if (edt == NULL || departement == NULL) return;

    Seance** seancesFiltrees = (Seance**)malloc(edt->taille * sizeof(Seance*));
    if (seancesFiltrees == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        return;
    }

    int nbSeances = 0;
    for (int i = 0; i < edt->taille; i++) {
        if (strcmp(edt->seances[i]->cours.departement, departement) == 0) {
            seancesFiltrees[nbSeances++] = edt->seances[i];
        }
    }

    char titre[150];
    sprintf(titre, "Département: %s", departement);
    afficherEDTHebdomadaire(seancesFiltrees, nbSeances, titre);

    free(seancesFiltrees);
}

void afficherEDTParSiteEtJour(EmploiDuTemps* edt, const char* site, int jour) {
    if (edt == NULL || site == NULL || jour < 0 || jour > 6) return;

    Seance** seancesFiltrees = (Seance**)malloc(edt->taille * sizeof(Seance*));
    if (seancesFiltrees == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        return;
    }

    int nbSeances = 0;
    for (int i = 0; i < edt->taille; i++) {
        if (strcmp(edt->seances[i]->site, site) == 0 && edt->seances[i]->jour == jour) {
            seancesFiltrees[nbSeances++] = edt->seances[i];
        }
    }

    const char* jours[] = {"Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi", "Samedi", "Dimanche"};
    char titre[150];
    sprintf(titre, "Site: %s - %s", site, jours[jour]);
    afficherEDTHebdomadaire(seancesFiltrees, nbSeances, titre);

    free(seancesFiltrees);
}

void afficherEDTJournalierParCampus(EmploiDuTemps* edt, const char* campus, int jour) {
    if (edt == NULL || campus == NULL || jour < 0 || jour > 6) return;

    Seance** seancesFiltrees = (Seance**)malloc(edt->taille * sizeof(Seance*));
    if (seancesFiltrees == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        return;
    }

    int nbSeances = 0;
    for (int i = 0; i < edt->taille; i++) {
        if (strcmp(edt->seances[i]->site, campus) == 0 && edt->seances[i]->jour == jour) {
            seancesFiltrees[nbSeances++] = edt->seances[i];
        }
    }

    const char* jours[] = {"Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi", "Samedi", "Dimanche"};
    char titre[150];
    sprintf(titre, "Campus: %s - %s", campus, jours[jour]);

    if (nbSeances == 0) {
        printf("\n=== EMPLOI DU TEMPS JOURNALIER ===\n");
        printf("%s\n", titre);
        printf("Aucune séance trouvée pour ce jour.\n\n");
    } else {
        // Trier par heure de début
        for (int i = 0; i < nbSeances - 1; i++) {
            for (int j = i + 1; j < nbSeances; j++) {
                int heureI = seancesFiltrees[i]->horaire.heure_debut * 60 + seancesFiltrees[i]->horaire.minute_debut;
                int heureJ = seancesFiltrees[j]->horaire.heure_debut * 60 + seancesFiltrees[j]->horaire.minute_debut;
                if (heureI > heureJ) {
                    Seance* temp = seancesFiltrees[i];
                    seancesFiltrees[i] = seancesFiltrees[j];
                    seancesFiltrees[j] = temp;
                }
            }
        }

        printf("\n=== EMPLOI DU TEMPS JOURNALIER ===\n");
        printf("%s\n", titre);
        printf("=====================================\n\n");

        for (int i = 0; i < nbSeances; i++) {
            Seance* s = seancesFiltrees[i];
            printf("  %02d:%02d - %02d:%02d | %s | Salle: %s | Enseignant: %s | Classe: %s\n",
                   s->horaire.heure_debut, s->horaire.minute_debut,
                   s->horaire.heure_fin, s->horaire.minute_fin,
                   s->cours.code, s->salle, s->enseignant, s->classe);
        }
        printf("\n");
    }

    free(seancesFiltrees);
}

// =============== Implémentations des fonctions de persistance (format CSV simple) =====================;
// Fonction auxiliaire pour convertir le jour en string
const char* jourToString(int jour) {
    const char* jours[] = {"LUNDI", "MARDI", "MERCREDI", "JEUDI", "VENDREDI", "SAMEDI", "DIMANCHE"};
    if (jour >= 0 && jour <= 6) return jours[jour];
    return "INCONNU";
}

int sauvegarderEDT(EmploiDuTemps* edt, const char* nomFichier) {
    if (edt == NULL || nomFichier == NULL) return -1;

    FILE* fichier = fopen(nomFichier, "w");
    if (fichier == NULL) {
        fprintf(stderr, "Erreur d'ouverture du fichier %s pour sauvegarde\n", nomFichier);
        return -1;
    }

    // Écrire l'en-tête CSV au format de la faculté
    fprintf(fichier, "Jour,Heure_Debut,Heure_Fin,Code_Cours,Departement,Enseignants,Salle,Site,Classe\n");

    // Trier les séances par jour et heure avant sauvegarde
    Seance** seancesTriees = (Seance**)malloc(edt->taille * sizeof(Seance*));
    if (seancesTriees == NULL) {
        fclose(fichier);
        return -1;
    }

    for (int i = 0; i < edt->taille; i++) {
        seancesTriees[i] = edt->seances[i];
    }

    // Trier par jour puis par heure
    for (int i = 0; i < edt->taille - 1; i++) {
        for (int j = i + 1; j < edt->taille; j++) {
            int jourI = seancesTriees[i]->jour;
            int jourJ = seancesTriees[j]->jour;
            int heureI = seancesTriees[i]->horaire.heure_debut * 60 + seancesTriees[i]->horaire.minute_debut;
            int heureJ = seancesTriees[j]->horaire.heure_debut * 60 + seancesTriees[j]->horaire.minute_debut;

            if (jourI > jourJ || (jourI == jourJ && heureI > heureJ)) {
                Seance* temp = seancesTriees[i];
                seancesTriees[i] = seancesTriees[j];
                seancesTriees[j] = temp;
            }
        }
    }

    // Écrire chaque séance au format de la faculté
    for (int i = 0; i < edt->taille; i++) {
        Seance* s = seancesTriees[i];
        fprintf(fichier, "%s,%02dh%02d,%02dh%02d,%s,%s,%s,%s,%s,%s\n",
                jourToString(s->jour),
                s->horaire.heure_debut, s->horaire.minute_debut,
                s->horaire.heure_fin, s->horaire.minute_fin,
                s->cours.code, s->cours.departement,
                s->enseignant, s->salle, s->site, s->classe);
    }

    free(seancesTriees);
    fclose(fichier);
    printf("Emploi du temps sauvegardé dans %s\n", nomFichier);
    return 0;
}

// Fonction auxiliaire pour convertir le jour en string vers int
int convertirJour(const char* jourStr) {
    if (strcmp(jourStr, "LUNDI") == 0) return 0;
    if (strcmp(jourStr, "MARDI") == 0) return 1;
    if (strcmp(jourStr, "MERCREDI") == 0) return 2;
    if (strcmp(jourStr, "JEUDI") == 0) return 3;
    if (strcmp(jourStr, "VENDREDI") == 0) return 4;
    if (strcmp(jourStr, "SAMEDI") == 0) return 5;
    if (strcmp(jourStr, "DIMANCHE") == 0) return 6;
    return -1; // Erreur
}

// Fonction auxiliaire pour parser l'heure au format "07h00"
int parserHeure(const char* heureStr, int* heure, int* minute) {
    if (sscanf(heureStr, "%dh%d", heure, minute) == 2) {
        return 0; // Succès
    }
    return -1; // Erreur
}

EmploiDuTemps* chargerEDT(const char* nomFichier) {
    if (nomFichier == NULL) return NULL;

    FILE* fichier = fopen(nomFichier, "r");
    if (fichier == NULL) {
        fprintf(stderr, "Erreur d'ouverture du fichier %s pour chargement\n", nomFichier);
        return NULL;
    }

    EmploiDuTemps* edt = initialiserEDT();
    if (edt == NULL) {
        fclose(fichier);
        return NULL;
    }

    char ligne[1024];
    // Sauter l'en-tête
    if (fgets(ligne, sizeof(ligne), fichier) == NULL) {
        fclose(fichier);
        libererEDT(edt);
        return NULL;
    }

    // Lire chaque ligne de données (format réel de la faculté)
    while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        Seance nouvelleSeance = {0}; // Initialiser à zéro

        char jourStr[20], heureDebutStr[10], heureFinStr[10];

        // Parser selon le format: Jour,Heure_Debut,Heure_Fin,Code_Cours,Departement,Enseignants,Salle,Site,Classe
        if (sscanf(ligne, "%19[^,],%9[^,],%9[^,],%49[^,],%49[^,],%99[^,],%49[^,],%49[^,],%49[^\n]",
                   jourStr, heureDebutStr, heureFinStr,
                   nouvelleSeance.cours.code, nouvelleSeance.cours.departement,
                   nouvelleSeance.enseignant, nouvelleSeance.salle,
                   nouvelleSeance.site, nouvelleSeance.classe) == 9) {

            // Convertir le jour
            nouvelleSeance.jour = convertirJour(jourStr);
            if (nouvelleSeance.jour == -1) continue; // Jour invalide, ignorer

            // Parser les heures
            if (parserHeure(heureDebutStr, &nouvelleSeance.horaire.heure_debut, &nouvelleSeance.horaire.minute_debut) != 0) continue;
            if (parserHeure(heureFinStr, &nouvelleSeance.horaire.heure_fin, &nouvelleSeance.horaire.minute_fin) != 0) continue;

            // Le nom du cours sera le même que le code pour simplifier
            strcpy(nouvelleSeance.cours.nom, nouvelleSeance.cours.code);

            if (ajouterSeance(edt, &nouvelleSeance) != 0) {
                fprintf(stderr, "Erreur lors de l'ajout d'une séance depuis le fichier\n");
                break;
            }
        }
    }

    fclose(fichier);
    printf("Emploi du temps chargé depuis %s (%d séances)\n", nomFichier, edt->taille);
    return edt;
}