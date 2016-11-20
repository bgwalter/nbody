CC=g++
CFLAGS=-Wall -lX11
OUT=nbody

SRCDIR=src/
SRCEXT=cpp
SOURCES= $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))

INCDIR=include/
INCLUDES=-I$(INCDIR)

debug:
	$(CC) $(SOURCES) $(CFLAGS) -g $(INCLUDES) -o $(OUT)

all:
	$(CC) $(SOURCES) $(CFLAGS) $(INCLUDES) -o $(OUT)
