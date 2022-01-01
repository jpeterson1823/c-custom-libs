#include "../include/filemgr.h"
#include <stdio.h>

int main() {
	char* filedata = file_read("test.txt", 50);
	printf("%s\n", filedata);
	free(filedata);
	return 0;
}
