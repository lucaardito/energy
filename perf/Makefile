CC=g++
RM=rm -f
BIN=./bin
SRC=./src
FLAGS=-g

all: jpgencoder jpgdecoder

jpgencoder:
	$(CC) $(FLAGS) $(SRC)/jpeg_encoding.cpp -o $(BIN)/jpgencoder

jpgdecoder:
	$(CC) $(FLAGS) $(SRC)/jpeg_decoderFast.cpp -o $(BIN)/jpgdecoder

clean:
	$(RM) ./bin/jpgencoder
	$(RM) ./bin/jpgdecoder
