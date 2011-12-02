# Makefile
# tweet?

NAME=tweet

all:
	gcc -ansi -o $(NAME) $(NAME).c

debug:
	gcc -Wall -ansi -g -o $(NAME) $(NAME).c

clean:
	rm -rf $(NAME)

