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

card get_card(card* deck);
void put_card_back(card* deck, card c);

#endif // __CARD_H_
