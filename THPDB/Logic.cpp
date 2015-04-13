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
	
		
		combination1->cards[0] = 1;
		combination1->cards[1] = 13;
		combination1->cards[2] = 4;
		combination1->cards[3] = 29;
		combination1->cards[4] = 21;
		combination1->cards[5] = 25;
		combination1->cards[6] = 40;
		player1->hand = CombinationFlush(combination1);
	
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


int CombinationFlush(Table* combination){

	int highCard = 0;
	int highCardHeart = 0;
	int highCardSpade = 0;
	int highCardDiamond = 0;
	int highCardClub = 0;
	bool flushIsFound = false;
	int counterHeart = 0;
	int counterSpade = 0;
	int counterClub = 0;
	int counterDiamond = 0;
	int heart[13] = { 1, 5, 9, 13, 17, 21, 25, 29, 33, 37, 41, 45, 49 };
	int spade[13] = { 2, 6, 10, 14, 18, 22, 26, 30, 34, 38, 42, 46, 50 };
	int club[13] = { 3, 7, 11, 15, 19, 23, 27, 31, 35, 39, 43, 47, 51 };
	int diamond[13] = { 4, 8, 12, 16, 20, 24, 28, 32, 36, 40, 44, 48, 52 };
	int heartArray[5] = { 0, 0, 0, 0, 0 };
	int spadeArray[5] = { 0, 0, 0, 0, 0 };
	int clubArray[5] = { 0, 0, 0, 0, 0 };
	int diamondArray[5] = { 0, 0, 0, 0, 0 };
	for (int i = 0; i < fullSize; i++) {
		for (int j = 0; j < fullSize - i - 1; j++) {
			if (combination->cards[j] > combination->cards[j + 1]) {
				int tmp = combination->cards[j];
				combination->cards[j] = combination->cards[j + 1];
				combination->cards[j + 1] = tmp;
			}
		}

	}

	for (int i = fullSize - 1; i >= 0; i--){
		for (int j = cellCount - 1; j >= 0; j--){
			if (combination->cards[i] == heart[j]){
				counterHeart++;
				heartArray[counterHeart - 1] = j;
				break;
			}
			if (combination->cards[i] == spade[j]){
				counterSpade++;
				spadeArray[counterSpade - 1] = j;
				break;
			}
			if (combination->cards[i] == club[j]){
				counterClub++;
				clubArray[counterClub - 1] = j;
				break;
			}
			if (combination->cards[i] == diamond[j]){
				counterDiamond++;
				diamondArray[counterDiamond - 1] = j;
				break;
			}
			
		}
		if (counterHeart == 5){
			flushIsFound = true;
			break;
		}
		if (counterClub == 5){
			flushIsFound = true;
			break;
		}
		if (counterDiamond == 5){
			flushIsFound = true;
			break;
		}
		if (counterSpade == 5){
			flushIsFound = true;
			break;
		}
	}
	
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3 - i; j++) {
			if (heartArray[j] > heartArray[j + 1]) {
				int tmp = heartArray[j];
				heartArray[j] = heartArray[j + 1];
				heartArray[j + 1] = tmp;
			}
		}

	}

	highCard = highCardArray[3];

		if (flushIsFound){
			printf("%s", "flush!!!");
			return Flush + highCard + 2;
		}
		else return 0;
}










