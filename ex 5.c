#include <stdio.h>
#include <stdlib.h>

void combinarVetores(int v1[], int v2[], int vFinal[], int tam) {
    // Copia os elementos do primeiro vetor para o novo vetor
    for (int i = 0; i < tam; i++) {
        vFinal[i] = v1[i];
    }
    // Copia os elementos do segundo vetor para o novo vetor, a partir da posição `tam`
    for (int i = 0; i < tam; i++) {
        vFinal[i + tam] = v2[i];
    }
}

void gnomesort(int tam, int v[]){
   int pos = 0;

    while (pos< tam){
        if (pos == 0 || v[pos] >= v[pos - 1]) {
            pos++;
        }
        else{
            int aux = v[pos];
            v[pos]= v[pos-1];
            v[pos-1]= aux;
            pos--;
        }
    }
}


void printVetor(const char *nome, int tam,int v[]){
    int c2;
    printf(" %s = ", nome);
    for(c2=0;c2<tam;c2++){
        printf(" %d ", v[c2]);
    }
printf("\n");

}


int main(){

     int v1[10]={8, 7, 5, 3, 2, 1, 4, 9, 6, 18};
     int v2[10]={17, 15, 13, 12, 11, 14, 19, 16, 10};
     int vFinal[20];

    printVetor("v1",10,v1);
    printVetor("v2",10,v2);

    combinarVetores(v1, v2, vFinal, 10);

    printVetor("Vetor Combinado", 20, vFinal);

    gnomesort(20,vFinal);

    printVetor("Vetor Final", 20, vFinal);


return 0;
}


