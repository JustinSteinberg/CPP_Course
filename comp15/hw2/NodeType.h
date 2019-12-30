/*
 * NodeType.h
 * COMP15
 * Spring 2019
 *
 * Small struct that is part of a Linked List class
 *
 */


#include "Station.h"
using namespace std;

#ifndef NODETYPE
#define NODETYPE

struct NodeType
{
    Station info;
    NodeType *next;
};

#endif
