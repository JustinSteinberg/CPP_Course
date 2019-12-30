# Author: Justin Steinberg
# Makefile for Trie
#
# Project 1 Week 2 
#
# Not using -Wextra

CXX      = clang++
CXXFLAGS = -std=c++11 -g3 -Wall -Wextra
LDFLAGS  = -g3

SeqMatch: main.o Trie.o 
	${CXX} ${LDFLAGS} -o SeqMatch main.o Trie.o

main.o:		main.cpp Trie.h
Trie.o:		Trie.cpp Trie.h

clean:
	rm -rf SeqMatch *.o *.dSYM

provide:
	provide comp15 proj1wk2 main.cpp Trie.cpp Trie.h \
		README Makefile


