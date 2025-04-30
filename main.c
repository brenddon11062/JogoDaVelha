#include <stdio.h>

//   | |
//   | |
//   | |

char board[3][3];
char currentPlayer = 'X';

// vamos inicilizar o tabuleiro, criando espaços vazios
void initializeBoard() {
  for (int i = 0; i < 3 ; i ++)
    for (int j = 0; j < 3; j++)
      board[i][j] = ' ';
}

// tabuleiro atual
//   | |
//   | |
//   | |


void printBoardWithOptions() {
  printf("\nTabuleiro:\n");
  for (int i = 0; i<3 ; i ++) {
    for (int j = 0; j<3; j++) {
      int pos = i * 3 + j + 1;
      if (board[i][j] = ' ') 
        printf(" %d ", pos);
      else 
        printf(" %c ", board[i][j]);
      if (j < 2)
        printf("|");
    }
    if (i < 2)
      printf("\n----------\n");
  }
  printf("\n");
}

// tabuleiro atual
//  1 | 2 | 3
//  4 | 5 | 6
//  7 | 8 | 9

// i = i + 1
// i++

// criando funcao que verifica vencedor
int isWinner() {
  for (int i = 0; i < 3; i++) {
    // verificar se jogador ganhou na linha
    if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
      return 1;
      //  X | X | X
      //  4 | 5 | 6
      //  7 | 8 | 9

    // verificar se jogador ganhou na coluna
    if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
      return 1;
      //  1 | 2 | X
      //  4 | 5 | X
      //  7 | 8 | X
  }

  // verificar se jogador ganhou na diagonal
  if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
    return 1;
    //  X | 2 | 3
    //  4 | X | 6
    //  7 | 8 | X

  if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
    return 1;
    //  1 | 2 | X
    //  4 | X | 6
    //  X | 8 | 9

  // se ninguem ganhou
  return 0;
}

// verifica se é possível alguma jogada
int isDraw() {
  for (int i = 0 ; i< 3; i++)
    for (int j =0 ; j< 3; j++)
      if (board[i][j] = ' ')
        return 0;
  return 1;
}

void switchPlayer() {
  if (currentPlayer == 'X') 
    currentPlayer = 'O';
  else if (currentPlayer == 'O')
    currentPlayer = 'X';

  // codigo equivalente
  // currentPlayer = (currentPlayer == 'X' ? 'O' : 'X');
}

void makeMove() {
  int pos;

  while(1) {
    printf("\nJogador %c, escolha uma posição (1-9): ", currentPlayer);
    scanf("%d", &pos);

    //  1 | 2 | 3
    //  4 | 5 | 6
    //  7 | 8 | 9
    
    // board[i][j]
    // board[0][0] => 1

    // verifica se a posição é válida
    if( pos >=1 && pos <=9) {
      int row = (pos - 1) / 3;
      int col = (pos - 1 ) % 3;
      if (board[row][col] == ' ') {
        board[row][col] = currentPlayer;
        break;
      } else {
        printf("Essa posição já está ocupada.\n");
      }
    } else {
      printf("Posição inválida. Tente de novo.\n");
    }
  }
}

int main() {

  initializeBoard();

  // jogo rodando
  while(1) {
    printBoardWithOptions();
    makeMove();
    if (isWinner()){
      printBoardWithOptions();
      printf("Jogador %c venceu!\n", currentPlayer);
      break;
    }
    if (isDraw()){
      printBoardWithOptions();
      printf("Empate!\n");
      break;
    }
    switchPlayer();
  }
  return 0;
}