#include <stdio.h>
#include "../include/cstring.h"

int main() {
	cstring* test = cString.create("test", 4);
	printf("String: %s\n", test->arr);
	printf("Length: %i\n", test->len);
	cString.destroy(test);

	return 0;
}
