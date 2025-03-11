#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SIZE_LINE 10
#define SIZE_COLUMN 10
#define SIZE_SHIP 3

//Função para iniciar o tabuleiro vazio, '0'
void startBoard(char board[SIZE_LINE][SIZE_COLUMN]){
    for (int i = 0; i < SIZE_LINE; i++){
        for (int j = 0; j < SIZE_COLUMN; j++){
            board[i][j] = '0';
        }
    }
}

//Função para exibição do tabuleiro com enumeração de linhas e colunas
void printBoard(char matrix[SIZE_LINE][SIZE_COLUMN]){
    printf("   A B C D E F G H I J\n"); // Nomeação das colunas
    for (int i = 0; i < SIZE_LINE; i++)    {
        printf("%2d ", i+1); //Enumeração das linhas
        for (int j = 0; j < SIZE_COLUMN; j++){
            printf("%c ", matrix[i][j] == '3' ? '3' : '0');
        }
        printf("\n");
    }
}

//Função para verificar os espaços do tabuleiro (se direction == 0, horizontal, se direction == 1, vertical)
int verifySpace(char board[SIZE_LINE][SIZE_COLUMN], int line, int column, int direction){
    for (int i = 0; i < SIZE_SHIP; i++){
        int newLine = line + (direction == 0 ? 0 : i);
        int newColumn = column + (direction == 1 ? 0 : i);

        if (newLine >= SIZE_LINE || newColumn >= SIZE_COLUMN || board[newLine][newColumn] == '3'){ //Condicional para evitar navios sendo colocados fora do tabuleiro ou se interpondo
           return 0; //Retorna 0 caso haja sobreposição ou falte espaço no tabuleiro
        }
    }
    return 1; //Retorna 1 caso o espaço seja válido
}

// Função para criar os navios no tabuleiro
void setShip(char board[SIZE_LINE][SIZE_COLUMN]){
    int line, column, direction;

    do {
        line = rand() % SIZE_LINE;
        column = rand() % SIZE_COLUMN;
        direction = rand() % 2;
    } while (!verifySpace(board, line, column, direction));

    for (int i = 0; i < SIZE_SHIP; i++){
        int newLine = line + (direction == 0 ? 0 : i);
        int newColumn = column + (direction == 1 ? 0 : i);
        board[newLine][newColumn] = '3'; //Marca no navio na posição correta
    }
}



int main(){
    srand(time(NULL)); //Iniciando randomizador baseado do no tempo atual

    char board[SIZE_LINE][SIZE_COLUMN];


    startBoard(board);

    for (int i = 0; i < 2; i++){
        setShip(board);
    }
    

    printBoard(board);


    return 0;
}