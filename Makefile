
tweet:
	gcc -Wall -ansi -g -o tweet tweet.c

counter:
	gcc -o count count.c

clean:
	rm -rf tweet count
