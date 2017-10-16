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


/* initializes a card deck */
card* init_deck(int size) {
	card* to_return = malloc(sizeof(card) * size);
	
	for (int i = 0; i < size; i++) {
		to_return[i].number = '0';
		to_return[i].value = 0;
		to_return[i].color_key = 0;
	}
	
	return to_return;
}


/* return amount of cards in deck */
int get_cardamount_of_deck(card* deck) {
	int max = 0;
	
	for (int i = 0; i < CARD_NUMBER; i++) {
		if (deck[i].number == '0') {
			max = i;
			i = CARD_NUMBER;
		}
	}
	if (max == 0) {
		max = CARD_NUMBER - 1;
	}
	
	return max;
}

/* function to scramble the cards inside a deck */
void mix_deck(card* deck) {
	int amount = get_cardamount_of_deck(deck);
	
	card* original_deck = malloc(sizeof(card) * CARD_NUMBER);
	memcpy(original_deck, deck, sizeof(card) * CARD_NUMBER);
	card temp;
	
	while (equal_decks(original_deck, deck) > 5) {
		for (int i = 0; i < amount; i++) {
			int r = rand() % amount;
			temp = deck[i];
			deck[i] = deck[r];
			deck[r] = temp;
		}
	}
	
	free(original_deck);
}


/* function that returns number of equal value cards in deck */
int equal_decks(card* original, card* manipulated) {
	int amount = get_cardamount_of_deck(original);
	int counter = 0;
	
	for (int i = 0; i < amount; i++) {
		if (original[i].number == manipulated[i].number) {
			counter++;
		}
	}
	
	return counter;
}


/* function to fill an empty card deck */
void fill_card_deck(card* deck) {
	int length = 0;
	int color_val = 1;
	
	for (int i = 0; i < 4; i++) {
		deck[length].number = 'A';
		deck[length].value = 11;
		deck[length].color_key = color_val;
		length++;
		deck[length].number = '2';
		deck[length].value = 2;
		deck[length].color_key = color_val;
		length++;
		deck[length].number = '3';
		deck[length].value = 3;
		deck[length].color_key = color_val;
		length++;
		deck[length].number = '4';
		deck[length].value = 4;
		deck[length].color_key = color_val;
		length++;
		deck[length].number = '5';
		deck[length].value = 5;
		deck[length].color_key = color_val;
		length++;
		deck[length].number = '6';
		deck[length].value = 6;
		deck[length].color_key = color_val;
		length++;
		deck[length].number = '7';
		deck[length].value = 7;
		deck[length].color_key = color_val;
		length++;
		deck[length].number = '8';
		deck[length].value = 8;
		deck[length].color_key = color_val;
		length++;
		deck[length].number = '9';
		deck[length].value = 9;
		deck[length].color_key = color_val;
		length++;
		deck[length].number = 'Z';
		deck[length].value = 10;
		deck[length].color_key = color_val;
		length++;
		deck[length].number = 'B';
		deck[length].value = 10;
		deck[length].color_key = color_val;
		length++;
		deck[length].number = 'D';
		deck[length].value = 10;
		deck[length].color_key = color_val;
		length++;
		deck[length].number = 'K';
		deck[length].value = 10;
		deck[length].color_key = color_val;
		length++;
		
		color_val++;
	}
}
