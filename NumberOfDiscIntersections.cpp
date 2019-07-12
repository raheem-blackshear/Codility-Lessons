#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> PLL;

vector <PLL> VPLL;

bool cmp (PLL A, PLL B) {
    if (A.second != B.second) return A.second < B.second;
    return A.first <= B.first;
}

int solution(vector<int> &A) {
    VPLL.clear();
    vector <ll> ed;
    ed.clear();

    int sz = A.size();
    if (sz < 2) return 0;

    for (int i = 0; i < sz; i ++) {
        VPLL.push_back(make_pair(i - 1ll*A[i], i + 1ll*A[i]));
    }
    sort(VPLL.begin(), VPLL.end(), cmp);

    int ans = 0;
    ed.push_back(VPLL[0].second);
    vector<ll>::iterator low;

    for (int i = 1; i < sz; i ++) {
        low = lower_bound (ed.begin(), ed.end(), VPLL[i].first);
        ans += i - (low - ed.begin());
        if (ans > 10000000) return -1;
        ed.push_back(VPLL[i].second);
    }
    return ans;
}

int main() {

    vector <int> A;
    A.clear();
    A.push_back(1);
    A.push_back(2147483647);
    A.push_back(0);

    printf ("%d\n", solution(A));
}
