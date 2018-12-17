Temporary alloc
===============

This library is useful if you need to create a lot of temporary object that
cannot be allocated on the stack.

To allocate a frame, use `temp_alloc_push(size_t)`. You can then allocate memory
with `temp_alloc(size_t)`. If you need to free the memory again, you can use
`temp_alloc_pop(void)` to free all allocated memory.

You can push multiple frames at once. Doing so will preserve any allocations made
before the second push when calling pop.
