#include "header.h"

//This procedure puts a new high_score in the file High_score.txt
void newHighScore(Score new_high_score){
  FILE* file=NULL;
  file=fopen("HighScore.txt","a");
  if (file==NULL){
    printf("Erreur d'ouverture du fichier\n");
    exit(1);
  } 
  fwrite(&new_high_score, sizeof(Score), 1, file);
  fclose(file);
}

//This procedure gets the high_score of a gamemode in the file High_Score.txt
void getHighScore(Score* high_score){
  //Create a file pointer
  FILE* file=NULL;
  //Initiate a temporary score, and set his score to max
  Score temp_score={0};
  temp_score.score=max_score;
  //Open the file
  file=fopen("HighScore.txt","r");
  if (file==NULL){
    printf("Erreur d'ouverture du fichier\n");
    exit(1);
  } 
  //While the cursor isn't at the End Of File
  while(! feof(file)){
    //Get a high_score from the file 
    fread(&temp_score, sizeof(Score), 1, file);
    //Check if the game_mode of the high_score is the same as the current game_mode, 
    //and if the temporary score is better than the previous high_score checked
    if (temp_score.mode==high_score->mode && temp_score.score<high_score->score){
      //If so, take the score and nickname from the temporary score and put it in the high_score
      high_score->score=temp_score.score;
      for(int i=0;i<nickname_size;i++){
        high_score->nickname[i]=temp_score.nickname[i];
      }
    }
  }
  fclose(file);
}



