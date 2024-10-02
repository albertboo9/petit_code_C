#include<stdio.h>
#include<math.h>

void echanger(int T[], int a , int b){
    int tmp = T[a];
    T[a] = T[b];
    T[b] = tmp;

}

void k_petit(int T[], int n, int k){
    int i,j, min;
    for ( i = 0; i < k ; i++)
    {
       
        for ( j = 0; j < n; i++)
        {
           if (T[j] < T[i]){
                echanger(T, j, i);
           }
        }
        printf("%d", T[i]);
        
    }
    

}

int main(){

    int T[] = (10, 9, 8, 7, 6, 5, 4, 3, 2, 1);

    k_petit(T, 10, 5);



}