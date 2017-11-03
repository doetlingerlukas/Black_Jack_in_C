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
	
	// 
	if(verify_black_jack(player.deck)){
		printf("You got a BlackJack\n");
	}
	
	// player buying 
	while(sum_deck(player.deck) < 21 && player.finished == 0){
		player.finished = decide(deck, player);
		printf("Your cards: ");
		print_deck(8, player.deck);
	}
	
	// bank buying
	while(sum_deck(bank.deck) < 16){
		sleep(1);
		buy(deck, bank.deck);
		printf("Bank cards: ");
		print_deck(8, bank.deck);
		sleep(1);
	}
	
	printf("******************************************************\n");
	int sum_bank = sum_deck(bank.deck);
	int sum_player = sum_deck(player.deck);
	printf("Bank: %d / You: %d\n", sum_bank, sum_player);
	
	if (sum_bank > 21 && sum_player <= 21){
		printf("You won!\n");
	} else if(sum_bank > sum_player && sum_bank <= 21){
		printf("You lost!\n");
	} else if(sum_bank < sum_player && sum_player <= 21){
		printf("You won!\n");
	} else {
		printf("Draw!\n");
	}
	
	
	free(bank.deck);
	free(player.deck);
	free(deck);

	return EXIT_SUCCESS;
}


