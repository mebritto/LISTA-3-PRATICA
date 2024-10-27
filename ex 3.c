#include <stdio.h>
#include <stdlib.h>

void gnomesort(int tam, int v[tam]){
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

void printVetor(int tam,int v[tam]){
    int c2;
    for(c2=0;c2<tam;c2++){
        printf("%d ", v[c2]);
    }
printf("\n");

}


int main(){
     int tam= 20;
     int v[20]= {8, 7, 5, 3, 2, 1, 4, 9, 6, 18, 17, 15, 13, 12, 11, 14, 19, 16, 10};

    printVetor(tam,v);

    gnomesort(tam,v);

    printVetor(tam,v);


return 0;
}
