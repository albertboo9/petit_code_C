#include <stdio.h>
#include <math.h>

/*BO'O ALBERT*/

int main(){
    int a,d, n, p, s,z;
    printf("veuillez entrer votre nombre ");
    scanf("%d", &a);
    printf("votre nombre contient combien de chiffre? ");
    scanf("%d", &n);
    p = pow(10, n-1);
    s=a/p;
    z=a/p;

    while (n !=0){
        p=pow(10, n-1);
        d=a/p;
        if (d>s)
            s=d;
        if (d<z)
            z=d;
        n=n-1;
        a=a%p;

    }
    printf("le plus grand chiffre de ce nombre est %d et le plus petit est %d", s,z);
}
/*BO'O ALBERT*/
