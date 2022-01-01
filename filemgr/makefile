INCLUDE = ./include
SRCDIR = ./src
ODIR = ./src/obj

CC = gcc
CFLAGS = -g -Wall -I$(INCLUDE)

_DEPS = filemgr.h
DEPS = $(patsubst %, $(INCLUDE)/%, $(_DEPS))

_OBJ = main.o filemgr.o
OBJ = $(patsubst %, $(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(SRCDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

test_filemgr: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -rf $(ODIR)/*.o *~ core $(INCDIR)/*~
