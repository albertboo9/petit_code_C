#include<stdio.h>
#include<math.h>

void car_par(int n){
     int a=0 , *pointa= &a, v, *pointv= &v,  i;
     for(i=2; i<=n/2; i++){
        if(i*i==n){
            a=1;
        }
     }
    v=sqrt(n);

}
int main(){
    int n, m, b;

    printf("entrer un entier");
    scanf("%d", &n);
    car_par(n);

}
