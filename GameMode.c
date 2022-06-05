#include "header.h"

// This procedure prints the title
void titlePrint(){
  couleur("33");
  printf(" _____      ______    ___    ___    _______    ___     _    ______    _     _    _____\n|  __ \\    |  ____|  |   \\  /   |  |__   __|  |   \\   | |  |  ____|  | |   | |  |  __ \\ \n| |  \\ \\   | |__     | |\\ \\/ /| |     | |     | |\\ \\  | |  | |__     | |   | |  | |__| | \n| |   | |  |  __|    | | \\__/ | |     | |     | | \\ \\ | |  |  __|    | |   | |  |  _  / \n| |__/ /   | |____   | |      | |   __| |__   | |  \\ \\| |  | |____   \\ \\___/ /  | | \\ \\ \n|_____/    |______|  |_|      |_|  |_______|  |_|   \\___|  |______|   \\_____/   |_|  \\_\\ \n\n");
  couleur("0");  
}



// This procedure ask the user what grid size and how many bombs he wants
void gameMode(int *row_amount, int *column_amount, int *bomb_amount, Score* high_score) { 
  // high_score->mode 1=Beginner 2=Advanced 3=Personnalized (to do : 4=multi)
  int leave;
  // Ask the gamemode to the user
  clrscr();
  titlePrint();
  printf("                              Choisissez le mode de jeu: \n\n1. Débutant(9x9)\n2. Avancé(16x16)\n3. Personnalisé(max 26x26)\n4. Quitter\n");
  scanf("%d", &high_score->mode);
  clear();
  while (high_score->mode > 4 || high_score->mode < 1){
    clrscr();
    titlePrint();
    printf("                              Choisissez le mode de jeu: \n\n1. Débutant(9x9)\n2. Avancé(16x16)\n3. Personnalisé(max 26x26)\n4. Quitter\n");
    error("de saisie");
    scanf("%d", &high_score->mode);
    clear();
  }
  switch (high_score->mode) {
    // If "Débutant" is selected => 9x9 with 10 bombs
    case 1: 
      *row_amount = 9;
      *column_amount = 9;
      *bomb_amount = 10;
      break;
    // If "Avancé" is selected => 16x16 with 40 bombs
    case 2: 
      *row_amount = 16;
      *column_amount = 16;
      *bomb_amount = 40;
      break;
    // If "Personnalisé" is selected
    case 3: 
      // Ask about the row amount
      clrscr();
      printf("Saisissez le nombre de lignes que vous voulez(min 1 ; max 26) : ");      
      scanf("%d", row_amount);
      clear();
       while (*row_amount < 1 || *row_amount > 26){
        clrscr();
        printf("Saisissez le nombre de lignes que vous voulez(min 1 ; max 26) : "); 
        error("de saisie");
        scanf("%d", row_amount);
        clear();
        // min 1; max 26
      } 
      // Ask about the column amount
      clrscr();
      printf("Saisissez le nombre de colonnes que vous voulez(min 1 ; max 26) : "); 
      scanf("%d", column_amount);
      clear();
      while (*column_amount < 1 || *column_amount > 26){
        clrscr();
        printf("Saisissez le nombre de colonnes que vous voulez(min 1 ; max 26) : "); 
        error("de saisie");
        scanf("%d", column_amount);
        clear();
        // min 1; max 26
      } 
      // Ask about the bomb amount
      clrscr();
      printf("Saisissez le nombre de bombes que vous voulez(min 1 ; max: %d) :",*column_amount**row_amount);
      scanf("%d", bomb_amount);
      clear();
      while ((*bomb_amount < 1 ||(*bomb_amount > *row_amount * *column_amount))){
        clrscr();
        printf("Saisissez le nombre de bombes que vous voulez(min 1 ; max: %d) :",*column_amount**row_amount);
        error("de saisie");
        scanf("%d", bomb_amount);
        clear();
       // min 1; max (rows * columns)
      }
      break;
    // If the user wants to leave the game
    case 4:
      clrscr();
      titlePrint();
      // Ask if he is sure he wants to do so
      printf("Etes-vous sûr de vouloir quitter ?\n1. Oui\n2. Non\n");
      scanf("%d",&leave);
      clear();
      while(leave != 1 && leave != 2){
        clrscr();
        titlePrint();
        printf("Etes-vous sûr de vouloir quitter ?\n1. Oui\n2. Non\n");
        error("de saisie");
        scanf("%d",&leave);
        clear();
      }
      // If he still wants to leave, clear and quit the programm
      if(leave==1){
        clrscr();
        exit(0);
      }
      // Else, ask him the gamemode again
      else{
        gameMode(row_amount, column_amount, bomb_amount,high_score);
      }
      break;
  }
  
}

