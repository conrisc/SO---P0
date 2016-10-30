main: main.o
	gcc -Wall -Werror main.c -o main -pthread

run:
	./main
