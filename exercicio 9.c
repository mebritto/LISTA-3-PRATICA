#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

void initBoardWithZeros(int W, int H, int board[H][W]) {
    int c1, c2;
    for (c1 = 0; c1 < H; c1++) {
        for (c2 = 0; c2 < W; c2++) {
            board[c1][c2] = 0;
        }
    }
}

int countLiveNeighbors(int W, int H, int board[H][W], int lin, int col) {
    if ((H == 0) || (W == 0)) {
        return 0;
    }
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;
            int newRow = lin + i;
            int newCol = col + j;
            if (newRow >= 0 && newRow < H && newCol >= 0 && newCol < W) {
                count += board[newRow][newCol];
            }
        }
    }
    return count;
}

void updateBoard(int W, int H, int board[H][W]) {
    int newBoard[H][W];
    for (int c1 = 0; c1 < H; c1++) {
        for (int c2 = 0; c2 < W; c2++) {
            int neighbors = countLiveNeighbors(W, H, board, c1, c2);
            if (board[c1][c2] == 1) {
                if (neighbors < 2 || neighbors > 3) {
                    newBoard[c1][c2] = 0;
                } else {
                    newBoard[c1][c2] = 1;
                }
            } else {
                if (neighbors == 3) {
                    newBoard[c1][c2] = 1;
                } else {
                    newBoard[c1][c2] = 0;
                }
            }
        }
    }
    for (int c1 = 0; c1 < H; c1++) {
        for (int c2 = 0; c2 < W; c2++) {
            board[c1][c2] = newBoard[c1][c2];
        }
    }
}

void printBoard(int W, int H, int board[H][W]) {
    for (int c1 = 0; c1 < H; c1++) {
        for (int c2 = 0; c2 < W; c2++) {
            if (board[c1][c2] == 1) {
                printf("o ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int hasLiveCells(int W, int H, int board[H][W]) {
    for (int c1 = 0; c1 < H; c1++) {
        for (int c2 = 0; c2 < W; c2++) {
            if (board[c1][c2] == 1) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    srand(time(NULL));
    int W = 10;
    int H = 10;
    int board[H][W];
    initBoardWithZeros(W, H, board);
    for (int c1 = 0; c1 < H; c1++) {
        for (int c2 = 0; c2 < W; c2++) {
            board[c1][c2] = rand() % 2;
        }
    }
    printf("Tabuleiro inicial:\n");
    printBoard(W, H, board);
    printf("Pressione qualquer tecla para continuar ou 'q' para sair...\n");

    while (1) {
        updateBoard(W, H, board);
        printBoard(W, H, board);
        if (!hasLiveCells(W, H, board)) {
            printf("Não há mais células vivas. O jogo terminou.\n");
            break;
        }
        if (_kbhit()) {
            char c = _getch();
            if (c == 'q' || c == 'Q') {
                break;
            }
        }
        sleep(1);
    }
    return 0;
}
