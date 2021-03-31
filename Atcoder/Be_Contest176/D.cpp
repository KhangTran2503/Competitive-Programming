/*********************************   
 *   @author: I_Love_Thuy_Linh   *
 *                               *
 *   0-1 BFS                     *
 ********************************/
#include <bits/stdc++.h>
using namespace std;
const int INF = int(1e9);
int H, W;
int Ch,Cw,Dh,Dw;
vector<vector<char>> S;
int dx[] = {0,0,-1,1},
    dy[] = {-1,1,0,0};

// 0-1 BFS, because weight's graph is 0 - 1 

int inside(int u,int v){
    return (u >= 0 && v >= 0 && u < H && v < W && S[u][v] == '.');
}

int BFS(int su,int sv){
    vector<vector<int>> dis(H,vector<int> (W,INF));
    deque<pair<int,int>> dq;

    dis[su][sv] = 0;
    dq.push_front(make_pair(su,sv));
    while (!dq.empty()){
        pair<int,int> u = dq.front();
        dq.pop_front();
        //cout << u.first << ' ' << u.second << ' ' << dis[u.first][u.second] << '\n';
        if (u == make_pair(Cw,Dw)) return dis[Cw][Dw];

        // Weight = 0
        for (int k = 0; k < 4; k++){
            int vx = u.first + dx[k];
            int vy = u.second + dy[k];
            if (inside(vx,vy) && dis[u.first][u.second] < dis[vx][vy]){
                dis[vx][vy] = dis[u.first][u.second];
                dq.push_front(make_pair(vx,vy));
            }
        }

        // Weight = 1
        for (int r = -2; r <= 2; r++)
            for (int c = -2; c <= 2; c++)
                if (!(r == 0 && c == 0)){
                    int vx = u.first + r;
                    int vy = u.second + c;
                    if (inside(vx,vy) && dis[u.first][u.second]  + 1 < dis[vx][vy]){
                        dis[vx][vy] = 1 + dis[u.first][u.second];
                        dq.push_back(make_pair(vx,vy));
                    }
                }
    }


    return -1;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> H >> W;
    cin >> Ch >> Dh;
    cin >> Cw >> Dw;
    Ch--, Dh--;
    Cw--, Dw--;

    S.assign(H,vector<char> (W,'.'));
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++) cin >> S[i][j];

    
    cout << BFS(Ch,Dh);    
    return 0;
}
