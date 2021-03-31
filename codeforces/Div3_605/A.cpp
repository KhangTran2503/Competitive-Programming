#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int q;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> q;
    while (q--){
        ll a, b ,c;
        cin >> a >> b >> c;
        ll ans = abs(a - b) + abs(a - c) + abs(c - b);
        for (ll _a = a - 1; _a <= a + 1; _a++)
            for (ll _b = b - 1; _b <= b + 1; _b++)
                for (ll _c = c - 1; _c <= c + 1; _c++)
                    ans = min(ans,1LL*abs(_a - _b) + 1LL*abs(_a - _c) + 1LL*abs(_b - _c));
        cout << ans << '\n';            
    }
    return 0;
}