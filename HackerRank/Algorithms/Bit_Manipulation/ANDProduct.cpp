/*    2021-01-01    */
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;

void solve(){
    unsigned int ans = 0;
    unsigned int L, R;
    cin >> L >> R;
    for (int i = 31; i >= 0; i--){
        int bitL = (L >> i) & 1;
        int bitR = (R >> i) & 1;
        if (bitL != bitR) break;
        if (bitL) ans |= (1 << i);
    }
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
