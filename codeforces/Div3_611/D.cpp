// Ngao cho BFS 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
vector<int> ans;
map<int,int> visit;
ll res = 0;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;

    queue<int> q;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        visit[x] = 0;
        q.push(x);
    }

    while (!q.empty()){
        int u = q.front();
        q.pop();
        for (int delta = -1; delta <= 1; delta += 2){
            int v = u + delta;
            if (visit.find(v) == visit.end()){
                visit[v] = visit[u] + 1;
                ans.push_back(v);
                q.push(v);
                res += (ll)visit[v];
                if (ans.size() == m){
                    cout << res << '\n';
                    for (int x: ans) cout << x << ' ';
                    return 0;
                }
            }
        }
    }
    return 0;
}