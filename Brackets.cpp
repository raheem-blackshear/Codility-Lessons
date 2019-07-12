#include <bits/stdc++.h>
using namespace std;

stack <int> st;

int solution(string &S) {
    while (!st.empty()) st.pop();
    int len = S.length();
    for (int i = 0; i < len; i ++) {
        if (S[i] == '{' || S[i] == '[' || S[i] == '(') {
            if (S[i] == '{') st.push(1);
            else if (S[i] == '[') st.push(2);
            else st.push(3);
        } else {
            if (st.empty()) return 0;
            int prev = st.top();
            if (S[i] == '}' && prev != 1) return 0;
            if (S[i] == ']' && prev != 2) return 0;
            if (S[i] == ')' && prev != 3) return 0;
            st.pop();
        }
    }
    if (!st.empty()) return 0;
    return 1;
}