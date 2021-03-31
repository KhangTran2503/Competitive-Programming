#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    stack<int> st;
    ll ans = 0;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        ans += (ll)st.size();
        while (!st.empty() && x > st.top()) st.pop();
        st.push(x);
    }
    cout << ans;
    return 0;
}
