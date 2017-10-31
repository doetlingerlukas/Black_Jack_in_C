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
#include <unistd.h>

#include "card.h"
#include "setup.h"


int main(void){
	
	srand(time(NULL));
	
	card* deck = malloc(sizeof(card)*13*4);
	
	fill_card_deck(deck);
	mix_deck(deck);
	
	/* to be put into a test file
	for(int i = 0; i < 52; i++){
		printf("%c", deck[i].number);
	}
	printf("\n");
	
	mix_deck(deck);
	
	for(int i = 0; i < 52; i++){
		printf("%c", deck[i].number);
	}
	printf("\n");
	
	card got;
	for(int j = 0; j < 8; j++){
		got = get_card(deck);
	
		printf("%c\n", got.number);
	}
	
	for(int i = 0; i < 52; i++){
		printf("%c", deck[i].number);
	}
	printf("\n");
	
	put_card(deck, got);
	
	for(int i = 0; i < 52; i++){
		printf("%c", deck[i].number);
	}
	printf("\n");
	
	mix_deck(deck);
	
	for(int i = 0; i < 52; i++){
		printf("%c", deck[i].number);
	}
	printf("\n");*/
	
	person bank;
	person player;
	
	bank.deck = init_deck(8);
	player.deck = init_deck(8);
	
	bank.finished = 0;
	player.finished = 0;
	
	dispense_cards(deck, bank.deck, player.deck);
	
	printf("Bank cards: ");
	print_deck(8, bank.deck);
	printf("Your cards: ");
	print_deck(8, player.deck);
	
	// player buying 
	while(sum_deck(player.deck) < 21 && player.finished == 0){
		player.finished = decide(deck, player);
		printf("Your cards: ");
		print_deck(8, player.deck);
	}
	
	// bank buying
	while(sum_deck(bank.deck) <= 16){
		buy(deck, bank.deck);
		printf("Bank cards: ");
		print_deck(8, bank.deck);
		sleep(1);
	}
	
	free(bank.deck);
	free(player.deck);
	free(deck);

	return EXIT_SUCCESS;
}


