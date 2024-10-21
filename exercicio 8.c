#include <stdio.h>

#define SIZE 3

void printBoard(char board[SIZE][SIZE]){
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            printf("%c", board [i][j]);
        }
        printf("\n");
    }
}

char checkGanhador(char board[SIZE][SIZE]){
    for (int i = 0; i < SIZE; i++){
        if (board[i][0] == board [i][1] && board [i][1] == board [i][2] && board [i][0] != ' '){
        return board [i][0];}

        if (board[0][i] == board [1][i] && board [1][i]== board [2][i] && board [0][i] != ' '){
        return board [0][i];}
    }
    if (board[0][0] == board [1][1] && board [1][1]== board [2][2] && board [0][0] != ' '){
        return board [0][0];}

        if (board[0][2] == board [1][1] && board [1][1]== board [2][0] && board [0][2] != ' '){
        return board [0][2];}

        return ' ';
}

int main(){
    char board [SIZE][SIZE] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    char Jogador = 'X';
    int linha, coluna;
    int movimento = 0;

    while(1){
        printBoard(board);
        printf("jogador %c, digite a linha (0-2) e a coluna (0-2): ", Jogador);
        scanf ("%d %d", &linha, &coluna);

        if (linha < 0 || linha >= SIZE || coluna < 0 ||coluna >= SIZE || board[linha][coluna] != ' '){
            printf("tentativa falha, tente novamente.\n");
            continue;
        }

        board[linha][coluna] = Jogador;
        movimento++;

        char vencedor = checkGanhador(board);
        if(vencedor != ' '){
            printBoard(board);
            printf("jogador %c venceu\n", vencedor);
            break;
        }
        if(movimento == SIZE * SIZE){
            printBoard(board);
            printf("empate\n");
            break;
        }
       Jogador = (Jogador == 'X')? 'O' : 'X';
    }
return 0;
}
