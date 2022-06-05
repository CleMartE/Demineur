all:exec

main.o: main.c header.h
	gcc -c $< -o $@

gameMode.o: gameMode.c header.h
	gcc -c $< -o $@

GestionGrid.o:GestionGrid.c header.h
	gcc -c $< -o $@

GestionTrun.o:GestionTurn.c header.h
	gcc -c $< -o $@

HighScore.o:HighScore.c header.h
	gcc -c $< -o $@

showTab.o: showTab.c header.h
	gcc -c $< -o $@

exec :main.o gameMode.o GestionGrid.o GestionTurn.o HighScore.o showTab.o tileDiscovery.o
	gcc $^ -o $@

clear:
  rm *.o
