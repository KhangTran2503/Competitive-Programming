#include <bits/stdc++.h>
using namespace std;
int T;
int n;

void solve(){
    cin >> n;
    vector<int> odd;
    vector<int> even;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        if (x & 1) odd.push_back(x);
        else even.push_back(x);
    }
    for (int x: odd) cout << x << ' ';
    for (int x: even) cout << x << ' ';
    cout << '\n';
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> T;
    while (T--) solve();
    return 0;
}
