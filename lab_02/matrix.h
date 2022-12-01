#ifndef LAB_02_MATRIX_H
#define LAB_02_MATRIX_H

#define MAX_VALUE 7

typedef struct
{
    int n_r = 0;
    int n_c = 0;
    int** m;
} matrix_t;

void create_matrix(matrix_t* m, int n_r, int n_c);
void delete_matrix(matrix_t* m);
void gen_matrix(matrix_t *m);
void print_matrix(matrix_t m);
void make_zero_matrix(matrix_t *m);

#endif //LAB_02_MATRIX_H
