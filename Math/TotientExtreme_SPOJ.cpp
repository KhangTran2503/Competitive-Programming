#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MaxN = int(1e4) + 5;
vector<int> phi(MaxN);
vector<ll> sumphi(MaxN);
int T;

void ETF(){
    for (int i = 1; i < MaxN; i++) phi[i] = i;
    for  (int i = 2; i < MaxN; i++)
        if (phi[i] == i){
            phi[i] = i - 1;
            for (int j = 2*i; j < MaxN; j += i) phi[j] -= phi[j]/i;
        }

    for (int i = 1; i < MaxN; i++) sumphi[i] = sumphi[i - 1] + (ll)phi[i];    
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> T;
    ETF();
    while (T--){
        int n;
        cin >> n;
        ll ans = (ll)sumphi[n]*(ll)sumphi[n];
        cout << ans << '\n';
    }
    return 0;
}