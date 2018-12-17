src = src/*.c test/*.c
headers = -Iinclude

run:
	gcc $(src) $(headers) $(C_FLAGS) -o build/temp-alloc -Wall
	valgrind --leak-check=full ./build/temp-alloc
