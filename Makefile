CC = gcc
CFLAGS = -Iinclude -Wall -g

SRC = src/main.c src/matrix.c
OUT = build/main

all:
	mkdir -p build
	$(CC) $(SRC) $(CFLAGS) -o $(OUT)

run: all
	./$(OUT)

test:
	$(CC) tests/test_matrix.c src/matrix.c -Iinclude -o build/test_matrix
	./build/test_matrix

clean:
	rm -rf build