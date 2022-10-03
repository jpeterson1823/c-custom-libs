#include "../../matrix/include/matrix.h"
#include "../include/vector.h"

int main() {
    vector* v1 = vector_new(3);
    vector_set(v1, 0, 3);
    vector_set(v1, 1, 2);
    vector_set(v1, 2, 1);

    vector* v2 = vector_new(3);
    vector_set(v2, 0, 1);
    vector_set(v2, 1, 2);
    vector_set(v2, 2, 3);

    vector* v3 = vector_div(v1, v2);

    vector_print(v1);
    vector_print(v2);
    vector_print(v3);

    vector_del(v1);
    vector_del(v2);
    vector_del(v3);

    return 0;
}
