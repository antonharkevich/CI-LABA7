all: build
build: File1.cpp
	gcc -Wall -O0 -g3 -DDEBUG -std=c11 main.c -o programm.exe

run: programm.exe
	./programm.exe

clean:
	rm -rf *.o programm