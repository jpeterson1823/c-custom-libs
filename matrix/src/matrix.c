#include <stdio.h>
#include <stdlib.h>
#include "../include/matrix.h"

matrix* matrix_new(unsigned short width, unsigned short height) {
    matrix* m = (matrix*)malloc(sizeof(matrix));
    m->width = width;
    m->height = height;
    m->array = (double*)calloc(width * height, sizeof(double));
    return m;
}

void matrix_del(matrix* m) {
    free(m->array);
    free(m);
    m = NULL;
}

double matrix_get_element(matrix* m, unsigned short row, unsigned short col) {
    if (row < m->height && col < m->width)
        return m->array[(row * m->width) + col];
    else {
        fprintf(stderr, "[MATRIX.ERROR] Attempted to access element outside of bounds for index (%d,%d)", row, col);
        exit(1);
    }
}

void matrix_set_element(matrix* m, unsigned short row, unsigned short col, double val) {
    if (row < m->height && col < m->width)
        m->array[(row * m->width) + col] = val;
}

void matrix_print(matrix* m) {
    for (unsigned short row = 0; row < m->height; row++) {
        printf("|  ");
        for (unsigned short col = 0; col < m->width-1; col++)
            printf("%f \t ", matrix_get_element(m, row, col));
        printf("%f  |\n", matrix_get_element(m, row, m->width-1));
    }
}

void matrix_fill(matrix* m, double val) {
    for (unsigned short row = 0; row < m->height; row++)
        for (unsigned short col = 0; col < m->width; col++)
            matrix_set_element(m, row, col, val);
}
