#include "../include/filemgr.h"
#include <stdio.h>

/**
 * @brief Reads the input character by character into a character array.
 *
 * @param path 			path to file
 * @param init_size		initial size of the char* buffer
 */
char* file_read(char* path, size_t init_size) {
	// open input file
	FILE* f;
	f = fopen(path, "r");
	if (f == NULL) {
		fprintf(stderr, "[ ERROR==>filemgr ] Failed to open file: '%s'\n", path);
		exit(EXIT_FAILURE);
	}

	// create string buffer
	char* str = malloc(sizeof(char) * init_size);

	// read file contents
	char ch;
	size_t size = init_size;
	int len = 0;
	while (EOF != (ch = fgetc(f))) {
		str[len++] = ch;
		// if out of room in buffer, realloc
		if (len == size)
			str = realloc(str, sizeof(char)*(size+=16));
	}
	// append null-terminator
	str[len++] = '\0';

	// close file pointer
	fclose(f);

	// realloc to remove excess alloc'd memory and return
	return str;
}
