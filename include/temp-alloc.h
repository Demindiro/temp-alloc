#ifndef TEMP_ALLOC__
#define TEMP_ALLOC__

#include "stddef.h"


int temp_alloc_push(size_t size);

int temp_alloc_pop(void);

int temp_alloc_reset(void);

void *temp_alloc(size_t count);


#endif
