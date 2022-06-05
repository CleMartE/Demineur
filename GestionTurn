#include "header.h"


/* This function manages a player's turn,
returns 1 if it's a win, -1 if it's a lose, and 0 if it's neither */
int gameTurn(Case **caseTab, int row_amount, int column_amount, int *bomb_remain, Score high_score) { 
  char column, choice;
  int row, leave;
  // Ask the user what action he wants to take
  showTab(caseTab, row_amount, column_amount, bomb_remain, high_score);
  printf("Que voulez-vous faire? :\n1. Découvrir une case\n2. Placer un marqueur de bombe\n3. Revenir au menu\n");
  scanf("%c", &choice);
  clear();
  
  while (choice != '1' && choice != '2' && choice != '3'){
    showTab(caseTab, row_amount, column_amount, bomb_remain, high_score);
    printf("Que voulez-vous faire? :\n1. Découvrir une case\n2. Placer un marqueur de bombe\n3. Revenir au menu\n");
    error("de saisie");
    scanf("%c", &choice);
    clear();
  }
  switch (choice) {
  // If the user wants to discover a tile (choice = 1)
  case '1': 
    // Ask the user where he wants to take action
    playerGuess(caseTab, row_amount, column_amount, &row, &column, bomb_remain, high_score); 
    // Discover the tile
    tileDiscovery(caseTab, row_amount, column_amount, row - 1, (int)column - 'A');
    // If the tile has a bomb in it
    if ((*(caseTab + row - 1) + (int)column - 'A')->value == -1 && (*(caseTab + row - 1) + (int)column - 'A')->state != -1) {
      showTab(caseTab, row_amount, column_amount, bomb_remain, high_score);
      // Send lose signal
      return -1; 
    }
    break;
  // If the user wants to put a flag (choice = 2)
  case '2': 
    // Ask the user where he wants to take action
    playerGuess(caseTab, row_amount, column_amount, &row, &column, bomb_remain, high_score); 
    // If there is no flag on the tile and the user have flags to pose
    if ((*(caseTab + row - 1) + (int)column - 'A')->state == 0 && *bomb_remain>0) {
      // Put a flag on a tile
      (*(caseTab + row - 1) + (int)column - 'A')->state = -1; 
      // Remove a bomb from the counter
      (*bomb_remain)--; 
    // If there is a flag on the tile
    } else if ((*(caseTab + row - 1) + (int)column - 'A')->state == -1) { 
      // Remove the flag
      (*(caseTab + row - 1) + (int)column - 'A')->state = 0;
      // Add a bomb to the counter
      (*bomb_remain)++; 
    }
    break;
  // If the user wants to go back to the menu
  case '3':
    clrscr();
    // Ask if he is sure he wants to do so
    printf("Etes-vous sûr de vouloir quitter ?\n1. Oui\n2. Non\n");
    scanf("%d",&leave);
     clear();
     while(leave != 1 && leave != 2){
      clrscr();
      printf("Etes-vous sûr de vouloir quitter ?\n1. Oui\n2. Non\n");
      error("de saisie");
      scanf("%d",&leave);
      clear();
    }
    // If the user is really willing to leave the current game
    if(leave==1){
      clrscr();
      // Leave the programm without winning or losing
      return 2;
    }
    else{
      return gameTurn(caseTab, row_amount, column_amount, bomb_remain, high_score); 
    }
    break;
  }
  // If every bomb has a flag, and every tile is discovered
  if (gridChecker(caseTab, row_amount, column_amount) == 1) { 
    showTab(caseTab, row_amount, column_amount, bomb_remain, high_score);
    // Send win signal
    return 1; 
  }

  showTab(caseTab, row_amount, column_amount, bomb_remain, high_score);
  // Send continue signal
  return 0; 
}





// This function checks if all the bombs are "flagged"  and others are "shown", if so, it returns 1
int gridChecker(Case **caseTab, int row_amount, int column_amount) {
  // Browse every row of the grid
  for (int row = 0; row < row_amount; row++) { 
    // Browses every tile of the row
    for (int column = 0; column < column_amount; column++) { 
      // If a tile is "hidden", the game still goes
      if ((*(caseTab + row) + column)->state == 0) { 
        return 0;
      }
      // If a bomb isn't "flagged", the game keeps going
      if ((*(caseTab + row) + column)->value == -1 && (*(caseTab + row) + column)->state != -1) { 
        return 0;
      }
      // If a tile without bomb is "flagged", the game keeps going
      if ((*(caseTab + row) + column)->value != -1 && (*(caseTab + row) + column)->state == -1) { 
        return 0;
      }
    }
  }
  // If every bomb of the grid is "flagged", and every other tiles are "shown", game's over, and it's a win
  return 1; 
}




// This functions asks the player for a position (row,column)
void playerGuess(Case **caseTab, int row_amount, int column_amount, int *guess_row, char *guess_column, int *bomb_remain, Score high_score) {     
  char column;
  int row;
  // Ask the user for a position
  showTab(caseTab, row_amount, column_amount, bomb_remain, high_score);
  printf("Veuillez saisir une coordonnée (ex:C6) : ");
  scanf("%c%d", &column, &row);
  clear();
  //The letter can be both in upper or lowercase, it will work
  while ((row < 1 || row > row_amount) ||((column < 'a' || column >= 'a' + column_amount)
    && (column < 'A' ||column >= 'A' + column_amount))){
    showTab(caseTab, row_amount, column_amount, bomb_remain,high_score);
    printf("Veuillez saisir une coordonnée (ex:C6) : ");
    error("de saisie");
    scanf("%c%d", &column, &row);
    clear();
    
  } 
  // Puts "column" in uppercase if it is in lowercase
  if (column >= 'a' && column <= 'z') { 
    column -= ('a' - 'A');
  }
  // Returns the row and the column to the programm
  *guess_row = row;       
  *guess_column = column; 
}


// Used to clear the buffer
void clear() {
  char c;
  while (c != '\n') {
    c = getchar();
  }
}





// This function reveals a tile at the position (tile_row,tile_column)
void tileDiscovery(Case **caseTab, int row_amount, int column_amount, int tile_row, int tile_column) { 
  // If the targeted tile is inside the grid and is hidden
  if (tile_row != -1 && tile_row < row_amount && tile_column != -1 && tile_column < column_amount 
    && (*(caseTab + tile_row) + tile_column)->state == 0) { 
    // Discover the targeted tile        
    (*(caseTab + tile_row) + tile_column)->state = 1; 
    // If there is no bomb next to the tile (if the tile's value is 0)
    if ((*(caseTab + tile_row) + tile_column)->value == 0) { 
      // Browse the row before the tile, the tile's row, and the row after the tile
      for (int r = -1; r <= 1; r++) { 
        // Browse the column before the tile, the tile's column, and the column after the tile
        for (int c = -1; c <= 1; c++) { 
          // If the tile is inside the grid and is a "hidden" tile
          if (tile_row + r != -1 && tile_row + r < row_amount 
            && tile_column + c != -1 && tile_column + c < column_amount 
            && (*(caseTab + tile_row + r) + tile_column + c)->state == 0) { 
              // Discover this tile => recursivity
              tileDiscovery(caseTab, row_amount, column_amount, tile_row + r, tile_column + c); 
          }
        }
      }
    }
  }
}
