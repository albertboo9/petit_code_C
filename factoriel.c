#include <stdio.h>

int factoriel(int n){
    int fact, i;
    fact=1;
    for (i=2; i<=n; i++){
        fact=fact*i;
    }
    return fact;

}
int main(){
    int nombre, facto;
    printf("veuillez entrer votre nombre  ");
    scanf("%d", &nombre);
    facto=factoriel(nombre);
    printf("le factoriel de %d est %d", nombre, facto);
}
