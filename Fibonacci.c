#include <stdio.h>

int fibonacci(int n){

    int a0, a1, u, i;

    if (n==0 || n==1)
        u=1;
    else{
        a0=1;
        a1=1;
        for(i=2; i<=n; i++){
            u=a0+a1;
            a0=a1;
            a1=u;

        }
    return u;
}
}
int main(){
    int nombre, fibo;

    printf("entrer votre entier");
    scanf("%d", &nombre);

    fibo = fibonacci(nombre);

    print("après %d mois on a %d couples de lapin", nombre, fibo);

}
