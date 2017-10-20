/******************************************************************
*
* card.c
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


/* returns 1 if player got a red hand, 0 otherwise */
int verify_red_hand(card* deck){
	if(is_red_card(deck[0]) && is_red_card(deck[1])){
		return 1;
	} else {
		return 0;
	}
}


/* returns 1 if a card has a red color, 0 otherwise */
int is_red_card(card c){
	if(c.color_key == 2 || c.color_key == 3){
		return 1;
	} else {
		return 0;
	}
}


/* returns the char representing the card color 
 * c -> club
 * d -> diamond
 * h -> heart
 * s -> spade */
char get_color_of_card(int color_val){
	switch(color_val){
		case 1 : 
			return 'c';
		case 2 : 
			return 'd';
		case 3 : 
			return 'h';
		case 4 : 
			return 's';
	}
	
	return '0';
}


/* distributes cards, which is the first operation of every game */
void dispense_cards(card* deck, card* bank, card* player){
	/** give card to bank **/
	put_card(bank, get_card(deck));
	
	/** give two cards to player **/
	put_card(player, get_card(deck));
	put_card(player, get_card(deck));
}


/* get a card and put it to the local deck */
void buy(card* deck, card* local_deck){
	put_card(local_deck, get_card(deck));
}


/* puts a card to a deck */
void put_card(card* deck, card c){
	int found = 0;
	int count = 0;
	
	while(found == 0){
		if(deck[count].number == '0'){
			found = 1;
		}
		count++;
		if(count == 55){
			perror("No space to put card !\n");
			return;
		}
	}
	
	deck[count-1] = c;
}


/* get a card from a deck */
card get_card(card* deck){
	card to_return = deck[0];
	
	for(int i = 0; i < 51; i++){
		deck[i] = deck[i+1];
	}
	deck[51].number = '0';
	deck[51].value = 0;
	deck[51].color_key = 0;
	
	return to_return;
}
