#include <bits/stdc++.h>
using namespace std;
const int Maxn = int(1e5) + 5;
typedef long long ll;
vector<int> phi(Maxn);
vector<ll> ans(Maxn);
int T;

void ETF(){
    for (int i = 1; i < Maxn; i++) phi[i] = i;

    for (int i = 2; i < Maxn; i++)
        if (phi[i] == i){
            phi[i] = i - 1;
            for (int j = 2*i; j < Maxn; j += i) phi[j] -= phi[j]/i;
        }

    for (int i = 1; i < Maxn; i++) ans[i] = ans[i - 1] + (ll)(i - phi[i]);    
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> T;
    ETF();
    for (int i = 1; i <= T; i++){
        int n;
        cin >> n;
        cout << "Case " << i << ": " << ans[n] << '\n';
    }
    return 0;
}