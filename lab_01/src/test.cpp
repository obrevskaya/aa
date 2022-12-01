#include "test.h"
#include <string>
#include <time.h>
#include <iostream>
#include <fstream>
#include "levenshtein.h"

const int MAX_SIZE = 100;
using namespace std;
#define N 100

wstring generate_string(int len)
{
    srand(time(NULL));
    wstring str = L"";
    for (size_t i = 0; i < len; i++)
        str += char('a' + rand() % 26);

    return str;
}

void tests() {
    srand(time(NULL));
    clock_t start, end;
    wstring s1;
    wstring s2;

    int step = 1;


    for (int len = 1; len <= MAX_SIZE; len += step) {
        if (len == 20)
            step = 5;
        else if (len == 50)
            step = 10;

        int t1 = 0, t2 = 0, t3 = 0, t4 = 0;


        s1 = generate_string(len);
        s2 = generate_string(len);
        for (int i = 0; i < N; i++) {

            start = clock();
            levenshtein_distance(&s1,  &s2);
            end = clock();

            t1 += end - start;

            start = clock();
            damerau_levenshtein_matr_distance(&s1, &s2);
            end = clock();

            t2 += end - start;

            if (len < 10) {
                start = clock();
                damerau_levenshtein_rec_distance(&s1, s1.length(), &s2, s2.length());
                end = clock();

                t3 += end - start;
            } else
                t3 = 0;


                start = clock();
                damerau_levenshtein_rec_cache_distance(&s1, s1.length(), &s2, s2.length());
                end = clock();

                t4 += end - start;


        }

        cout << len << " " << t1 / N << " " << t2 / N << " " << t3 / N << " " << t4 / N << "\n";

    }
}