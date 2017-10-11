#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void fill_cards(char* cards);
void mix_cards(char* cards);
int equal_cards(char* cards_original, char* cards_manipulated);

int main(void){
	
	srand(time(NULL));
	
	char* cards = malloc(13*4);
	
	fill_cards(cards);
	
	for(int i = 0; i < 52; i++){
		printf("%c", cards[i]);
	}
	printf("\n");
	
	mix_cards(cards);
	
	for(int i = 0; i < 52; i++){
		printf("%c", cards[i]);
	}

}



int equal_cards(char* cards_original, char* cards_manipulated){
	int counter = 0;
	
	for(int i = 0; i < 52; i++){
		if(cards_original[i] == cards_manipulated[i]){
			counter++;
		}
	}
	
	return counter;
}

void mix_cards(char* cards){
	char* original_cards = malloc(13*4);
	memcpy(original_cards, cards, 13*4);
	char temp;
	
	while(equal_cards(original_cards, cards) > 5){
		for(int i = 0; i < 52; i++){
			int r = rand() % 52;
			temp = cards[0];
			cards[0] = cards[r];
			cards[r] = temp;
		}
	}
	
	free(original_cards);
}

void fill_cards(char* cards){
	int lenght = 0;
	
	for(int i = 0; i < 4; i++){
		cards[lenght] = 'A';
		lenght++;
		cards[lenght] = '2';
		lenght++;
		cards[lenght] = '3';
		lenght++;
		cards[lenght] = '4';
		lenght++;
		cards[lenght] = '5';
		lenght++;
		cards[lenght] = '6';
		lenght++;
		cards[lenght] = '7';
		lenght++;
		cards[lenght] = '8';
		lenght++;
		cards[lenght] = '9';
		lenght++;
		cards[lenght] = 'Z';
		lenght++;
		cards[lenght] = 'B';
		lenght++;
		cards[lenght] = 'D';
		lenght++;
		cards[lenght] = 'K';
		lenght++;
	}
}
