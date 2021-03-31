#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const  ll Mod = (ll)(1e9) + 7;

void solve(){
    int n;
    cin >> n;
    multiset<int> mset;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        mset.insert(x);
    }

    int max_ai = *prev(mset.end());
    if (mset.count(max_ai) > 1){
        cout << 0 << '\n';
        return;
    }
    int cnt = 0;
    for (auto x: mset){
       int set_cnt = mset.count(x);
       if (set_cnt > 2){
          cout << 0 << '\n';
          return;
       }
       if (set_cnt == 1) cnt++;

    }

    // remove cnt max_ai;
    cnt--;
    int ans = 1;
    for (int i = 0; i < cnt; i++) ans = (ans*2) % Mod;
    cout << ans << '\n';



}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
