#include <bits/stdc++.h>
using namespace std;
typedef long ll;
typedef vector<vector<ll>> matrix;
const ll Mod = (ll)(1e9) + 7;


matrix I(int n){
    matrix I_n(n,vector<ll> (n,0));
    for (int i = 0; i < n; i++) I_n[i][i] = 1;
    return I_n;
}

matrix operator *(const matrix& a,const matrix& b){
    assert(b.empty() == false);
    int n = a.size();
    int m = b[0].size();
    int p = b.size();
    matrix c(n,vector<ll> (m,0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int k = 0; k < p; k++)
                c[i][j] = (c[i][j] + (a[i][k]*b[k][j]) % Mod) % Mod;
    return c;
    
}

matrix fastpow(matrix x,ll y){
    matrix ans = I(6);
    while (y){
        if (y & 1) ans = ans*x;
        x = x*x;
        y >>= 1;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin >> n;

    if (n == 0) cout << 0;
    else {
        matrix a(6,vector<ll> (6,0));
        for (int i = 0; i < 5; i++) a[i][i + 1] = 1;
        for (int i = 0; i < 6; i++) a[5][i] = 1;

        matrix ans = fastpow(a,n);
        cout << ans[5][5];
    }
    return 0;
}
