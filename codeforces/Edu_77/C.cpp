#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll r, b, k;
int T;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--){
        ll r, b, k;
        cin >> r >> b >> k;
        if (r > b) swap(r,b);
        ll g = __gcd(r,b); // pt nr - mb = x (x min) <=> x = gcd(r,b)
        if (g + r*(k - 1) < b) cout << "REBEL\n";
        else cout << "OBEY\n";
    }
    return 0;
}