#include <bits/stdc++.h>
using namespace std;
int a[20][20];
int d[20][20];
int n, m;
int dx[] = {0,0,-1,1},
    dy[] = {-1,1,0,0};


bool inside(int u,int v){
    return (u >= 0 && u < n && v >= 0 && v < m && !a[u][v]);
}

int bfs(int u,int v){
    memset(d,0,sizeof(d));
    queue<pair<int,int>> q;
    q.push(make_pair(u,v));
    d[u][v] = 1;
    while (!q.empty()){
        int ux = q.front().first;
        int vx = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++){
            int uy = ux + dx[k];
            int vy = vx + dy[k];
            if (inside(uy,vy) && !d[uy][vy]){
                d[uy][vy] = d[ux][vx] + 1;
                q.push(make_pair(uy,vy));
            } 
        }
    }

    int rs = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            rs = max(rs,d[i][j]);
    return rs - 1;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            char x;
            cin >> x;
            if (x == '.') a[i][j] = 0;
            else a[i][j] = 1;
        }

    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!a[i][j])
                ans = max(ans,bfs(i,j));
    cout << ans;
    return 0;
}