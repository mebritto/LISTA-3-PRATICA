#include <stdio.h>
#include <stdlib.h>

void selectionSort(int v[], int n) {
    int i, c1, minimo, temp;

    for (i = 0; i < n - 1; i++) {

        minimo = i;


        for (c1 = i + 1; c1 < n; c1++) {
            if (v[c1] < v[minimo]) {
                minimo = c1;
            }
        }

        if (minimo != i) {
            temp = v[i];
            v[i] = v[minimo];
            v[minimo] = temp;
        }
    }
}

int main() {
    int v[20] = {19, 5, 10, 12, 1, 9, 4, 6, 7, 2,
                 8, 18, 17, 3, 11, 13, 16, 14, 20, 15};
    int n = 20;

    printf("Vetor antes da ordenação: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    selectionSort(v, n);

    printf("Vetor depois da ordenação: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}

