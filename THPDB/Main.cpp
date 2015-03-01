#include"Prototypes.h"



int main(){
	Player *player1 = (Player *)calloc(1, sizeof(Player));
	Player *player2 = (Player *)calloc(1, sizeof(Player));
	player1->bankroll = 0;
	player1->firstCard = 0;
	Table *combination1 = (Table*)calloc(1, sizeof(Table));
	Table *combination2 = (Table*)calloc(1, sizeof(Table));
	for (int i = 0; i < fullSize; i++){
		combination1->cards[i] = 0;
		combination2->cards[i] = 0;
	}

	//	combination1 = NULL; combination2 = NULL;
	int a[52] = {};
	srand(time(NULL));
	for (int i = 0; i < 52; i++){
		fflush(stdin);
		a[i] = Random();
		printf("%d\n", a[i]);
	}
	Game(player1, player2, combination1, combination2);


	system("pause");
}