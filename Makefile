#
# fichier Makefile
# auteurs : Jérôme Barbier, Mehdi NS, Augustin Husson, David Levayer
# date : 28/05/2013
#

CC = gcc
OBJS = main.o arbre.o
EXEC = main
FLAGS = -Wall -g -DDEBUG

all: $(EXEC) 

arbre.o: arbre.c lzw.h 
	$(CC) $(FLAGS) -c $<

main.o: main.c arbre.h
	$(CC) $(FLAGS) -c $<

$(EXEC): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(EXEC)

clean:
	rm $(OBJS) $(EXEC)
	rm *~
