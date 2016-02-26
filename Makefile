####################################################################
#
#	IDENTIFICATION DIVISION.
#	PROGRAM-ID. WOPR Makefile.
#	AUTHOR. Taylor Rainwater.
#	INSTALLATION. alduin.
#	DATE-WRITTEN. 8.11.2015.
#	DESCRIPTION. The WOPR Makefile.
#
####################################################################

CC = gcc
CFLAGS = -Wall -I -g -o
OBJS = wopr.c ttt.c actions.c nuclear.c games.c
HDRS = wopr.h

wopr: $(HDRS)
	$(CC) $(OBJS) $(CFLAGS) wopr 

clean:
	rm -f *.o