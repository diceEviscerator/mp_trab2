IDIR =../include
CC=g++
EXT = cpp
CFLAGS= -I $(IDIR) -Wall 

ODIR=obj
LDIR =../lib

GTESTLIBS = /usr/lib/libgtest.a -lgtest -lpthread
LIBS=$(GTESTLIBS) 

_DEPS = roman.h 
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = roman_test.o roman.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.$(EXT) $(DEPS)
	$(CC) -g -c -o $@ $< $(CFLAGS)

trab2: $(OBJ)
	$(CC) -g -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 