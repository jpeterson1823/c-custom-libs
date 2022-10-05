#ifndef __MATRIX
#define __MATRIX

typedef unsigned short u_short;

typedef struct __MATRIX {
    u_short width;
    u_short height;
    double* array;
} matrix;

matrix* matrix_new(u_short width, u_short height);
matrix* matrix_from_array(u_short width, u_short height, double* values, u_short length);
matrix* matrix_copy(matrix* m);
void    matrix_del(matrix* m);
double  matrix_get(matrix* m, u_short row, u_short col);
void    matrix_set(matrix* m, u_short row, u_short col, double val);
void    matrix_scale(matrix* a, double scalar);
void    matrix_print(matrix* m);
void    matrix_fill(matrix* m, double val);
matrix* matrix_submatrix(matrix* m, u_short xstart, u_short ystart, u_short xend, u_short yend);
double  matrix_determinant(matrix* m);
matrix* matrix_add(matrix* a, matrix* b);
matrix* matrix_sub(matrix* a, matrix* b);
matrix* matrix_mul(matrix* a, matrix* b);
matrix* matrix_div(matrix* a, matrix* b);

// "private" methods
int __matrix_is_square(matrix* m);
int __matrix_same_dimensions(matrix* a, matrix* b);

#endif
