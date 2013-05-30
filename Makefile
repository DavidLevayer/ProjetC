#
# fichier Makefile
# auteurs : Jérôme Barbier, Mehdi NS, Augustin Husson, David Levayer
# date : 28/05/2013
#

CC = gcc
OBJS = main.o dictionnaire.o fichier.o lzw.o
EXEC = main
FLAGS = -Wall -g -DDEBUG

all: $(EXEC) 

lzw.o: lzw.c lzw.h fichier.h dictionnaire.h
	$(CC) $(FLAGS) -c $<

main.o: main.c lzw.h fichier.h
	$(CC) $(FLAGS) -c $<

$(EXEC): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(EXEC)

clean:
	rm $(OBJS) $(EXEC)
	rm *~
