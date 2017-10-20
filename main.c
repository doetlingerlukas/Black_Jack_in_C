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

#include "card.h"
#include "setup.h"

void mix_cards(char* cards);
int equal_cards(char* cards_original, char* cards_manipulated);

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
	
	card* bank = init_deck(8);
	card* player = init_deck(8);
	
	dispense_cards(deck, bank, player);
	
	print_deck(8, bank);
	print_deck(8, player);
	
	printf("%d\n", sum_deck(player));
	printf("%c, %c\n", get_color_of_card(player[0].color_key), 
		get_color_of_card(player[1].color_key));
	
	free(bank);
	free(player);
	free(deck);

	return EXIT_SUCCESS;
}

void decision(card* player){
	/*
	printf("Card or stay? (c/s)");
	char desicion;
	scanf("%c", desicion);
	*/
	get_card(player);
}

