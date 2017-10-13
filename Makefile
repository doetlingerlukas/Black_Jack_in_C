CC = gcc
OBJ = main.o setup.o
CFLAGS = -Wall -Wextra -Werror 

blackjack: $(OBJ)
	 $(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o blackjack
.PHONY: all clean
