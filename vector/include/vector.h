#ifndef __VECTOR
#define __VECTOR

#include "../../matrix/include/matrix.h"

typedef struct __VECTOR {
    u_short dimension;
    matrix* m;
} vector;

vector* vector_new(u_short dimension);
vector* vector_from_array(u_short dimension, double* array);
void    vector_del(vector* v);
void    vector_print(vector* v);
void    vector_set(vector* v, u_short element, double val);
double  vector_get(vector* v, u_short element);
double  vector_mag(vector* v);
vector* vector_add(vector* v1, vector* v2);
vector* vector_sub(vector* v1, vector* v2);
vector* vector_mul(vector* v1, vector* v2);
vector* vector_div(vector* v1, vector* v2);
vector* vector_dot(vector* v1, vector* v2);

#endif
