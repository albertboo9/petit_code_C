#include<stdio.h>
#include<math.h>
int main(){
    int salaire, absence, anciennete;
    float prime;

    printf("entrer votre salaire ");
    scanf("%d", &salaire);
    printf("pendant combien de jours avez-vous ete absent? ");
    scanf("%d", &absence);
    printf("depuis combien d'annee etes vous employe ici? ");
    scanf("%d", &anciennete);
    prime=salaire/2+0.02*salaire*anciennete-0.01*salaire*(absence/20);
    printf("votre prime est de %f", prime);

}
