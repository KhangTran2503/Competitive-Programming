#include <bits/stdc++.h>
using namespace std;
int dx[] = {0,0,1,1,1,-1,-1,-1},
    dy[] = {-1,1,-1,0,1,-1,0,1};
int n, sx, sy;

bool check(int ux,int uy,int vx,int vy,int zx,int zy){
    int d1 =  abs(ux - vx) + abs(uy - vy);
    int d2 = abs(vx - zx) + abs(vy - zy);
    int d3 = abs(ux - zx) + abs(uy - zy);
    return (d1 + d2 == d3);
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> sx >> sy;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
    
    int ans = 0;
    int ansx, ansy;
    for (int k = 0; k < 8; k++){
         int uu = sx + dx[k];
         int vv = sy + dy[k];
         int cnt = 0;
        for (int i = 0; i < n; i++)
            if (check(sx,sy,uu,vv,x[i],y[i])) cnt++;
        if (cnt > ans){
            ans = cnt;
            ansx = uu;
            ansy = vv;
        }   
    }    
    cout << ans << '\n';
    cout << ansx << ' ' << ansy;
    return 0;
}