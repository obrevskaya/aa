#include "matrix.h"
#include <iostream>
#include <random>

void create_matrix(matrix_t* m, int n_r, int n_c)
{
    m->m = new int *[n_r];
    for (int i = 0; i < n_r; i++)
    {
        m->m[i] = new int[n_c];
        for (int j = 0; j < n_c; j++)
            m->m[i][j] = 0;
    }
    m->n_r = n_r;
    m->n_c = n_c;
}

void delete_matrix(matrix_t* m)
{
    for (int i = 0; i < m->n_r; i++)
        delete[] m->m[i];

    delete[] m->m;
}

void print_matrix(matrix_t m)
{
    for (int i = 0; i < m.n_r; i++) {
        for (int j = 0; j < m.n_c; j++)
            std::cout << m.m[i][j] << ' ';
        std::cout << '\n';
    }
}

void gen_matrix(matrix_t *m)
{
    m->m = new int *[m->n_r];
    for (int i = 0; i < m->n_r; i++)
        m->m[i] = new int[m->n_c];

    for (int i = 0; i < m->n_r; i++)
        for (int j = 0; j < m->n_c; j++)
        {
            m->m[i][j] = rand() % MAX_VALUE;
        }
}

void make_zero_matrix(matrix_t *m)
{
    for (int i = 0; i < m->n_r; i++)
        for (int j = 0; j < m->n_c; j++)
            m->m[i][j] = 0;
}