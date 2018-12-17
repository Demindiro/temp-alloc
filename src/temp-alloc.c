#include "temp-alloc.h"
#include <stdlib.h>


static void  *frames    [226];
static size_t pointers  [256];
static size_t sizes     [256];
static size_t capacity = 256;
static size_t index    = -1;


int temp_alloc_push(size_t size)
{
	index++;
	if (capacity <= index) {
		index--;
		return -1;
	}
	void *ptr = malloc(size);
	if (ptr == NULL)
		return -1;
	frames  [index] = ptr;
	pointers[index] = 0;
	sizes   [index] = size;
	return 0;
}


int temp_alloc_pop(void)
{
	if (index == -1)
		return -1;
	free(frames[index]);
	index--;
	return 0;
}


int temp_alloc_reset(void)
{
	if (index == -1)
		return -1;
	pointers[index] = 0;
	return 0;
}


void *temp_alloc(size_t count)
{
	if (index == -1 || pointers[index] + count >= sizes[index])
		return NULL;

	// Aligned memory accesses are generally faster
	size_t align_offset = count % 8;
	if (align_offset > 0)
		count += 8 - align_offset;

	void *ptr = frames[index] + pointers[index];
	pointers[index] += count;
	return ptr;
}
