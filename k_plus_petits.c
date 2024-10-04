// B.A.E
#include <stdio.h>

void echanger(int *T, int a, int b) {
    int tmp = T[a];
    T[a] = T[b];
    T[b] = tmp;
}

void k_petit(int T[], int n, int k) {
    int i, j, min;
    // tri du tableau jusqu'à trouvé les k plus petits
    for (i = 0; i < k; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (T[j] < T[min]) {
                min = j;
            }
        }
        echanger(T, i, min);
        printf("%d ", T[i]); // affichage du plus petit élément trouver en T[i] et la fin du tableau
    }
}

int main() {
    // test
    int T[10] = {10,9, 8, 7, 6, 55, 4, 33, 2, 11};

    k_petit(T, 10, 10);

    return 0;
}