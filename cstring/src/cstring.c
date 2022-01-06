#include <stdlib.h>
#include "../include/cstring.h"

cstring* __cstr_create(char* str, int len) {
	// alloc mem for cstr struct and it's char array
	cstring* cstr = malloc(sizeof(cstring));
	cstr->arr = malloc(sizeof(char)*len + 1);

	// set length
	cstr->len = len;

	// deepcopy str to cstr.arr
	for (int i = 0; i < len; i++)
		cstr->arr[i] = str[i];

	// add null-terminator
	cstr->arr[len+1] = '\0';

	return cstr;
}

void __cstr_destroy(cstring* cstr) {
	free(cstr->arr);
	free(cstr);
}

cstring* __cstr_copy(cstring* cstr) {
	return __cstr_create(cstr->arr, cstr->len);
}

cstring* __cstr_join(cstring* cstr1, cstring* cstr2) {
	cstring* joined = malloc(sizeof(cstring));
	joined->arr = malloc(sizeof(char) * (cstr1->len + cstr2->len));
	joined->len = cstr1->len + cstr2->len;

	int j = 0;
	for (int i = 0; i < cstr1->len; i++)
		joined->arr[j++] = cstr1->arr[i];
	for (int i = 0; i < cstr2->len; i++)
		joined->arr[j++] = cstr2->arr[i];
	joined->arr[j] = '\0';

	return joined;
}

cstring_interface cString = {
	.create = __cstr_create,
	.destroy = __cstr_destroy,
	.copy = __cstr_copy,
	.join = __cstr_join
};
