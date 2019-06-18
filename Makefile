#		MAKEFILE
#
# Danny Leonel De LA A

CC=gcc -Wall -c
OBJ= shell.o

all: shell_r

shell_r: $(OBJ)
	gcc obj/$< -o bin/$@ -g 

shell.o: shell.c
	$(CC) $< -o obj/$@


.PHONY: clean
clean:
	rm bin/* obj/*


