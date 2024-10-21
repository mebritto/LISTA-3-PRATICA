#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int tam, int v[tam]){
    int c1, c2;
    int aux;

    for(c2=tam; c2>0; c2--){
    for(c1=0; c1<(tam-1); c1++){
        if(v[c1]>v[c1+1]){
            aux = v[c1+1];
            v[c1+1] = v[c1];
            v[c1] = aux;
            }

        }

    }
}

void printvetor(int tam, int v[tam]){
    int c1;
    for(c1=0; c1<tam; c1++){
        printf("%d", v[c1]);
    }
    printf("\n");
}


int main(){
    int tam = 20;
    int v[20] = { 8 , 7 , 5 , 3 , 2 , 1 , 4 , 9 , 6 , 0 , 18 , 17 , 15 , 13 , 12 , 11 , 14 , 19 , 16 , 10};

    printvetor(tam, v);
    bubbleSort(tam, v);
    printvetor(tam, v);

    return 0;
}

