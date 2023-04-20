all: gcc

gcc: main.o IntVector.o
	gcc -Wall -o main main.o IntVector.o

main.o: main.c
		gcc -c main.c

IntVector.o: IntVector.c
	gcc -c IntVector.c

clean:
	rm main main.o IntVector.o

run:
	./main