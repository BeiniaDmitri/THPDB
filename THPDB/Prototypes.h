#include<iostream>
#include<time.h>

#define size 5
#define fullSize 7
#define turn 5
#define river 6
#define OnePair 100
#define TwoPairs 200
#define Three 300
#define Straight 400
#define Flush 500
#define FullHouse 600
#define Four 700
#define StraightFlush 800
#define RoyalFlush 900
#define Ace 14
#define King 13
#define Queen 12
#define Jack 11



struct Player{
	int bankroll;
	int firstCard;
	int secondCard;
};

struct Table{
	int cards[7];
}
;

int Random();
bool Compare(Table *, Table *);
void Game(Player *, Player *, Table *, Table *);
