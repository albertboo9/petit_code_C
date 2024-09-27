#include <stdio.h>


void entier(n){
    int i=1, max, min, s,v,m;
    max=0;
    min=10000;
     while(i<n+1){

        printf("entrer le nombre d'indice %d ", i);
        scanf("%d", &m);
        if (m<min){
            min=m;
            s=i;
        }
        if (m>max){
            max=m;
            v=i;
        }
        i++;
     }


    printf("le maximum de cette liste est %d il occupe la position numero %d\n", max, v);
    printf("le minimum de cette liste est %d il occupe la position numero %d \n", min, s);



}
int main(){
    int n;
    printf("entrer votre entier");
    scanf("%d", &n);
    entier(n);
}
