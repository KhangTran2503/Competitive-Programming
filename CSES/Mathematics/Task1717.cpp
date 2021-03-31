// Number of Rearrangement
// Link: https://en.wikipedia.org/wiki/Derangement
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll Mod = (ll)(1e9) + 7;
int n;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    vector<ll> D(n + 1);
    
    D[1] = 0;
    D[2] = 1;
    for (int i = 3; i <= n; i++){
        D[i] = ((i - 1)*(D[i - 1] + D[i - 2])) % Mod;
    }
    cout << D[n];
    return 0;
}
