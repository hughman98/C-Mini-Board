CC = gcc
CFLAGS = -g -Wall -Wextra

run: main
	valgrind --leak-check=full --show-leak-kinds=all ./main

main: sha256.o hash.o main.c
	$(CC) $(CFLAGS) $^ -o $@

hash.o: hash.c hash.h
	$(CC) $(CFLAGS) -c $< -o $@

sha256.o: sha256.c sha256.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o main

.PHONY: run clean
