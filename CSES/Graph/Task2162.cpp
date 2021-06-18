#include <bits/stdc++.h>
using namespace std;
int vis[9][9];
int dx[] = {-2,-2,-1,-1,1,1,2,2},
    dy[] = {-1,1,-2,2,-2,2,-1,1};


bool is_feasible(int x,int y){
    return (x >= 1 && x <= 8 && y >= 1 && y <= 8);
}

int deg(int x,int y){
    int neigh = 0;
    for (int i = 0; i < 8; i++){
        int u = x + dx[i];
        int v = y + dy[i];
        if (is_feasible(u,v) && vis[u][v] == 0) neigh++;
    }
    return neigh;
}


bool dfs(int x,int y,int cnt){
    vis[x][y] = cnt;
    if (cnt == 64) return true;
    vector<pair<int,int>> dir;
   for (int i = 0; i < 8; i++){
        int u = x + dx[i];
        int v = y + dy[i];
        if (is_feasible(u,v) && vis[u][v] == 0){
            dir.push_back({deg(u,v),i});
        }
    }
    
    if (!dir.empty()){
        sort(dir.begin(),dir.end());
        for (pair<int,int> d: dir){
            int u = x + dx[d.second];
            int v = y + dy[d.second];
            if (dfs(u,v,cnt + 1)) return true;
        }
    }

    vis[x][y] = 0;
    return false;
}


int main(){

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(vis,0,sizeof(vis));
    int x, y;
    cin >> x >> y;
    dfs(y,x,1);
    
    for (int i = 1; i <= 8; i++){
        for (int j = 1; j <= 8; j++) cout << vis[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}
