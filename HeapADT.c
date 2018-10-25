//Author:Matthew "The Hammer" O'Herren
//revisions can be found in revisions.txt

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "HeapADT.h"

typedef struct Heap_S
{
	int capacity;
	int(*compFun)(const void * lhs, const void * rhs);
	void(*dumpEntry)(const void * item, FILE * outfp);
	int size;
	int* contents;

} * Heap;

Heap *heap;

Heap createHeap(size_t capacity, int(*compFun)(const void *lhs, const void *rhs), void(*dumpEntry)(const void *item, FILE *outfp))
{
	heap = malloc(sizeof(int)*2+sizeof(compFun)+sizeof(dumpEntry)+sizeof(int*));

	//heap = {capacity, compFun, dumpEntry, size, constraints};

	return 0;
}

void destroyHeap(Heap aHeap)
{
}

size_t sizeHeap(Heap aHeap)
{
	return 0;
}

const void * topHeap(const Heap aHeap)
{
	return NULL;
}

void * removeTopHeap(Heap aHeap)
{
	return NULL;
}

void insertHeapItem(Heap aHeap, const void * item)
{
}

void dumpHeap(Heap aHeap, FILE * outfp)
{
}

