####
# Makefile for baboons problem
# Kat Cannon-MacMartin
# Adapted from a Makefile by Jim Mahoney
###

STARGET = baboons_single
MTARGET = baboons_multi

SSOURCE = baboons.c single.c
MSOURCE = baboons.c multi.c

CFLAGS = -O2 -g -Wall -pthread
SFLAG = -D SINGLE

CC = gcc

###################################################

MOBJECTS = $(MSOURCE:.c=.o)
SOBJECTS = baboons_single.o single.o

all:
	make single
	make multi
	make clean

baboons_single.o: baboons.c
	$(CC) -c $(CFLAGS) $(SFLAG) -o baboons_single.o baboons.c

single: $(SOBJECTS)
	$(CC) $(CFLAGS) $(SFLAG) $(SOBJECTS) -o $(STARGET)
	make clean

multi: $(MOBJECTS)
	$(CC) $(CFLAGS) $(MOBJECTS) -o $(MTARGET)
	make clean

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f *.o *.d
