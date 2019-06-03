CC=gcc
CFLAGS=-I. -fPIC
OBJ=obj
SRC=sha3
TARGET=libskunk_hash.so

SOURCES := $(wildcard $(SRC)/*.c)
OBJS :=  $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SOURCES)) $(OBJ)/skunkhash.o

$(TARGET): $(OBJS) 
	$(CC) -o $@ $^ $(CFLAGS) -shared 
	cp $@ /usr/lib

$(OBJ)/%.o: $(SRC)/%.c | $(OBJ)
	$(CC) -c -o $@ $< $(CFLAGS)

$(OBJ):
	mkdir obj

$(OBJ)/skunkhash.o: skunkhash.c
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean
clean:
	rm -Rf $(OBJ) *.so 
