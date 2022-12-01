#include "levenshtein.h"

#include <vector>
#include "matrix.h"

using namespace std;

int levenshtein_distance(const wstring *s1, const wstring *s2)
{
    int n = (*s1).length();
    int m = (*s2).length();
    if (n == 0)
        return m;
    if (m == 0)
        return n;
    int ans;
    n++;
    m++;

    matrix_t matrix;
    create_matrix(&matrix, n, m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i * j == 0)
                matrix[i][j] = i + j;
        }
    }
    bool turn = 0;
    for (int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            turn = (*s1)[i - 1] == (*s2)[j - 1] ? 0 : 1;
            matrix[i][j] = min(min(matrix[i - 1][j] + 1, matrix[i][j - 1] + 1), matrix[i - 1][j - 1] + turn);
        }
    }

    ans = matrix[n - 1][m - 1];
    delete_matrix(&matrix, n);
    return ans;
}

int damerau_levenshtein_matr_distance(const wstring *s1, const wstring *s2)
{
    int n = (*s1).length() + 1;
    int m = (*s2).length() + 1;
    if (n == 0)
        return m;
    if (m == 0)
        return n;
    int ans;
    n++;
    m++;

    matrix_t matrix;
    create_matrix(&matrix, n, m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i * j == 0)
                matrix[i][j] = i + j;
        }
    }
    bool turn = 0;
    for (int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            turn = (*s1)[i - 1] == (*s2)[j - 1] ? 0 : 1;
            if ((i > 1 && j > 1) && ((*s1)[i-1] == (*s2)[j-2] && (*s1)[i-2] == (*s2)[j-1]) && (turn == 1))
                matrix[i][j] = min(min(matrix[i - 1][j] + 1, matrix[i][j - 1] + 1), min(matrix[i - 1][j - 1] + turn, matrix[i - 2][j - 2] + 1));
            else
                matrix[i][j] = min(min(matrix[i - 1][j] + 1, matrix[i][j - 1] + 1), matrix[i - 1][j - 1] + turn);
        }
    }

    ans = matrix[n - 1][m - 1];
    delete_matrix(&matrix, n);
    return ans;
}

int damerau_levenshtein_rec_distance(const std::wstring *s1, int n, const std::wstring *s2, int m)
{
    if (n == 0)
        return m;
    if (m == 0)
        return n;

    int ans = damerau_levenshtein_rec_distance(s1, n - 1, s2, m) + 1;
    ans = min(ans, damerau_levenshtein_rec_distance(s1, n, s2,
                                                 m - 1) + 1);

    bool t = (*s1)[n - 1] == (*s2)[m - 1] ? 0 : 1;
    int dist = damerau_levenshtein_rec_distance(s1, n - 1,
                                             s2, m - 1) + t;

    ans = min(ans, dist);
    if (n > 1 && m > 1)
        if ((*s1)[n - 2] == (*s2)[m - 1] && (*s1)[n - 1] == (*s2)[m - 2])
            dist = damerau_levenshtein_rec_distance(s1, n - 2,
                                                 s2, m - 2) + 1;
    ans = min(ans, dist);
    return ans;
}

int rec_cache(matrix_t *matrix, const wstring *s1, size_t i, const wstring *s2, size_t j)
{
    int dist1, dist2, dist3;
    int ans;

    if ((dist1 = (*matrix)[i][j - 1]) == -1)
        dist1 = rec_cache(matrix, s1, i, s2, j - 1);
    if ((dist2 = (*matrix)[i - 1][j]) == -1)
        dist2 = rec_cache(matrix, s1, i - 1, s2, j);
    if ((dist3 = (*matrix)[i - 1][j - 1]) == -1)
        dist3 = rec_cache(matrix, s1, i - 1, s2, j - 1);
    if((*s1)[i - 1] != (*s2)[j - 1])
        dist3++;
    dist1++;
    dist2++;
    ans = min(min(dist1, dist2), dist3);

    if (i > 1 && j > 1){
        if ((*s1)[i - 1] == (*s2)[j - 2] && (*s1)[i - 2] == (*s2)[j - 1])
            if ((dist1 = (*matrix)[i - 2][j - 2]) == -1)
                dist1 = rec_cache(matrix, s1, i - 2, s2, j - 2);
        dist1++;
    }
    ans = min(ans, dist1);

    (*matrix)[i][j] = ans;
    return ans;
}

int damerau_levenshtein_rec_cache_distance(const std::wstring *s1, int n, const std::wstring *s2, int m)
{
    if (n == 0)
        return m;
    if (m == 0)
        return n;

    matrix_t matrix;
    create_matrix(&matrix, n + 1, m + 1);

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i * j == 0)
                matrix[i][j] = i + j;
            else
                matrix[i][j] = -1;
        }
    }

    int ans = rec_cache(&matrix, s1, n, s2, m);
    delete_matrix(&matrix, n + 1);
    return ans;
}
