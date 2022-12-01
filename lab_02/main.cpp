#include <iostream>
#include "matrix.h"
#include "mul_alg.h"

int main() {
    matrix_t m1, m2, res;

    std::cout << "Input count of rows and columns of matrix1" << std::endl;
    std::cin >> m1.n_r >> m1.n_c;
    std::cout << "Matrix 1:" << std::endl;
    gen_matrix(&m1);
    print_matrix(m1);

    std::cout << "Input count of rows and columns of matrix2" << std::endl;
    std::cin >> m2.n_r >> m2.n_c;
    std::cout << "Matrix 2:" << std::endl;
    gen_matrix(&m2);
    print_matrix(m2);

    if (m1.n_c != m2.n_r)
    {
        std::cout << "Incorrect matrix sizes for mul" << std::endl;
        return 1;
    }

    create_matrix(&res, m1.n_r, m2.n_c);

    std::cout << "Classic algorithm:" << std::endl;
    std_alg_mul(&m1, &m2, &res);
    print_matrix(res);

    make_zero_matrix(&res);
    std::cout << "Winograd algorithm:" << std::endl;
    winograd_alg_mul(&m1, &m2, &res);
    print_matrix(res);

    make_zero_matrix(&res);
    std::cout << "Optimized winograd algorithm:" << std::endl;
    optimized_winograd_alg_mul(&m1, &m2, &res);
    print_matrix(res);

    delete_matrix(&m1);
    delete_matrix(&m2);
    delete_matrix(&res);

    return 0;
}
