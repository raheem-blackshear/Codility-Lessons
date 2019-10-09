#include <bits/stdc++.h>
using namespace std;
typedef long long INT;
typedef __int64 INT64;

### Here is master branch ###

int solution(vector<int> &A) {
    int sz = A.size();
    if (sz < 3) return 0;
    sort (A.begin(), A.end());
    for (int i = 0; i < sz - 2; i ++) {
        if (A[i] > 0 && (INT)A[i] + (INT)A[i + 1] > (INT)A[i + 2]) return 1;
    }
    return 0;
}

### Here is master branch ###
