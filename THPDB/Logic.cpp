#include"Prototypes.h"

int Random(){

	int card = 0;
	card = 1 + rand() % 52;
	return card;
}

bool Compare(Table *combination1, Table *combination2){

	return 1;
}

void Game(Player *player1, Player *player2, Table *combination1, Table *combination2){

	srand(time(NULL));

	for (int i = 0; i < size; i++){
		combination1->cards[i] = Random();
		combination2->cards[i] = combination1->cards[i];
	}
	player1->firstCard = Random();
	player1->secondCard = Random();
	player2->firstCard = Random();
	player2->secondCard = Random();

	combination1->cards[turn] = player1->firstCard;
	combination1->cards[river] = player1->secondCard;
	combination2->cards[turn] = player2->firstCard;
	combination2->cards[river] = player2->secondCard;

	for (int i = 0; i < fullSize; i++){
		printf("%d ", combination1->cards[i]);
	}
	puts("");
	for (int i = 0; i < fullSize; i++){
		printf("%d ", combination2->cards[i]);
	}
	puts("");

}
