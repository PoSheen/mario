CC := g++
CFLAGS := -Wall -std=c++17 -O2 -v
ALLEGRO_LIBRARIES := allegro-5 allegro_image-5 allegro_font-5 allegro_ttf-5 allegro_dialog-5 allegro_primitives-5 allegro_audio-5 allegro_acodec-5
ALLEGRO_FLAGS := $(shell pkg-config --cflags --libs "$(ALLEGRO_LIBRARIES) <= 5.2.7") -lallegro -lallegro_main

OUT:= game
SOURCE = practice.cpp Hero.cpp global.cpp DataCenter.cpp map.cpp ../algif5/src/algif.cpp ../algif5/src/bitmap.cpp ../algif5/src/gif.cpp ../algif5/src/lzw.cpp
OBJ = practice.o Hero.o global.o DataCenter.o map.o algif.o bitmap.o gif.o lzw.o

all: 
	$(CC) -c -g $(CFLAGS) $(SOURCE) $(ALLEGRO_FLAGS)
	$(CC) $(CFLAGS) -o $(OUT) $(OBJ) $(ALLEGRO_FLAGS)
	rm $(OBJ)

.PHONY:clean
clean:
	rm $(OUT)
