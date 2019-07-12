#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> &A) {
    sort (A.begin(), A.end());
    int len = A.size(), cnt = 1;

    for (int i = 1; i < len; i ++) {
        if (A[i] != A[i - 1]) {
            if (cnt & 1) return A[i - 1];
            cnt = 1;
        } else {
            cnt ++;
        }
    }
    return A[len - 1];
}
