#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/vector.h"

vector* vector_new(unsigned short dimension) {
    vector* v = malloc(sizeof(vector));
    v->dimension = dimension;
    v->m = matrix_new(1, dimension);
    return v;
}

void vector_del(vector* v) {
    matrix_del(v->m);
    free(v);
    v = NULL;
}


void vector_print(vector* v) {
    printf("(");
    for (unsigned short i = 0; i < v->dimension; i++)
        printf("%f, ", matrix_get_element(v->m, i, 0));
    printf("\b\b)\n");
}

void vector_set(vector* v, unsigned short element, double val) {
    if (element  < v->dimension)
        matrix_set_element(v->m, element, 0, val);
}

double vector_get(vector* v, unsigned short element) {
    return matrix_get_element(v->m, element, 0);
}

double vector_mag(vector* v) {
    double square_sum = 0;
    for (unsigned short i = 0; i < v->dimension; i++)
        square_sum += pow(vector_get(v, i), 2);
    return sqrt(square_sum);
}

vector* vector_add(vector* v1, vector* v2) {
    if (v1->dimension == v2->dimension) {
        vector* v = vector_new(v1->dimension);
        for (unsigned short i = 0; i < v->dimension; i++)
            vector_set(v, i, vector_get(v1, i) + vector_get(v2, i));
        return v;
    } else {
        fprintf(stderr, "[VECTOR.ERROR] Attempted to add vectors of different dimensions\n");
        exit(1);
    }
}

vector* vector_sub(vector* v1, vector* v2) {
    if (v1->dimension == v2->dimension) {
        vector* v = vector_new(v1->dimension);
        for (unsigned short i = 0; i < v->dimension; i++)
            vector_set(v, i, vector_get(v1, i) - vector_get(v2, i));
        return v;
    } else {
        fprintf(stderr, "[VECTOR.ERROR] Attempted to subtract vectors of different dimensions\n");
        exit(1);
    }
}

vector* vector_mul(vector* v1, vector* v2) {
    if (v1->dimension == v2->dimension) {
        vector* v = vector_new(v1->dimension);
        for (unsigned short i = 0; i < v->dimension; i++)
            vector_set(v, i, vector_get(v1, i) * vector_get(v2, i));
        return v;
    } else {
        fprintf(stderr, "[VECTOR.ERROR] Attempted to multiply vectors of different dimensions\n");
        exit(1);
    }
}

vector* vector_div(vector* v1, vector* v2) {
    if (v1->dimension == v2->dimension) {
        vector* v = vector_new(v1->dimension);
        for (unsigned short i = 0; i < v->dimension; i++)
            vector_set(v, i, vector_get(v1, i) / vector_get(v2, i));
        return v;
    } else {
        fprintf(stderr, "[VECTOR.ERROR] Attempted to divide vectors of different dimensions\n");
        exit(1);
    }
}
