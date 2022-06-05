#include "header.h"


int main(){
  srand(time(NULL));
  FILE* new_txt=NULL;
  new_txt=fopen("HighScore.txt","a");
  fclose(new_txt);
  int row_amount, column_amount, bomb_amount, bomb_remain, result, tot_time;
  Score high_score={0},current_score={0};
  
  while(0 != 1){
    // Initialisation
    row_amount=0; column_amount=0; bomb_amount=0; result=0;
    current_score.score=0;
    high_score.score=max_score;high_score.mode=0;

    gameMode(&row_amount,&column_amount,&bomb_amount,&high_score);
    Case** caseTab=gridBuilder(row_amount,column_amount,bomb_amount); 
    bomb_remain=bomb_amount;
    
    getHighScore(&high_score);
    current_score.mode=high_score.mode;
    showTab(caseTab,row_amount,column_amount,&bomb_amount,high_score);
   
   

    tot_time = -time(NULL);
    
    do{
      result=gameTurn(caseTab,row_amount,column_amount,&bomb_remain, high_score);
    }while(result==0);
    
    tot_time += time(NULL);

 

    // Conclusion
    if(result==-1){
      printf("BOOM... Partie terminée, vous avez perdu...\n");
      printf("Appuyez sur Entrée pour revenir au menu\n");
      clear();
      
    }
    else if(result==1){
      current_score.score=tot_time;
      printf("Partie terminée, vous avez gagné!\n");
      printf("Temps : %ds",tot_time);
      if(current_score.score<high_score.score){
        printf(" NOUVEAU RECORD !");
        printf("\nEntrez votre pseudo :\n");
        scanf("%s", current_score.nickname);
        clear();
        while (current_score.nickname[0]==0){
          clrscr();
          printf("Partie terminée, vous avez gagné!\n");
          printf("Temps : %ds",tot_time);
          printf(" NOUVEAU RECORD !");
          printf("\nEntrez votre pseudo :\n");
          error("de saisie");
          scanf("%s", current_score.nickname);
          clear();
        }
        newHighScore(current_score);
        clrscr();
        printf("Partie terminée, vous avez gagné!\n");
        printf("Temps : %ds",tot_time);
        printf(" NOUVEAU RECORD !");
        printf("\nNouveau meilleur score enregistré");
      }
      printf("\nAppuyez sur Entrée pour revenir au menu\n");
      clear();
    }
    
   
    
    
  }
  return 0;
}

