# General Makefile for small C programs
# Based on one by Alexender Hiam in Jan 2013
# Jim Mahoney | Jan 2016 | Public Domain

############################################################
# Modify these to fit your project.

# The name of the target executable
SINGLE_TARGET  = baboons_single
MULTI_TARGE = baboons_multi

# Space separated list of all source files
SINGLE_SOURCE = baboons.c single.c
MULTI_SOURCE = baboons.c multi.c

# Space separated directories containing source files
INCLUDE_DIRS =

# Compiler flags (e.g. optimization, links, etc.):
CFLAGS = -O2 -g -Wall -pthread

# Compiler:
CC = gcc

############################################################
# You probably won't need to change this part.

# Append -I to each include dir
INCLUDES = $(foreach dir, $(INCLUDE_DIRS), -I$(dir))

# Create list of the object files
SINGLE_OBJECTS = $(SINGLE_SOURCE:.c=.o)
MULTI_OBJECTS = $(MULTI_SOURCE:.c=.o)

all:
	make single
	make multi
	make clean

single: $(SINGLE_OBJECTS)
	   $(CC) $(CFLAGS) $(SINGLE_OBJECTS) -o $(SINGLE_TARGET)

multi: $(MULTI_OBJECTS)
	  $(CC) $(CFLAGS) $(MULTI_OBJECTS) -o $(MULTI_TARGET)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f *.o *.d
