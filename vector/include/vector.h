#ifndef __VECTOR
#define __VECTOR

#include "../../matrix/include/matrix.h"

typedef struct __VECTOR {
    unsigned short dimension;
    matrix* m;
} vector;

vector* vector_new(unsigned short dimension);
void    vector_del(vector* v);
void    vector_print(vector* v);
void    vector_set(vector* v, unsigned short element, double val);
double  vector_get(vector* v, unsigned short element);
double  vector_mag(vector* v);
vector* vector_add(vector* v1, vector* v2);
vector* vector_sub(vector* v1, vector* v2);
vector* vector_mul(vector* v1, vector* v2);
vector* vector_div(vector* v1, vector* v2);

#endif
