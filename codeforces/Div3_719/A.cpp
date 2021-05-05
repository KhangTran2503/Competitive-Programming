#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<char> a(n);
    for (char &x: a) cin >> x;
    uni(a);
    vector<int> cnt(26);
    for (char x: a)
        if (++cnt[x - 'A'] > 1){
            cout << "NO\n";
            return;
        }
    cout << "YES\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
