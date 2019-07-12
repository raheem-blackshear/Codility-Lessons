#include <bits/stdc++.h>
using namespace std;

stack <int> st;

int solution(vector<int> &H) {
    while (!st.empty()) st.pop();

    int sz = H.size();
    st.push(0);
    int ans = 0;
    for (int i = 1; i < sz; i ++) {
        if (H[st.top()] < H[i]){
            st.push(i);
        }
        else if (H[st.top()] == H[i]) continue;
        else {
            while (!st.empty() && H[st.top()] > H[i]) {
                ans ++, st.pop();
            }
            if (st.empty() || H[st.top()] < H[i]){
                st.push(i);
            }
        }
    }
    while (!st.empty()){
        st.pop(), ans ++;
    }
    return ans;
}
