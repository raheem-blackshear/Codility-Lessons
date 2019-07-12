#include <bits/stdc++.h>
using namespace std;
#define MX 100010

const int INF = - (1 << 30);

vector <int> tmp;
int id[MX];

bool cmp(int i, int j) {
    return tmp[i] < tmp[j];
}

int solution(vector<int> &A) {
    int sz = A.size();
    if (sz == 1) return 0;
    if (sz == 2) {
        if (A[0] == A[1]) return 1;
        return 0;
    }
    for (int i = 0; i < sz; i ++) tmp.push_back(A[i]), id[i] = i;
    sort (id, id + sz, cmp);
    int cnt = 1, cur = A[id[0]];
    int leader_val = INF;
    for (int i = 1; i < sz; i ++) {
        if (A[id[i]] != cur) {
            if (2 * cnt > sz) leader_val = A[id[i - 1]];
            cur = A[id[i]], cnt = 1;
        } else {
            cnt ++;
            if (2 * cnt > sz) leader_val = A[id[i - 1]];
        }
    }
    if (leader_val == INF) return 0;

    cnt = 0;
    for (int i = 0; i < sz; i ++) if (A[i] == leader_val) cnt ++;
    int S = 0;
    int cur_cnt = 0, ans = 0;
    for (S = 0; S < sz - 1; S ++) {
        if (A[S] == leader_val) cur_cnt ++;
        if (cur_cnt * 2 > S + 1 && 2 * (cnt - cur_cnt) > (sz - S - 1)) ans ++;
    }
    return ans;
}
