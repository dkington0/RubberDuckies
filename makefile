CC = g++
FLAGS = -std=c++17 -Wall -g

all: vector_test

vector_test: vector_test.cpp
        $(CC) $(FLAGS) vector_test.cpp -o circle.h rectangle.h

clean:
        rm -f vector_test

tar:
        tar cf vector_test.tar vector_test.scr makefile vector_test.cpp
