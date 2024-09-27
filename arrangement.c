#include<stdio.h>

int factoriel(int n){
    int fact=1, i;
    for(i=2; i<=n; i++){
            fact=fact*i;
    }
    return fact;
}

int arrangement(int nbre, int p){
    int facp, facnbre, arran;

    facp=factoriel(p);
    facnbre=factoriel(nbre);

    arran=facnbre/facp;

    return arran;


}
int combinaison(int nbre, int p){
    int facsous, arra, com;

    facsous=factoriel(nbre-p);
    arra = arrangement(nbre, p);
    com=arra/facsous;
    return com;
}

int main(){
    int nombre, arrange, pi, combi;
    printf("veuillez entrer n et p ");
    scanf("%d %d", &nombre, &pi);
    while (pi>nombre){
        printf("entrer des valeurs valides de n et p (n > p) ");
        scanf("%d %d ", &nombre , &pi);
    }

    arrange=arrangement(nombre, pi);
    combi=combinaison(nombre, pi);
    printf(" L'arrangement de %d dans %d est %d \n",nombre,pi, arrange);
    printf("La combinaison de %d dans %d est %d",nombre,pi, combi);


}
