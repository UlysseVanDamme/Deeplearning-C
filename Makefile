CC = gcc
CFLAGS = -Iinclude -Wall -g

SRC = src/main.c src/matrix.c
OUT = build/main

all:
	mkdir -p build
	$(CC) $(SRC) $(CFLAGS) -o $(OUT)

run: all
	./$(OUT)

test_matrix:
	$(CC) tests/test_matrix.c src/matrix.c -Iinclude -o build/test_matrix
	./build/test_matrix

test_vector:
	mkdir -p build
	gcc tests/test_vector.c src/vector.c src/matrix.c -Iinclude -o build/test_vector
	./build/test_vector

clean:
	rm -rf build