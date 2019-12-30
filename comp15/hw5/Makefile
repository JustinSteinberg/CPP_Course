#
# Filename: Makefile
# Contains: Makefile
# For HW5 of Comp 15
#
CC = clang++
CFLAGS = -Wall -Wextra -c -std=c++11
DEPS = SixDegrees.h Graph.h Queue.h Stack.h LinkedList.h NodeType.h Actor.h


%.o: %.cpp $(DEPS)
	$(CC) -o $@ $< $(CFLAGS)

sixdegrees: main.o SixDegrees.o Graph.o Queue.o Stack.o LinkedList.o Actor.o
	$(CC) -o sixdegrees main.o SixDegrees.o Graph.o Queue.o Stack.o LinkedList.o Actor.o

clean:
	rm -f *.o core* *~ sixdegrees


