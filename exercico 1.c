#include <stdio.h>
#include <stdlib.h>

void printVetor(int tam, int v[tam]){
    int c1;
    for(c1=0; c1<tam;c1++){
        printf("%d", v[c1]);
    }
    printf("\n");
}

void rotDireita(int tam, int v[tam]){
    int aux;
    int c1;

    aux = v[tam-1];

    for(c1=(tam-1); c1>0; c1--){
        v[c1] = v[c1-1];
    }
    v[0] = aux;
}

    void rotEsquerda(int tam, int v[tam]){
    int aux;
    int c1;

    aux = v[0];

    for(c1 = 0; c1<(tam-1); c1++){
        v[c1] = v[c1 + 1];
    }
    v[tam-1] = aux;
    }

int main(){
    int v[6] = {1, 2, 3, 4, 5, 6};
    int nr = 3;
    int c1;
    for(c1=0; c1< nr; c1++){
        rotEsquerda(6, v);
    }
    printVetor(6, v);
    rotEsquerda(6, v);
    printVetor(6, v);

    return 0;
}
