#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef tuple<int,int,int> tup;
const int INF = int(1e9);
vector<vector<char>> Map;
vector<vector<int>> dis;
int dx[] = {0,0,-1,1},
    dy[] = {1,-1,0,0};
int n, m;
bool visit[500][500];
ii start, target;

// chat np + ki thuat dijsktra nhieu nguon

bool inside(int u,int v){
    return (u >= 0 && u < n && v >= 0 && v < m);
}

void calc_distance(){
    dis.resize(n, vector<int> (m,INF));
    priority_queue <tup, vector<tup> , greater<tup> > pq;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++)
            if (Map[i][j] == '+'){
                dis[i][j] = 0;
                pq.push(make_tuple(0,i,j));
            }

    while (!pq.empty()){
        int duv,u,v;
        tie(duv,u,v) = pq.top();
        pq.pop();
        if (duv != dis[u][v]) continue;
        for (int dir = 0; dir < 4; dir++){
            int uu = u + dx[dir],
                vv = v + dy[dir];
            if (inside(uu,vv) && duv + 1 < dis[uu][vv]){
                dis[uu][vv] = duv + 1;
                pq.push(make_tuple(duv + 1,uu,vv));
            }    
        }
    }        
}

bool can_go(int u,int v,int w){
    return inside(u,v) && (dis[u][v] >= w) && !visit[u][v];
}


bool dfs(int u,int v,int mid){
    
    if (!can_go(u,v,mid)) return false;
    visit[u][v] = 1;
    if (ii(u,v) == target) return true;
    bool ok = false;
    for (int dir = 0; dir < 4; dir++)
        if (can_go(u + dx[dir],v + dy[dir],mid)) ok |= dfs(u + dx[dir],v + dy[dir],mid);  
    return ok;
}
bool go(int mid){
    memset(visit,0,sizeof(visit));
    return dfs(start.first,start.second,mid);
}


int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    Map.resize(n, vector<char> (m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> Map[i][j];
            if (Map[i][j] == 'V') start = ii(i,j);
            if (Map[i][j] == 'J') target = ii(i,j);
        }    

    calc_distance();

    int lef = 0, rig = n + m;
    int ans;
    while (lef <= rig){
        int mid = (lef + rig) >> 1;
        if (go(mid)){
            ans = mid;
            lef = mid + 1;
        }
        else rig = mid - 1;
    }
    cout << ans;
    
    return 0;
}