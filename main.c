/******************************************************************
*
* main.c
* 
* A Black Jack Game written in C.
* By Lukas Dötlinger
*
*******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "common.h"
#include "card.h"
#include "setup.h"

void mix_cards(char* cards);
int equal_cards(char* cards_original, char* cards_manipulated);

int main(void) {
	
	srand(time(NULL));
	
	
	card* deck = malloc(sizeof(card) * CARD_NUMBER);
	
	fill_card_deck(deck);
	mix_deck(deck);
	
	/* to be put into a test file
	for(int i = 0; i < 52; i++) {
		printf("%c", deck[i].number);
	}
	printf("\n");
	
	mix_deck(deck);
	
	for(int i = 0; i < 52; i++) {
		printf("%c", deck[i].number);
	}
	printf("\n");
	
	card got;
	for(int j = 0; j < 8; j++) {
		got = get_card(deck);
	
		printf("%c\n", got.number);
	}
	
	for(int i = 0; i < 52; i++) {
		printf("%c", deck[i].number);
	}
	printf("\n");
	
	put_card(deck, got);
	
	for(int i = 0; i < 52; i++) {
		printf("%c", deck[i].number);
	}
	printf("\n");
	
	mix_deck(deck);
	
	for(int i = 0; i < 52; i++) {
		printf("%c", deck[i].number);
	}
	printf("\n");*/
	
	card* bank = init_deck(8);
	card* player = init_deck(8);
	
	dispense_cards(deck, bank, player);
	
	for (int i = 0; i < 8; i++) {
		printf("%c", bank[i].number);
	}
	printf("\n");
	for (int i = 0; i < 8; i++) {
		printf("%c", player[i].number);
	}
	printf("\n");
	
	free(bank);
	free(player);
	free(deck);

	return EXIT_SUCCESS;
}



