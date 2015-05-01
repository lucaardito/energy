CC=g++
RM=rm -f
BIN=./bin
SRC=./src

all: jpgencoder jpgdecoder

jpgencoder:
	$(CC) $(SRC)/jpeg_encoding.cpp -o $(BIN)/jpgencoder

jpgdecoder:
	$(CC) $(SRC)/jpeg_decoderFast.cpp -o $(BIN)/jpgdecoder

clean:
	$(RM) ./bin/jpgencoder
	$(RM) ./bin/jpgdecoder
