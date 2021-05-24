#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<double>> matrix;

int n, m;

matrix operator*(const matrix& a,const matrix& b){
    matrix c(a.size(),vector<double> (b[0].size()));
    int n = a.size();
    int m = b[0].size();
    int p = b.size();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < p; k++) c[i][j] += a[i][k]*b[k][j];
    return c;
}

matrix I(int n){
    matrix a(n,vector<double> (n,0));
    for (int i = 0; i < n; i++) a[i][i] = 1;
    return a;
}

matrix fast_pow(matrix x,int y){
    matrix ans = I(n);
    while (y){
        if (y & 1) ans = ans*x;
        x = x*x;
        y >>= 1;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    matrix base(n,vector<double> (n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> base[i][j];
    
    matrix ans = fast_pow(base,m);
    for (int i = 0; i < n; i++) cout << ans[0][i] << '\n';
    return 0;
}
