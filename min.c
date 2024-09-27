#include<stdio.h>
void minimum(int n, float *res)
{
    int i;
    float min, a;
    if(n>0){
        scanf("%f",&a);
        min=a;
        for(i=1;i<=n-1;i++){
            scanf("%f",&a);
            if(min>a)
               min=a;
            *res;
        }
    }
}
int main()
{

    int i, n;
    float *res;
    printf("entrer un entier");
    scanf("%d", &n);
    minimum(n, res);
    printf("le min = %f", *res);
    return 0;
}
