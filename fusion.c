// B.A.E
// programme C qui fusionne deux tableaux triés et renvoie un tableau trié
#include <stdio.h>

void echanger(int T[], int a, int b) {
    int tmp = T[a];
    T[a] = T[b];
    T[b] = tmp;
}

void insertion(int* T, int n, int x){ // cette procédure insère un nombre x dans un tableau trié de taille n
T[n] = x;
int i=n-1;
while (T[i] > T[i+1] && i>0)
{
    echanger(T, i, i+1);
    i--;
}

}

int* fusion(int* T, int* L, int n){
    int j = n;
    for (int i = 0; i < n; i++)
    {
        insertion(T, j, L[i]);
        j = j+1;
    }
    return T;
}

int main(){

    int n = 5;
    int *T  = (int*)malloc(2*n*sizeof(int));
    int *L  = (int*)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++) {
    T[i] = i + 1; // Initialisation avec les valeurs 1, 2, 3, 4, 5

}
       for (int i = 0; i < n; i++) {
    L[i] = 10 - i; // Initialisation avec les valeurs 1, 2, 3, 4, 5
    
}
    


    int* R = fusion(T, L, n);

    for (int  i = 0; i < 2*n; i++)
    {
        printf("%d : ", R[i]);
    }

    return 0;
}