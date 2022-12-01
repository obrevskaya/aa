#ifndef _MATRIX_H
#define _MATRIX_H

typedef int** matrix_t;

void create_matrix(matrix_t* m, int n_r, int n_c);
void delete_matrix(matrix_t* m, int n_r);

#endif //LAB_02_MATRIX_H