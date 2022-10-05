#include "../include/matrix.h"

int __matrix_is_square(matrix* m) {
    return (double)m->width/(double)m->height == 1.0;
}

int __matrix_same_dimensions(matrix* a, matrix* b) {
    return a->height == b->height && a->width == b->width;
}
