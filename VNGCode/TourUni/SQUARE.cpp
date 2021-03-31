#include <bits/stdc++.h>
using namespace std;
int a[1005][1005] = {0};
int zip[1005][1005] = {0};
int f[1005][1005] = {0};
int n, m, k;
int h,w;
 
int get(int u,int v){
    return f[u + k - 1][v + k - 1] + f[u - 1][v - 1] - f[u + k - 1][v - 1] - f[u - 1][v + k - 1];
}
 
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--){
        memset(f,0,sizeof(0));
        memset(a,0,sizeof(a));
        cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
            f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + a[i][j];
        }
       
    h = n - k + 1;
    w = m - k + 1;
    int ans = 0;
    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++)
            if (get(i,j) == 0) ans++;
    cout << ans << '\n';
   
             
   

    }
    return 0;
 
}