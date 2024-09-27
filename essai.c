#include <stdio.h>

struct article {
    char  Nom[100]; /*nom de l'article*/
    int Nb; /*Nombre d'article*/
    float prix; /*Prix unitaire de l'article*/
    int Nbmin; /*Nombre d'articles minimum à avoir en stock*/
};

int main(){
    int n=0, i, v, s;
    struct article tab[n];

    printf("entrer le nombre d'article a stocker ");
    scanf("%d", &n);

    for(i=0; i<n; i++){
        printf("entrer le nom de  l'article N°%d: ", i+1);
        scanf("%s", &tab[i].Nom);
        printf("entrer son nombre en stock ");
        scanf("%d", &tab[i].Nb);
        printf("entrer son prix unitaire ");
        scanf("%f", &tab[i].prix);
        printf("entrer le nombre minimal d'article a avoir en stock ");
        scanf("%d", &tab[i].Nbmin);

    }
    printf("/////////////affichage des articles en stock/////////////\n");
    for(v=0; v<n; v++){
        printf("l'article N°%d se nomme %s \n", v+1, tab[v].Nom);
        printf("son nombre en stock est %d \n", tab[v].Nb);
        printf("son prix unitaire est %f\n", tab[v].prix);
        printf("son nombre minimum a avoir en stock est %d \n",tab[v].Nbmin);
    }
    printf("////////affichage des articles à reaprovisionner/////////\n");
    for(s=0; s<n; s++){
        if(tab[s].Nb<tab[s].Nbmin){
            printf("l'article %s doit etre reaprovisionne \n", tab[s].Nom);
        }
    }

}
