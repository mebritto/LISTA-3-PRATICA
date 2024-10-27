#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void mediana (int tam, int v[tam]){
    int c1;
    int c2;
    for(c1 = 0; c1<tam-1; c1++){
        for(c2= c1+1; c2<tam; c2++){
            if(v[c1] > v[c2]){
                int temp = v[c1];
                v[c1]= v[c2];
                v[c2]= temp;
            }
        }
    }


}
double mediana2 (int tam, int v[tam]){
    mediana (tam,v);
     if (tam % 2 == 1) {
        return v[tam / 2];
    }
    else {

        return (v[tam / 2 - 1] + v[tam / 2]) / 2.0;
    }
}


int main(){

int tam = 20;
int v[20]= {8, 7, 5, 3, 2, 1, 4, 9, 6, 18, 17, 15, 13, 12, 11, 14, 19, 16, 10};

 double resultado = mediana2(tam, v);
    printf("A mediana eh: %.2f\n", resultado);

return 0;
}
