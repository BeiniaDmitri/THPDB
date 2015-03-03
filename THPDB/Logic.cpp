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
	player1->hand = 0;
	player1->hand = CombinationStraight(combination1);
	printf("%d\n", player1->hand);
	if (player1->hand == 0)
		printf("false\n");
}

int CombinationStraight(Table* combination){

	int highCard = 0;
	int counter = 0;
	bool straightIsFound = false;
	bool cell = false;
	int straightArray[13] = { 4, 8, 12, 16, 20, 24, 28, 32, 36, 40, 44, 48, 52 };
	int straightArrayHelp[13] = { 4, 8, 12, 16, 20, 24, 28, 32, 36, 40, 44, 48, 52 };
	for (int i = 0; i <fullSize; i++){
		for (int j = 0; j < cellCount; j++){
			if (combination->cards[i] <= straightArray[j]){
				straightArrayHelp[j] = 1;
				cell = true;
			}
			if (cell)
				break;
		}
		cell = false;
	}
	for (int i = 0; i < cellCount; i++){
		printf("%d ", straightArrayHelp[i]);
	}
	
	for (int i = cellCount - 1; i >= 0; i--){
		if (straightArrayHelp[i] == 1){
			for (int j = i;; j--){
				if (straightArrayHelp[j] == 1)
					counter++;
				else break;
				if (counter == 5){
					highCard = i;
					straightIsFound = true;
					break;
				}
			}
		}
		counter = 0;
		if (straightIsFound)
			break;
	}
	if (straightIsFound)
		return Straight + highCard + 2;
	else return 0;
}