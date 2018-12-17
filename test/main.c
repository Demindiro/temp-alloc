#include "temp-alloc.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main()
{
	temp_alloc_push(1024);
	temp_alloc_push(1024);
	temp_alloc_push(1024);
	temp_alloc_push(1024*1024);
	for (size_t i = 0; i < 100; i++) {
		char *ptrs[32];
		// PS: Mind the null terminator
		char str[] = "This is " "a string" " of exac" "tly 32 "; // "characters";
		for (size_t j = 0; j < 32; j++)
			ptrs[j] = temp_alloc(32);
		for (size_t j = 0; j < 32; j++)
			memcpy(ptrs[j], str, sizeof(str));
		for (size_t j = 0; j < 32; j++)
			printf("%2lu: %s\n", j, ptrs[j]);
		if (i == 50)
			temp_alloc_reset();
	}
	temp_alloc_pop();
	temp_alloc_pop();
	temp_alloc_pop();
	temp_alloc_pop();
}
