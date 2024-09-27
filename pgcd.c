#include <stdio.h>

int pgcd(int a, int b){
    int n1, p, x, i;
    p=1;
    if (a>b){
        x=a;
        a=b;
        b=x;
    }
    n1=a/2;
    if (b%a==0){
        p=a;
    }
    else{
    for(i=2; i<=n1; i++){
        if(a%i==0 && b%i==0 && i>p){
            p=i;
        }
    }
    }
    return p;

}
int ppcm(int a, int b){
    int p;
    p = (a*b)/pgcd(a,b);

}

int main(){
    int a,b, pg, pp;
    printf("entrer deux nombres ");
    scanf("%d %d", &a, &b);
    pg=pgcd(a,b);
    pp=ppcm(a,b);

    printf("le PGCD de %d et %d est %d et leur PPCM est %d",a,b,pg,pp);
}
