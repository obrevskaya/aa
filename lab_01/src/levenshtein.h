#ifndef LAB_01_LEVENSHTEIN_H
#define LAB_01_LEVENSHTEIN_H

#include <string>

int levenshtein_distance(const std::wstring *s1, const std::wstring *s2);
int damerau_levenshtein_matr_distance(const std::wstring *s1, const std::wstring *s2);
int damerau_levenshtein_rec_distance(const std::wstring *s1, int n, const std::wstring *s2, int m);
int damerau_levenshtein_rec_cache_distance(const std::wstring *s1, int n, const std::wstring *s2, int m);

#endif //LAB_01_LEVENSHTEIN_H