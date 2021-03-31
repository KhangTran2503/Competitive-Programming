#include <bits/stdc++.h>
using namespace std;
vector<int> a,b ;
int n, m;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    a.resize(n);
    b.resize(n);
    for (int &i: a) cin >> i;
    for (int &i: b) cin >> i;
    sort(b.begin(),b.end());

    int ans = m;
    for (int i = 0; i < n; i++){
        int delta = (b[0] - a[i] >= 0) ? (b[0] - a[i]) : (b[0] - a[i] + m);
        vector<int> tmp = a;
        for (int &x: tmp) x = (x + delta) % m;
        sort(tmp.begin(),tmp.end());
        if (tmp == b) ans = min(ans,delta);
    }
    cout << ans;
    return 0;
}