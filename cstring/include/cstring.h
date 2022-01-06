#ifndef __CSTRING_H__
#define __CSTRING_H__

// Define cstring datatype
typedef struct _CSTRING cstring;

typedef struct _CSTRING_INTERFACE {
	cstring* (*create)(char* str, int len);
	void (*destroy)(cstring* cstr);
	cstring* (*copy)(cstring* __cstr);
	cstring* (*join)(cstring* cstr1, cstring* cstr2);
} cstring_interface;

struct _CSTRING {
	char* arr;
	int len;
};

extern cstring_interface cString;

#endif
