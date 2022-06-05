#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Change the color
#define couleur(param) printf("\033[%sm",param)
//Clear the screen
#define clrscr() printf("\033[H\033[2J")
//Error message
#define error(cause) couleur("41");printf("\nErreur %s, veuillez recommencer\n",cause);couleur("0")

#define max_score 999999999

#define nickname_size 25

// Every values a tile can have
typedef enum { 
  // It iterates from -1 for the bomb, to 8
  BOMB = -1,   
  ZERO,        
  ONE,
  TWO,
  THREE,
  FOUR,
  FIVE,
  SIX,
  SEVEN,
  EIGHT 
} Value;

// Every states a tile can have
typedef enum { 
  FLAGGED = -1,
  HIDDEN, 
  SHOWN   
} State;

// Each tile has a value, a state and a position on the grid (row,column)
typedef struct {    
  Value value;
  State state;
  int row;
  int column;
} Case;

// Each score registered has the nickname of the player, his score, and the game mode he was playing
typedef struct{
  int mode;
  int score;
  char nickname[nickname_size];
} Score;

Case **gridBuilder(int row_amount, int column_amount, int bomb_amount);
void showTab(Case **caseTab, int row_amount, int column_amount, int *bomb_remain, Score high_score);
void bombPlacer(Case **caseTab, int row_amount, int column_amount);
void numberGiver(Case **caseTab, int row_amount, int column_amount);
void tileDiscovery(Case **caseTab, int row_amount, int column_amount, int tile_row, int tile_column);
int gameTurn(Case **caseTab, int row_amount, int column_amount, int *bomb_remain, Score high_score);
int gridChecker(Case **caseTab, int row_amount, int column_amount);
void playerGuess(Case **caseTab, int row_amount, int column_amount, int *guess_row, char *guess_column,int *bomb_remain, Score high_score);
void clear();
void gameMode(int *row_amount, int *column_amount, int *bomb_amount, Score* high_score);
void titlePrint();
void getHighScore(Score* high_score);
void newHighScore(Score new_high_score);
