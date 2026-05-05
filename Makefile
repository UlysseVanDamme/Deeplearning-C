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

test_linalg:
	mkdir -p build
	gcc tests/test_linalg.c src/vector.c src/matrix.c src/linalg.c src/probability.c -Iinclude -o build/test_linalg -lm
	./build/test_linalg

test_ml:
	mkdir -p build
	gcc tests/test_ml.c src/vector.c src/matrix.c src/linalg.c src/probability.c src/machine_learning.c -Iinclude -o build/test_ml -lm
	./build/test_ml

test_rootfinding:
	mkdir -p build
	gcc tests/test_rootfinding.c src/rootfinding.c src/vector.c src/matrix.c src/linalg.c src/probability.c -Iinclude -o build/test_rootfinding -lm
	./build/test_rootfinding

test_optimization:
	mkdir -p build
	gcc tests/test_optimization.c src/optimization.c src/vector.c src/matrix.c src/linalg.c src/probability.c -Iinclude -o build/test_optimization -lm
	./build/test_optimization

test_interpolation:
	mkdir -p build
	gcc tests/test_interpolation.c src/interpolation.c src/vector.c src/matrix.c src/linalg.c src/probability.c -Iinclude -o build/test_interpolation -lm
	./build/test_interpolation

test_quadrature:
	mkdir -p build
	gcc tests/test_quadrature.c src/quadrature.c -Iinclude -o build/test_quadrature -lm
	./build/test_quadrature

clean:
	rm -rf build