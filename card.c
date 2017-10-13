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


/* puts a card back to a deck */
void put_card_back(card* deck, card c){
	int found = 0;
	int count = 0;
	
	while(found == 0){
		if(deck[count].number == '0'){
			found = 1;
		}
		count++;
		if(count == 55){
			perror("No space to put back card !\n");
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
