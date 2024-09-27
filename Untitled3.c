#include<stdio.h>

int main(){

    int n, i, a=0;


    printf("entrer votre nombre ");
    scanf("%d", &n);

    for (i=1; i<=n; i++){
        if(n%i==0){
            a=a+1;
        }
    }
    if (a==2)
        printf("votre nombre est premier");
    else
        printf("votre nombre n'est pas premier");



}
