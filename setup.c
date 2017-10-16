/******************************************************************
*
* setup.c
* 
* A Black Jack Game written in C.
* By Lukas Dötlinger
*
*******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "setup.h"


/* return amount of cards in deck */
int get_cardamount_of_deck(card* deck){
	int max = 0;
	
	for(int i = 0; i < 52; i++){
		if(deck[i].number == '0'){
			max = i;
			i = 52;
		}
	}
	if(max == 0){
		max = 51;
	}
	
	return max;
}

/* function to scramble the cards inside a deck */
void mix_deck(card* deck){
	int amount = get_cardamount_of_deck(deck);
	printf("%d\n", amount);
	
	card* original_deck = malloc(sizeof(card)*13*4);
	memcpy(original_deck, deck, sizeof(card)*13*4);
	card temp;
	
	while(equal_decks(original_deck, deck) > 5){
		for(int i = 0; i < amount; i++){
			int r = rand() % amount;
			temp = deck[i];
			deck[i] = deck[r];
			deck[r] = temp;
		}
	}
	
	free(original_deck);
}


/* function that returns number of equal value cards in deck */
int equal_decks(card* original, card* manipulated){
	int amount = get_cardamount_of_deck(original);
	int counter = 0;
	
	for(int i = 0; i < amount; i++){
		if(original[i].number == manipulated[i].number){
			counter++;
		}
	}
	
	return counter;
}


/* function to fill an empty card deck */
void fill_card_deck(card* deck){
	int lenght = 0;
	int color_val = 1;
	
	for(int i = 0; i < 4; i++){
		deck[lenght].number = 'A';
		deck[lenght].value = 11;
		deck[lenght].color_key = color_val;
		lenght++;
		deck[lenght].number = '2';
		deck[lenght].value = 2;
		deck[lenght].color_key = color_val;
		lenght++;
		deck[lenght].number = '3';
		deck[lenght].value = 3;
		deck[lenght].color_key = color_val;
		lenght++;
		deck[lenght].number = '4';
		deck[lenght].value = 4;
		deck[lenght].color_key = color_val;
		lenght++;
		deck[lenght].number = '5';
		deck[lenght].value = 5;
		deck[lenght].color_key = color_val;
		lenght++;
		deck[lenght].number = '6';
		deck[lenght].value = 6;
		deck[lenght].color_key = color_val;
		lenght++;
		deck[lenght].number = '7';
		deck[lenght].value = 7;
		deck[lenght].color_key = color_val;
		lenght++;
		deck[lenght].number = '8';
		deck[lenght].value = 8;
		deck[lenght].color_key = color_val;
		lenght++;
		deck[lenght].number = '9';
		deck[lenght].value = 9;
		deck[lenght].color_key = color_val;
		lenght++;
		deck[lenght].number = 'Z';
		deck[lenght].value = 10;
		deck[lenght].color_key = color_val;
		lenght++;
		deck[lenght].number = 'B';
		deck[lenght].value = 10;
		deck[lenght].color_key = color_val;
		lenght++;
		deck[lenght].number = 'D';
		deck[lenght].value = 10;
		deck[lenght].color_key = color_val;
		lenght++;
		deck[lenght].number = 'K';
		deck[lenght].value = 10;
		deck[lenght].color_key = color_val;
		lenght++;
		
		color_val++;
	}
}
