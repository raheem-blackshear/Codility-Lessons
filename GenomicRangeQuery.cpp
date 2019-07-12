#include <bits/stdc++.h>
using namespace std;

#define N 100100
#define min(a, b) ((a) > (b) ? (b) : (a))

const int maxV = N << 1;
const int inf = (1 << 30);

class RMQ_Tree {

private:
	int Min[maxV];
	int n;

public:
	void build(int *a, int m) {
		Min[n = m] = a[n];
		for (int i = 1; i <= n; i ++) Min[i + n] = a[i];
		for (int i = n - 1; i; i --) Min[i] = min(Min[i << 1], Min[i << 1 | 1]);
	}

	void update(int p, int v) {
		Min[p += n] = v;
		for (; p > 1; p >>= 1) Min[p >> 1] = min(Min[p], Min[p ^ 1]);
	}

	int queryValue(int p) { return Min[p + n]; }

	int queryMin(int l, int r) {
		l += n, r += n;
		int rlt = inf;
		for (; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1) {
			if (l & 1) rlt = min(rlt, Min[l]);
			if ((r & 1) == 0) rlt = min(rlt, Min[r]);
		}
		return rlt;
	}
} T;

int a[N];

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    vector <int> ans;
    ans.clear();

    int len = S.length();

    for (int i = 0; i < len; i ++) {
        if (S[i] == 'A') {
            a[i + 1] = 1;
        } else if (S[i] == 'C') {
            a[i + 1] = 2;
        } else if (S[i] == 'G') {
            a[i + 1] = 3;
        } else {
            a[i + 1] = 4;
        }
    }
    T.build(a, len);
    int query_cnt = P.size();
    for (int q = 0; q < query_cnt; q ++) {
        int l = min(P[q], Q[q]);
        int r = max(P[q], Q[q]);
        ans.push_back(T.queryMin(l + 1, r + 1));
    }
    return ans;
}

int main() {
    freopen ("1.in", "r", stdin);
    string S = "CAGCCTA";
    vector <int> P, Q;
    P.clear(); Q.clear();
    P.push_back(2);
    P.push_back(5);
    P.push_back(0);

    Q.push_back(4);
    Q.push_back(5);
    Q.push_back(6);

    vector <int> ans = solution(S, P, Q);
    for (int i = 0; i < ans.size(); i ++) {
        printf ("%d ", ans[i]);
    }
}
