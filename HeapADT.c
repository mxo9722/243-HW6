//Author:Matthew "The Hammer" O'Herren
//revisions can be found in revisions.txt

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "HeapADT.h"
#include "test_HeapADT.c"

typedef struct Heap_S
{
	size_t capacity;
	int(*compFun)(const void * lhs, const void * rhs);
	void(*dumpEntry)(const void * item, FILE * outfp);
	int size;
	void ** contents;
} * Heap;




Heap createHeap(size_t capacity, int(*compFun)(const void *lhs, const void *rhs), void(*dumpEntry)(const void *item, FILE *outfp))
{
	printf("stuff\n");
	
	Heap heap=malloc(sizeof(struct Heap_S));

	//heap.capacity = malloc(sizeof(size_t));
	heap->capacity = capacity;
	heap->compFun = compFun;
	heap->dumpEntry = dumpEntry;
	//heap.size = malloc(sizeof(int));
	heap->size = 0;
	heap->contents=(void**)malloc(sizeof(void**)*capacity);

	return heap;
}

void destroyHeap(Heap aHeap)
{
	free(aHeap->contents);
	free(aHeap);
}

size_t sizeHeap(Heap aHeap)
{
	return aHeap->size;
}

const void * topHeap(const Heap aHeap)
{
	return (aHeap->contents[0]);
}

void * removeTopHeap(Heap aHeap)
{

	void* val = aHeap->contents[0];

	aHeap->size=aHeap->size-1;

	for (int i = 0; i < aHeap->size; i++) {
		aHeap->contents[i] = aHeap->contents[i + 1];
	}

	return val;
}

void insertHeapItem(Heap aHeap, const void * item)
{
	if (aHeap->capacity == aHeap->size)
		return;

	void* i = (void*)item;
	//aHeap->contents[aHeap->size] = malloc(sizeof(void*));
	(aHeap->contents)[aHeap->size++] = i;

	int x = aHeap->size - 1;

	if(x!=0)
	while (x!=0&& (*aHeap->compFun)((void*)aHeap->contents[x], (void*)aHeap->contents[parent(x)])>0)
	{
		
		swapContents(aHeap,x);

		x = parent(x);

		if(x==0)
			break;

	}
}

void dumpHeap(Heap aHeap, FILE * outfp)
{
	for (int i = 0; i < aHeap->size; i++) {
		aHeap->dumpEntry(aHeap->contents[i], outfp);
	}
}

int parent(int index) {
	return (index - 1) / 2;
}

void swapContents(Heap aHeap,int index) {
	void* holder = (aHeap->contents[index]);

	aHeap->contents[index] = aHeap->contents[parent(index)];

	aHeap->contents[parent(index)] = (void*)holder;
}
