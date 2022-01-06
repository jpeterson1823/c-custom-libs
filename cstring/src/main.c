#include <stdio.h>
#include "../include/cstring.h"

int main() {
	printf("Creation, Copying, and Destruction\n");
	cstring* test = cString.create("test", 4);
	cstring* copy = cString.copy(test);
	cString.namedPrint(test, "test");
	cString.destroy(test);
	cString.namedPrint(copy, "copy");
	cString.destroy(copy);
	printf("\n");

	printf("Normal Join\n");
	cstring* s1 = cString.create("String1", 7);
	cstring* s2 = cString.create("String2", 7);
	cstring* joined = cString.join(s1, s2);
	cString.destroy(s1);
	cString.destroy(s2);
	cString.namedPrint(joined, "joined");
	cString.destroy(joined);
	printf("\n");

	printf("Delimited Join\n");
	s1 = cString.create("a", 1);
	s2 = cString.create("b", 1);
	joined = cString.delimitedJoin(s1, s2, ' ');
	cString.destroy(s1);
	cString.destroy(s2);
	cString.print(joined);
	cString.destroy(joined);
	printf("\n");

	printf("Substring\n");
	test = cString.create("SubThis", 7);
	s1 = cString.substr(test, 0, 3);
	s2 = cString.substr(test, 3, 7);
	cString.print(s1);
	cString.print(s2);
	cString.destroy(test);
	cString.destroy(s1);
	cString.destroy(s2);

	return 0;
}
