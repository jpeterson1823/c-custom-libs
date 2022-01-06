#include <stdio.h>
#include "../include/cstring.h"

int main() {
	cstring* test = cString.create("test", 4);
	cstring* copy = cString.copy(test);
	cString.namedPrint(test, "test");
	cString.destroy(test);
	cString.namedPrint(copy, "copy");
	cString.destroy(copy);

	cstring* s1 = cString.create("String1", 7);
	cstring* s2 = cString.create("String2", 7);
	cstring* joined = cString.join(s1, s2);
	cString.destroy(s1);
	cString.destroy(s2);
	cString.namedPrint(joined, "joined");
	cString.destroy(joined);

	printf("Reusing pointers\n");
	cstring* s3 = cString.create("Delimited", 9);
	cstring* s4 = cString.create("String", 8);
	joined = cString.delimitedJoin(s3, s4, ' ');
	cString.destroy(s3);
	cString.destroy(s4);
	cString.print(joined);
	cString.destroy(joined);

	return 0;
}
