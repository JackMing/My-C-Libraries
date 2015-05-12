all:
	gcc -g -Wall -c *.c
	ar -cvq ../mylib.a *.o
clean:
	rm *.o
