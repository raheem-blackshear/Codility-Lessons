#include <bits/stdc++.h>
using namespace std;
#define MX 31

int f[32];
int str[40];

void prepare() {
    f[0] = 1;
    for (int i = 1; i < 31; i ++) f[i] = f[i - 1] * 2;
}

int solution(int N) {
    prepare();

    for (int i = 0; i < MX; i ++) {
        str[i] = (N & f[i]) ? 1 : 0;
    }

    int len = 0, cnt = 0, ans = 0, cur = -1;

    for (int i = 0; i < MX; i ++) if (str[i] == 1) len = i + 1;

    for (int l = 0; l < len; l ++) {
        if (str[l] == 1) {
            if (cur >= 0) ans = max(ans, cnt);
            cur = l;
            cnt = 0;
            continue;
        } else {
            cnt ++;
        }
    }
    return ans;
}

int main() {
    freopen("1.in", "r", stdin);
    int N;
    scanf("%d", &N);
    printf ("%d\n", solution(N));
}
