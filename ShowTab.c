#include "header.h"


// This function prints the entire grid
void showTab(Case **caseTab, int row_amount, int column_amount, int *bomb_remain, Score high_score) { 
  clrscr();
  //"n" will be used to put the letters before the grid
  int n = 1;
  //if the high_score isn't the default one
  if(high_score.score!=max_score){
    //print it before the grid
    printf("\nHigh Score: %ds by %s\n",high_score.score,high_score.nickname);
  }
  printf("\n    ");
  // Put the letters before the grid
  for (char c = 'A'; c < 'A' + column_amount; c++) {
    printf("%c ", c);
  }
  printf("\n");
  // Browse every row of the grid 
  for (int row = 0; row < row_amount; row++) { 
    // Put the number before the grid 
    if(n<10){ 
      printf(" %d ", n++);
    }
    else{
      printf("%d ",n++);
    }
    // Browses every tile of a row
    for (int column = 0; column <column_amount; column++) {  
      // If a tile is stated as "discovered"
      if ((*(caseTab + row) + column)->state == 1) { 
        // Show an "X" if the tile has a bomb
        if ((*(caseTab + row) + column)->value == -1) {
          printf("|");
          couleur("31");
          printf("X");
          couleur("0");
        } 
        // Show a "~" if there's no bomb around the tile
        else if ((*(caseTab + row) + column)->value == 0) {
          printf("|");
          couleur("32");
          printf("~");
          couleur("0"); 
        } 
        // Show the amount of bomb near the tile
        else {
          char color[2]; color[0]='3';
          color[1]='7'+1-(*(caseTab + row) + column)->value;
          printf("|");
          couleur(color);
          printf("%d", (*(caseTab + row) + column)->value); 
          couleur("0");
        }
      } 
      // If a tile is stated as "undiscovered"
      else if ((*(caseTab + row) + column)->state == 0) {  
        // Show a blank space
        printf("| ");                   
      }
      // If a tile is stated as "flagged"
      else if ((*(caseTab + row) + column)->state == -1) { 
        // Show a "@"
        printf("|");
        couleur("36");
        printf("@");
        couleur("0");
      }
    }
    //End of a row
    printf("|\n");
  }
  //End of the grid
  printf("\n");
  printf("Il vous reste %d bombes à trouver.\n\n", *bomb_remain);
}
