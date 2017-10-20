/******************************************************************
*
* card.h
* 
* A Black Jack Game written in C.
* By Lukas Dötlinger
*
*******************************************************************/

#ifndef __CARD_H__
#define __CARD_H__


typedef struct card{
	char number;
	int value;
	int color_key;
} card;


int verify_red_hand(card* deck);
int is_red_card(card c);
char get_color_of_card(int color_val);
void dispense_cards(card* deck, card* bank, card* player);
void buy(card* deck, card* local_deck);
card get_card(card* deck);
void put_card(card* deck, card c);

#endif // __CARD_H_
