CC=g++
RM=rm -f
BIN=./bin
SRC=./src
FLAGS=-g -fno-omit-frame-pointer -shared-libgcc

all: jpgencoder jpgdecoder mem

jpgencoder:
	$(CC) $(FLAGS) $(SRC)/jpeg_encoding.cpp -o $(BIN)/jpgencoder

jpgdecoder:
	$(CC) $(FLAGS) $(SRC)/jpeg_decoderFast.cpp -o $(BIN)/jpgdecoder

clean:
	$(RM) $(BIN)/*

run:
	script/alloc.sh
	script/jpgdecoder.sh input/img.jpg
	script/jpgencoder.sh input/img.bmp

rep:
	perf report -n -g graph -i ./data/jpgdecoder.data

mem:
	gcc -g $(SRC)/simpleCalloc.c -o $(BIN)/c-alloc
	$(CC) $(FLAGS) $(SRC)/simpleCPPalloc.cpp -o $(BIN)/cpp-alloc
