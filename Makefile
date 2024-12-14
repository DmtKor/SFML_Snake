CC=g++
CFLAGS=-c -Wall -pedantic

all: clean build
	./build/app

build_src: clean
	$(CC) ./src/main.cc ./src/handle_events.cc ./src/logic_update.cc ./src/draw_objects.cc -o ./build/app -lsfml-graphics -lsfml-window -lsfml-system

build: clean main.o handle_events.o logic_update.o draw_objects.o menu.o
	$(CC) ./build/temp/main.o ./build/temp/handle_events.o ./build/temp/logic_update.o ./build/temp/draw_objects.o ./build/temp/menu.o -o ./build/app -lsfml-graphics -lsfml-window -lsfml-system

main.o:
	$(CC) ./src/main.cc $(CFLAGS) -o ./build/temp/main.o

handle_events.o:
	$(CC) ./src/handle_events.cc $(CFLAGS) -o ./build/temp/handle_events.o

logic_update.o:
	$(CC) ./src/logic_update.cc $(CFLAGS) -o ./build/temp/logic_update.o

draw_objects.o:
	$(CC) ./src/draw_objects.cc $(CFLAGS) -o ./build/temp/draw_objects.o

menu.o:
	$(CC) ./src/menu.cc $(CFLAGS) -o ./build/temp/menu.o

clean:
	rm -rf ./build/temp/*.o
	rm -rf ./build/app