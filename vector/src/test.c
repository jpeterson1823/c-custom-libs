#include "../../matrix/include/matrix.h"
#include "../include/vector.h"

int main() {
    double a1[3] = {1, 2, 3};
    double a2[3] = {3, 2, 1};

    vector* v1 = vector_from_array(3, a1);
    vector* v2 = vector_from_array(3, a2);
    vector* v3 = vector_div(v1, v2);

    vector_print(v1);
    vector_print(v2);
    vector_print(v3);

    vector_del(v1);
    vector_del(v2);
    vector_del(v3);

    return 0;
}
