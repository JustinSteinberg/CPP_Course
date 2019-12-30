
# Filename: Makefile
# Contains: Makefile
# For HW5 of Comp 15
#
CC = clang++
CFLAGS = -Wall -Wextra -c -std=c++11
LDFLAGS = -g3 -O2
DEPS = HashMap.h HashNode.h FSTreeTraversal.h DirNode.h FSTree.h StringProcessing.h


%.o: %.cpp $(DEPS)
	$(CC) -o $@ $< $(CFLAGS)


gerp: main.o HashMap.o FSTreeTraversal.o StringProcessing.o
	${CC} ${LDFLAGS} -o gerp main.o HashMap.o FSTreeTraversal.o FSTree.o DirNode.o StringProcessing.o

#HashMap.o: HashMap.cpp HashMap.h HashNode.h
#FSTreeTraversal.o: FSTreeTraversal.cpp FSTreeTraversal.h DirNode.h FSTree.h StringProcessing.h
#StringProcessing.o: StringProcessing.cpp StringProcessing.h
#main.o: main.cpp HashMap.h HashNode.h FSTreeTraversal.h DirNode.h FSTree.h StringProcessing.h


clean:
	rm -f *.o core* *~ gerp



