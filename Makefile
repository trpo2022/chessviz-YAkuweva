all:
	gcc -Wall -Werror -o main main.c
test:
	./main
