CC = gcc
CFLAGS = -Wall -Wextra -g

OBJ = main.o create.o search.o save.o update.o validate.o

inverted_search: $(OBJ)
	$(CC) $(OBJ) -o inverted_search

%.o: %.c header.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o inverted_search