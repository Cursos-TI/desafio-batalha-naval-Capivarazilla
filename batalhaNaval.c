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
        int newLine = line + (direction == 1 ? i : 0) + (direction == 2 ? i : 0); // Verificação das direções horizontais e diagonais
        int newColumn = column + (direction == 0 ? i : 0) + (direction == 2 ? i : 0);  // Verificação das direções verticais e diagonais
        
        // Verifica se a posição é válida e se não há sobreposição de navios
        if (newLine >= SIZE_LINE || newColumn >= SIZE_COLUMN || board[newLine][newColumn] == '3') {
            return 0; // Se inválido, retorna 0
        }
    }
    return 1; // Se espaço válido, retorna 1
}
// Função para criar os navios no tabuleiro
void setShip(char board[SIZE_LINE][SIZE_COLUMN], int direction){
    int line, column;

    do {
        line = rand() % SIZE_LINE;
        column = rand() % SIZE_COLUMN;
        //direction = rand() % 2;
    } while (!verifySpace(board, line, column, direction));

    for (int i = 0; i < SIZE_SHIP; i++){
        int newLine = line + (direction == 1 ? i : 0) + (direction == 2 ? i : 0);
        int newColumn = column + (direction == 0 ? i : 0) + (direction == 2 ? i : 0);
        board[newLine][newColumn] = '3'; //Marca no navio na posição correta
    }
}



int main(){
    srand(time(NULL)); //Iniciando randomizador baseado do no tempo atual

    char board[SIZE_LINE][SIZE_COLUMN];
    int horizontalCount = 0, verticalCount = 0;


    startBoard(board);

    //Força dois navios a serem diagonais
    for (int i = 0; i < 2; i++){
        setShip(board, 2);
    }
    
    //Escolhe aleatóriamente se os navios serão verticais ou horizontais
    for (int i = 0; i < 2; i++){
        int direction = rand() % 2; //Determina um valor entre 0(horizontal) ou 1(vertical)

        if (direction == 0 && horizontalCount < 2){
            setShip(board, direction);
            horizontalCount++;
        } 
        else if (direction == 1 && verticalCount < 2) {
            setShip(board, direction);
            verticalCount++;
        }
        else if (horizontalCount < 2){
            setShip(board, 0);
            horizontalCount++;
        }
        else if (verticalCount < 2){
            setShip(board, 1);
            verticalCount++;
        }
    }
    

    printBoard(board);


    return 0;
}