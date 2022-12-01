#include <iostream>
#include <ctime>
#include <string>
#include <stdlib.h>

#include "levenshtein.h"
#include "test.h"

using namespace std;



int main() {
    setlocale(LC_ALL, "");

    #ifdef TEST
        tests();
        return 0;
    #endif
    int ans;
    wstring s1;
    wstring s2;
    clock_t start, end;

    cout << "Input string 1:" << endl;
    getline(wcin, s1);
    cout << "Input string 2:" << endl;
    getline(wcin, s2);

    cout << "\nLevenshtein distance:" << endl;
    start = clock();
    ans = levenshtein_distance(&s1, &s2);
    end = clock();
    cout<<"Answer: "<<ans<<endl;
    cout<<"Time: "<<end - start<<" ticks"<<endl;

    cout << "\nDamerau-Levenshtein distance:" << endl;
    start = clock();
    ans = damerau_levenshtein_matr_distance(&s1, &s2);
    end = clock();
    cout<<"Answer: "<<ans<<endl;
    cout<<"Time: "<<end - start<<" ticks"<<endl;

    cout << "\nDamerau-Levenshtein recursive distance:" << endl;
    start = clock();
    ans = damerau_levenshtein_rec_distance(&s1, s1.length(), &s2, s2.length());
    end = clock();
    cout<<"Answer: "<<ans<<endl;
    cout<<"Time: "<<end - start<<" ticks"<<endl;

    cout << "\nDamerau-Levenshtein recursive with cache distance:" << endl;
    start = clock();
    ans = damerau_levenshtein_rec_cache_distance(&s1, s1.length(), &s2, s2.length());
    end = clock();
    cout<<"Answer: "<<ans<<endl;
    cout<<"Time: "<<end - start<<" ticks"<<endl;


    return 0;
}

