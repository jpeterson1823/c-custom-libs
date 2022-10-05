#include <stdio.h>
#include <stdbool.h>
#include "../include/matrix.h"

void test_create_from_array();
void test_determinant();


int main() {
    //test_create_from_array();
    test_determinant();
    return 0;
}


void test_create_from_array() {
    double array[9] = {6, 1, 1, 4, -2, 5, 2, 8, 7};
    matrix* m = matrix_from_array(3, 3, (double*)array);
    matrix_print(m);
    matrix_del(m);
}

void test_determinant() {
    double array[9] = {6, 1, 1, 4, -2, 5, 2, 8, 7};
    matrix* m = matrix_from_array(3, 3, (double*)array);

    matrix_print(m);
    printf("Determinant: %f\n", matrix_determinant(m));

    matrix_del(m);
}
