#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll Mod = (ll)(1e9) + 7;
typedef vector<vector<ll>> matrix;
matrix A;
int n;
ll K;


matrix operator * (matrix u,matrix v){
    matrix c;
    int n = u.size();
    c.resize(n,vector<ll> (n,0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                c[i][j] = (c[i][j] + (u[i][k]*v[k][j]) % Mod)% Mod;
    return c;            
}

matrix I(int n){
    matrix c(n,vector<ll> (n));
    for (int i = 0; i < n; i++) c[i][i] = 1;
    return c;
}

matrix powmatrix(const matrix&  x,ll y){
    matrix res = I(n);
    matrix u = x;
    while (y){
        if (y & 1) res = res * u;
        u = u * u;
        y >>= 1;
    }
    return res;

}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> K;
    A.resize(n,vector<ll> (n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> A[i][j];

    matrix Ans = powmatrix(A,K);
    ll ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) ans = (ans + Ans[i][j]) % Mod;

    cout << ans;    
    return 0;
}