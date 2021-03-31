#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll X, ans1,ans2;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> X;
    for (ll u = 1; u*u <= X; u++)
        if (X % u == 0 && __gcd(u,X/u) == 1) ans1 = u, ans2 = X/u;
    
    cout << ans1 << ' ' << ans2;
    return 0;
}