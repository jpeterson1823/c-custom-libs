#include <stdio.h>
#include <stdlib.h>
#include "../include/matrix.h"

matrix* matrix_new(u_short width, u_short height) {
    matrix* m = (matrix*)malloc(sizeof(matrix));
    m->width = width;
    m->height = height;
    m->array = (double*)calloc(width * height, sizeof(double));
    return m;
}

matrix* matrix_from_array(u_short width, u_short height, double* array) {
    matrix* m = matrix_new(width, height);
    for (u_short row = 0; row < height; row++) {
        for (u_short col = 0; col < width; col++) {
            matrix_set(m, row, col, array[(row * width) + col]);
        }
    }
    return m;
}

matrix* matrix_copy(matrix* m) {
    matrix* c = matrix_new(m->width, m->height);
    for (ushort row = 0; row < m->height; row++)
        for (ushort col = 0; col < m->width; col++)
            matrix_set(c, row, col, matrix_get(m, row, col));
    return c;
}

void matrix_del(matrix* m) {
    free(m->array);
    free(m);
    m = NULL;
}

double matrix_get(matrix* m, u_short row, u_short col) {
    if (row < m->height && col < m->width)
        return m->array[(row * m->width) + col];
    else {
        fprintf(stderr, "[MATRIX.ERROR] Attempted to access element outside of bounds for index (%d,%d)", row, col);
        exit(1);
    }
}

void matrix_set(matrix* m, u_short row, u_short col, double val) {
    if (row < m->height && col < m->width)
        m->array[(row * m->width) + col] = val;
}

void matrix_print(matrix* m) {
    u_short row, col;
    printf("\n");
    for (row = 0; row < m->height; row++) {
        printf("|  ");
        for (col = 0; col < m->width-1; col++)
            printf("%f \t ", matrix_get(m, row, col));
        printf("%f  |\n", matrix_get(m, row, m->width-1));
    }
    printf("\n");
}

void matrix_fill(matrix* m, double val) {
    u_short row, col;
    for (row = 0; row < m->height; row++)
        for (col = 0; col < m->width; col++)
            matrix_set(m, row, col, val);
}

void matrix_scale(matrix* m, double scalar) {
    for (ushort row = 0; row < m->height; row++)
        for (ushort col = 0; col < m->width; col++)
            matrix_set(m, row, col, scalar * matrix_get(m, row, col));
}

double matrix_determinant(matrix* m) {
    // make sure matrix is square
    if (!__matrix_is_square(m)) {
        fprintf(stderr, "[MATRIX.WARN] Attempted to find determinant of rectangular matrix of width %i and height %i!", m->width, m->height);
        return 0.0;
    }

    // make sure matrix is no bigger than 3x3
    if (m->width > 3 || m->height > 3) {
        fprintf(stderr, "[MATRIX.WARN] Attempted to find determinant of matrix with dimensions %ix%i, which is bigger than 3x3!", m->width, m->height);
        return 0.0;
    }

    // if 1x1, determinant is 0
    if (m->width == 1 && m->height == 1) {
        return 0.0;
    }
    
    // if 2x2, determinant is mini-cross prod
    else if (m->width == 2 && m->height == 2) {
        return matrix_get(m, 0, 0) * matrix_get(m, 1, 1) - matrix_get(m, 1, 0) * matrix_get(m, 0, 1);
    }

    // otherwise, it gets complicated...
    else {
        double determinant = 0;
        double sign = 1.0;
        double scalar;
        matrix* subm;

        // loop through each column
        for (ushort col = 0; col < m->width; col++) {
            // get scalar for submatrix
            scalar = matrix_get(m, 0, col);

            // create submatrix
            subm = matrix_new(m->width-1, m->height-1);
            for (ushort r = 1; r < m->height; r++) {
                // copy all values in columns before 'col'
                for (ushort c = 0; c < col; c++) {
                    matrix_set(subm, r-1, c, matrix_get(m, r, c));
                }
                // copy all values in columns after 'col'
                for (ushort c = col+1; c < m->width; c++) {
                    matrix_set(subm, r-1, c-1, matrix_get(m, r, c));
                }
            }

            // calculate "mini-cross product" thing
            double b = matrix_get(subm, 0, 0)*matrix_get(subm, 1, 1) - matrix_get(subm, 0, 1)*matrix_get(subm, 1, 0);
            // add to determinant
            determinant += sign * scalar * b;
            // update sign
            sign *= -1.0;

            // free submatrix
            matrix_del(subm);
        }

        return determinant;
    }
}

matrix* matrix_add(matrix* a, matrix* b) {
    // check to make sure matrix dimension are the same
    if (__matrix_same_dimensions(a, b)) {
        // create sum matrix
        matrix* sum = matrix_new(a->width, b->height);

        // sum elements and save to sum matrix
        u_short i, j;
        int s;
        for (i = 0; i < a->height; i++) {
            for (j = 0; j < b->width; j++) {
                s = matrix_get(a, i, j) + matrix_get(b, i, j);
                matrix_set(sum, i, j, s);
            }
        }
        return sum;
    }
    else {
        fprintf(stderr, "[MATRIX.WARN] Attempted to add matrices of differing dimensions! ");
        return NULL;
    }
}

matrix* matrix_sub(matrix* a, matrix* b) {
    // check dimensions
    if (__matrix_same_dimensions(a, b)) {
        // create difference matrix
        matrix* difference = matrix_new(a->width, b->height);

        // subtract elements and save to product matrix
        u_short i, j;
        int d;
        for (i = 0; i < a->height; i++) {
            for (j = 0; j < b->width; j++) {
                d = matrix_get(a, i, j) - matrix_get(b, i, j);
                matrix_set(difference, i, j, d);
            }
        }
        return difference;
    }
    else {
        fprintf(stderr, "[MATRIX.WARN] Attempted to subtract matrices of differing dimensions! ");
        return NULL;
    }
}

matrix* matrix_mul(matrix* a, matrix* b) {
    // check dimensions
    if (__matrix_same_dimensions(a, b)) {
        // create product matrix
        matrix* product = matrix_new(a->width, b->height);

        u_short i, j;
        int p;
        for (i = 0; i < a->height; i++) {
            for (j = 0; j < a->height; j++) {
                p = matrix_get(a, i, j) * matrix_get(b, i, j);
                matrix_set(product, i, j, p);
            }
        }
        return product;
    }
    else {
        fprintf(stderr, "[MATRIX.WARN] Attempted to multiply matrices of differing dimensions! ");
        return NULL;
    }
}

matrix* matrix_div(matrix* a, matrix* b) {
    // check dimensions
    if (__matrix_same_dimensions(a, b)) {
        // create quotient matrix
        matrix* quotient = matrix_new(a->width, b->height);

        u_short i, j;
        int q;
        for (i = 0; i < a->height; i++) {
            for (j = 0; j < a->height; j++) {
                q = matrix_get(a, i, j) / matrix_get(b, i, j);
                matrix_set(quotient, i, j, q);
            }
        }
        return quotient;
    }
    else {
        fprintf(stderr, "[MATRIX.WARN] Attempted to divide matrices of differing dimensions! ");
        return NULL;
    }
}
