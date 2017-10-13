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

#include "main.h"
#include "setup.h"

void mix_cards(char* cards);
int equal_cards(char* cards_original, char* cards_manipulated);

int main(void){
	
	srand(time(NULL));
	
	
	card* deck = malloc(sizeof(card)*13*4);
	
	fill_card_deck(deck);
	
	for(int i = 0; i < 52; i++){
		printf("%c", deck[i].number);
	}
	printf("\n");
	
	mix_deck(deck);
	
	for(int i = 0; i < 52; i++){
		printf("%c", deck[i].number);
	}
	
	free(deck);

}



