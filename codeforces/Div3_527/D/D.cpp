#include<bits/stdc++.h>
using namespace std;
int n;

int main(){
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n;
    stack<int> st;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        if (!st.empty() && x%2 == st.top()) st.pop();
        else st.push(x&1);
    }
    if (st.size()<2) cout << "YES";
    else cout << "NO";
    return 0;
}
