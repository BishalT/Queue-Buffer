
main := main
CC = g++
CFLAGS	:= -Wall -Werror -g

all: $(main)

queue.o: queue.cpp queue.hpp
	$(CC) $(CLFLAGS) -c -o $@ $<

buffer.o: buff.cpp buff.hpp queue.o
	$(CC) $(CLFLAGS) -c -o $@ $<

main: main.cpp buffer.o
	$(CC) $(CLFLAGS) -o $@ $< buffer.o

clean:
	rm *.o