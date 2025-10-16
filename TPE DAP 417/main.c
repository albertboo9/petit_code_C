#include "gestion_edt.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fonction pour afficher le menu principal
void afficherMenu() {
    printf("\n=== GESTION DE L'EMPLOI DU TEMPS ===\n");
    printf("1. Ajouter une séance\n");
    printf("2. Consulter mon EDT (Enseignant)\n");
    printf("3. Consulter mon EDT (Classe/Étudiant)\n");
    printf("4. Consulter EDT d'une salle\n");
    printf("5. Consulter EDT d'un département\n");
    printf("6. Consulter EDT par site et jour\n");
    printf("7. Consulter EDT journalier par campus\n");
    printf("8. Sauvegarder EDT\n");
    printf("9. Charger EDT\n");
    printf("10. Quitter\n");
    printf("Choix : ");
}

int main() {
    EmploiDuTemps* edt = initialiserEDT();
    if (edt == NULL) {
        fprintf(stderr, "Erreur d'initialisation de l'emploi du temps\n");
        return EXIT_FAILURE;
    }

    int choix;
    char buffer[100];

    do {
        afficherMenu();
        if (scanf("%d", &choix) != 1) {
            printf("Entrée invalide. Veuillez entrer un nombre.\n");
            while (getchar() != '\n'); // Vider le buffer
            choix = 0;
            continue;
        }
        getchar(); // Consommer le \n restant

        switch (choix) {
            case 1: {
                // Ajouter une séance
                Seance* nouvelleSeance = saisirSeanceUtilisateur();
                if (nouvelleSeance != NULL) {
                    if (ajouterSeance(edt, nouvelleSeance) == 0) {
                        printf("Séance ajoutée avec succès.\n");
                    } else {
                        printf("Erreur lors de l'ajout de la séance.\n");
                    }
                    free(nouvelleSeance); // Libérer la copie temporaire
                } else {
                    printf("Erreur de saisie de la séance.\n");
                }
                break;
            }
            case 2: {
                // Consulter mon EDT (Enseignant)
                printf("Votre nom d'enseignant : ");
                fgets(buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = 0;
                afficherEDTParEnseignant(edt, buffer);
                break;
            }
            case 3: {
                // Consulter mon EDT (Classe/Étudiant)
                printf("Votre classe (ex: L3 Info, M1 Maths) : ");
                fgets(buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = 0;
                afficherEDTParClasse(edt, buffer);
                break;
            }
            case 4: {
                // Consulter EDT d'une salle
                printf("Nom de la salle : ");
                fgets(buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = 0;
                afficherEDTParSalle(edt, buffer);
                break;
            }
            case 5: {
                // Consulter EDT d'un département
                printf("Nom du département : ");
                fgets(buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = 0;
                afficherEDTParDepartement(edt, buffer);
                break;
            }
            case 6: {
                // Consulter EDT par site et jour
                printf("Nom du site : ");
                fgets(buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = 0;
                printf("Jour (0=Lundi, 1=Mardi, ..., 6=Dimanche) : ");
                int jour;
                scanf("%d", &jour);
                getchar();
                afficherEDTParSiteEtJour(edt, buffer, jour);
                break;
            }
            case 7: {
                // Consulter EDT journalier par campus
                printf("Nom du campus (ex: CAMPUS 2 (NDOGBONG)) : ");
                fgets(buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = 0;
                printf("Jour (0=Lundi, 1=Mardi, ..., 6=Dimanche) : ");
                int jour;
                scanf("%d", &jour);
                getchar();
                afficherEDTJournalierParCampus(edt, buffer, jour);
                break;
            }
            case 8: {
                // Sauvegarder EDT
                printf("Nom du fichier pour la sauvegarde : ");
                fgets(buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = 0;
                if (sauvegarderEDT(edt, buffer) == 0) {
                    printf("Sauvegarde réussie.\n");
                } else {
                    printf("Erreur lors de la sauvegarde.\n");
                }
                break;
            }
            case 9: {
                // Charger EDT
                printf("Nom du fichier à charger : ");
                fgets(buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = 0;
                EmploiDuTemps* nouveauEDT = chargerEDT(buffer);
                if (nouveauEDT != NULL) {
                    libererEDT(edt);
                    edt = nouveauEDT;
                    printf("Chargement réussi.\n");
                } else {
                    printf("Erreur lors du chargement.\n");
                }
                break;
            }
            case 10:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choix != 9);

    libererEDT(edt);
    return EXIT_SUCCESS;
}