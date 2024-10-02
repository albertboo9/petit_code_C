#include <stdio.h>

void echanger(int T[], int a, int b) {
    int tmp = T[a];
    T[a] = T[b];
    T[b] = tmp;
}

void k_petit(int T[], int n, int k) {
    int i, j, min;
    for (i = 0; i < k; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (T[j] < T[min]) {
                min = j;
            }
        }
        echanger(T, i, min);
    }

    // Print the k smallest elements after sorting
    for (i = 0; i < k; i++) {
        printf("%d ", T[i]);
    }
}

int main() {
    int T[10] = {10,9, 8, 7, 6, 5, 4, 3, 2, 1};

    k_petit(T, 10, 5);

    return 0;
}