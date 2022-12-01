#include "mul_alg.h"
#include <iostream>
void std_alg_mul(matrix_t *m1, matrix_t *m2, matrix_t *res){
    for (int i = 0; i < m1->n_r; i++)
        for (int j = 0; j < m2->n_c; j++)
            for (int k = 0; k < m1->n_c; k++)
                res->m[i][j] = res->m[i][j] + m1->m[i][k] * m2->m[k][j];
}


void winograd_alg_mul(matrix_t *m1, matrix_t *m2, matrix_t *res){
    int n_r1 = m1->n_r;
    int n_c1 = m1->n_c;
    int n_c2 = m2->n_c;
    int *mulh = new int [n_r1];
    int *mulv = new int [n_c2];

    for (int i = 0; i < n_r1; i++)
        for (int j = 0; j < n_c1 / 2; j++)
            mulh[i] = mulh[i] + m1->m[i][2 * j] * m1->m[i][2 * j + 1];

    for (int i = 0; i < n_c2; i++)
        for (int j = 0; j < n_c1 / 2; j++)
            mulv[i] = mulv[i] + m2->m[2 * j][i] * m2->m[2 * j + 1][i];

    for (int i = 0; i < n_r1; i++)
        for (int j = 0; j < n_c2; j++)
        {
            res->m[i][j] = -mulh[i] - mulv[j];
            for (int k = 0; k < n_c1/2; k++)
                res->m[i][j] = res->m[i][j] +
                        (m1->m[i][2 * k] + m2->m[2 * k + 1][j]) * (m1->m[i][2 * k + 1] + m2->m[2 * k][j]);
        }
    if (n_c1 % 2 == 1)
        for (int i = 0; i < n_r1; i++)
            for (int j = 0; j < n_c2; j++)
                res->m[i][j] = res->m[i][j] + m1->m[i][n_c1 - 1] * m2->m[n_c1 - 1][j];

}

void optimized_winograd_alg_mul(matrix_t *m1, matrix_t *m2, matrix_t *res)
{
    int n_r1 = m1->n_r;
    int n_c1 = m1->n_c;
    int n_c2 = m2->n_c;
    int half_nc1 = n_c1 >> 1;
    int *mulh = new int [n_r1];
    int *mulv = new int [n_c2];
    int j_ind;

    for (int i = 0; i < n_r1; i++)
        for (int j = 0; j < half_nc1; j++)
        {
            j_ind = j << 1;
            mulh[i] += m1->m[i][j_ind] * m1->m[i][j_ind + 1];
        }

    for (int i = 0; i < n_c2; i++)
        for (int j = 0; j < half_nc1; j++)
        {
            j_ind = j << 1;
            mulv[i] += m2->m[j_ind][i] * m2->m[j_ind + 1][i];
        }

    for (int i = 0; i < n_r1; i++)
        for (int j = 0; j < n_c2; j++)
        {
            res->m[i][j] = -mulh[i] - mulv[j];
            for (int k = 0; k < half_nc1; k++)
            {
                j_ind = k << 1;
                res->m[i][j] += (m1->m[i][j_ind] + m2->m[j_ind + 1][j]) *
                                (m1->m[i][j_ind + 1] + m2->m[j_ind][j]);
            }
        }
    if (n_c1 % 2 == 1)
        for (int i = 0; i < n_r1; i++)
            for (int j = 0; j < n_c2; j++)
            {
                j_ind = n_c1 - 1;
                res->m[i][j] += m1->m[i][j_ind] * m2->m[j_ind][j];
            }

}
