#include <stdio.h>
#include <math.h>

int main(){
    int a, d, s=0, n,p,b;
    printf("entrer votre nombre ");
    scanf("%d", &a);
    b=a;
    printf("votre nombre contient combien de chiffre ");
    scanf("%d", &n);
    while (n!=0){
        p = pow(10, n-1);
        d=b/p;
        s=s+d;
        n=n-1;
        b=b%p;
    }

    printf("%d", s);



}
