#include "heap.h"

#include <math.h>
#include <time.h>

int main() {
	Heap* heap = createHeap(50);

	srand(time(NULL));

	for (int i = 1; i <= 10;++i)
	{
		HeapData data;
		data.priority = rand() % 20;
		printf("pushed %d\n", data.priority);
		pushHeapData(heap, data);
	}

	printHeap(heap);

	printf("poped %d\n heapified\n\n", popMaxData(heap).priority);
	printHeap(heap);

	printf("poped %d\n heapified\n\n", popMaxData(heap).priority);
	printHeap(heap);

	printf("poped %d\n heapified\n\n", popMaxData(heap).priority);
	printHeap(heap);

	printf("poped %d\n heapified\n\n", popMaxData(heap).priority);
	printHeap(heap);

	printf("poped %d\n heapified\n\n", popMaxData(heap).priority);
	printHeap(heap);

	printf("poped %d\n heapified\n\n", popMaxData(heap).priority);
	printHeap(heap);

	printf("poped %d\n heapified\n\n", popMaxData(heap).priority);
	printHeap(heap);

	printf("poped %d\n heapified\n\n", popMaxData(heap).priority);
	printHeap(heap);

	printf("poped %d\n heapified\n\n", popMaxData(heap).priority);
	printHeap(heap);
	
	printf("poped %d\n heapified\n\n", popMaxData(heap).priority);
	printHeap(heap);

	clearHeapdata(heap);
	printHeap(heap);


}