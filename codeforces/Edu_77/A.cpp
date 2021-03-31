#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++){
        ll c, sum;
        cin >> c >> sum;
        ll q = (sum/c);
        ll r = (sum % c);
        ll ans = r*(q + 1)*(q + 1) + (c - r)*q*q;
        cout << ans << '\n';
    }
    return 0;
}