#
# fichier Makefile
# auteurs : Jérôme Barbier, Mehdi NS, Augustin Husson, David Levayer
# date : 28/05/2013
#

CC = gcc
OBJS = main.o list.o
EXEC = main
FLAGS = -Wall -g -DDEBUG

all: $(EXEC) 

list.o: list.c 
	$(CC) $(FLAGS) -c $<

main.o: main.c list.h 
	$(CC) $(FLAGS) -c $<

$(EXEC): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(EXEC)

clean:
	rm $(OBJS) $(EXEC)
	rm *~
