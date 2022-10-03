#include <stdio.h>
#include <stdbool.h>
#include "../include/matrix.h"

void test_print();

int main() {
    test_print();
    return 0;
}

void test_print() {
    matrix* m = matrix_new(5, 5);
    matrix_fill(m, 1.2345);
    matrix_print(m);
    matrix_del(m);
}
