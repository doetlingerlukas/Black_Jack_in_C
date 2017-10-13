/******************************************************************
*
* setup.h
* 
* A Black Jack Game written in C.
* By Lukas Dötlinger
*
*******************************************************************/

#ifndef __SETUP_H__
#define __SETUP_H__

#include "main.h"

void mix_deck(card* deck);
int equal_decks(card* original, card* manipulated);
void fill_card_deck(card* deck);


#endif // __SETUP_H_
