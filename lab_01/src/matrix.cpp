#include "matrix.h"
#include <random>

void create_matrix(matrix_t* m, int n_r, int n_c)
{
    (*m) = new int *[n_r];
    for (int i = 0; i < n_r; i++) {
        (*m)[i] = new int[n_c];
        for (int j = 0; j < n_c; j++)
            (*m)[i][j] = 0;
    }
}

void delete_matrix(matrix_t* m, int n_r)
{
    for (int i = 0; i < n_r; i++)
        delete[] (*m)[i];

    delete[] (*m);
}
