#ifndef __MATRIX
#define __MATRIX

typedef struct __MATRIX {
    unsigned short width;
    unsigned short height;
    double* array;
} matrix;

matrix* matrix_new(unsigned short width, unsigned short height);
void    matrix_del(matrix* m);
double  matrix_get_element(matrix* m, unsigned short row, unsigned short col);
void    matrix_set_element(matrix* m, unsigned short row, unsigned short col, double val);
void    matrix_print(matrix* m);
void    matrix_fill(matrix* m, double val);

#endif
