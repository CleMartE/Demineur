#include "header.h"

// This function builds the whole grid
Case **gridBuilder(int row_amount, int column_amount, int bomb_amount) { 
  Case **caseTab;
  // Creates every row
  caseTab = calloc(row_amount, sizeof(Case *)); 
  if (caseTab == NULL) {
    error("d'allocution");
    exit(1);
  }
  // Creates every tiles for each row (repeats "row_amount" times)
  for (int row = 0; row <  row_amount; row++) { 
    *(caseTab + row) = calloc(column_amount, sizeof(Case));
    if (*(caseTab + row) == NULL) {
      error("d'allocution");
      exit(1);
    }
    // Gives each tile his position on the grid (row,column)
    for (int column = 0; column < column_amount; column++) { 
      (*(caseTab + row) + column)->column = column;
      (*(caseTab + row) + column)->row = row;
    }
    
  }
  // Place "bomb_amount" bombs on the grid
  for (int i = 0; i < bomb_amount; i++) { 
    bombPlacer(caseTab, row_amount, column_amount);
  }
  // Gives each tile his value
  numberGiver(caseTab, row_amount, column_amount); 
  // The grid is done, and each tile has his position, his  value, and is "HIDDEN" by default
  return caseTab; 
}




// This function places randomly 1 bomb on the grid, at a place where there is none
void bombPlacer(Case **caseTab, int row_amount, int column_amount) { 
  // 0 = not placed, 1 = placed
  int placed = 0, row, column;      
  do {
    // Get both a random row...
    row = rand() % row_amount; 
    //...and a random column between 0 and the max amount
    column = rand() % column_amount; 
    // If the tile doesn't contain a bomb
    if ((*(caseTab + row) + column)->value != -1) { 
       // Place a bomb in it
      (*(caseTab + row) + column)->value = -1;
      // Bomb has been planted
      placed = 1;                              
    }
  // Do all that while the bomb isn't placed
  } while (placed == 0); 
}




// This function gives each tile his value
void numberGiver(Case **caseTab, int row_amount, int column_amount) { 
  // Browse every row of the grid
  for (int row = 0; row < row_amount; row++) { 
    // Browse every tile of the row
    for (int column = 0; column < column_amount; column++) { 
      // If a tile at a certain row and column contains a bomb
      if ((*(caseTab + row) + column)->value == -1) { 
        // Browse the row before the tile, the  tile's row, and the row after the tile
        for (int r = -1; r <= 1; r++) { 
          // Browse the column before the tile, the tile's column, and the column after the tile
          for (int c = -1; c <= 1; c++) { 
            //If the current tile is inside the grid and does not contain a bomb
            if (row + r != -1 && row + r < row_amount && column + c != -1 && column + c < column_amount 
              && (*(caseTab + row + r) + column + c)->value != -1) {
              // Increases his value by 1
              (*(caseTab + row + r) + column + c)->value++; 
            }
          }
        }
      }
    }
  }
}



