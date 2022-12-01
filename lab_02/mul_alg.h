#ifndef LAB_02_MUL_ALG_H
#define LAB_02_MUL_ALG_H
#include "matrix.h"

void std_alg_mul(matrix_t *m1, matrix_t *m2, matrix_t *res);
void winograd_alg_mul(matrix_t *m1, matrix_t *m2, matrix_t *res);
void optimized_winograd_alg_mul(matrix_t *m1, matrix_t *m2, matrix_t *res);

#endif //LAB_02_MUL_ALG_H
