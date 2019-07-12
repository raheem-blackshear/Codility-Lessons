#include <bits/stdc++.h>
using namespace std;
#define MX 100010

vector <int> tmp;
int id[MX];

bool cmp(int i, int j) {
    return tmp[i] < tmp[j];
}

int solution(vector<int> &A) {
    int sz = A.size();
    if (!sz) return -1;
    if (sz == 1) return 0;
    for (int i = 0; i < sz; i ++) tmp.push_back(A[i]);
    for (int i = 0; i < sz; i ++) id[i] = i;
    sort (id, id + sz, cmp);
    int cnt = 1, cur = A[id[0]];
    for (int i = 1; i < sz; i ++) {
        if (A[id[i]] != cur) {
            if (2 * cnt > sz) return id[i - 1];
            cur = A[id[i]], cnt = 1;
        } else {
            cnt ++;
            if (2 * cnt > sz) return id[i - 1];
        }
    }
    return -1;
}
