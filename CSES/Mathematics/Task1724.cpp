#include <bits/stdc++.h>
using namespace std;
typedef long ll;
typedef vector<vector<ll>> matrix;
const ll Mod = (ll)(1e9) + 7;
const ll INF  = (ll)(4e18);
int n, m, k;

matrix I(int n){
    matrix I_n(n,vector<ll> (n,0LL));
    //for (int i = 0; i < n; i++) I_n[i][i] = 1;
    return I_n;
}

matrix operator *(const matrix& a,const matrix& b){
    assert(b.empty() == false);
    int n = a.size();
    int m = b[0].size();
    int p = b.size();
    matrix c(n,vector<ll> (m,INF));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int k = 0; k < p; k++)
                c[i][j] = min(c[i][j] ,a[i][k] + b[k][j]);
    return c;
    
}

matrix fastpow(matrix x,ll y){
    y--;
    matrix ans = x;
    while (y){
        if (y & 1) ans = ans*x;
        x = x*x;
        y >>= 1;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n >> m >> k;
    matrix adjacency_matrix(n,vector<ll> (n,INF));
    //for (int i = 0; i < n; i++) adjacency_matrix[i][i] = 0;

    for (int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        adjacency_matrix[a][b] = min(adjacency_matrix[a][b],(ll)c);
    }

    //cout << adjacency_matrix[0][n - 1] << '\n';
    matrix ans = fastpow(adjacency_matrix,k);
    if (ans[0][n - 1] == INF) cout << -1;
    else cout << ans[0][n - 1];
    return 0;
}
