#include <bits/stdc++.h>
using namespace std;

stack <int> st;

int solution(vector<int> &A, vector<int> &B) {
    while (!st.empty()) st.pop();
    int sz = A.size();
    st.push(0);
    for (int i = 1; i < sz; i ++) {
        if (B[st.top()] == B[i]) st.push(i);
        else {
            if (B[st.top()] == 0 && B[i] == 1) {
                st.push(i);
            } else if (!B[i]) {
                while (!st.empty() && B[st.top()] == 1 && A[st.top()] < A[i]) {
                    st.pop();
                }
                if (st.empty() || B[st.top()] == B[i]) st.push(i);
            }
        }
    }
    int ans = 0;
    while (!st.empty()) {
        st.pop(); ans ++;
    }
    return ans;
}
