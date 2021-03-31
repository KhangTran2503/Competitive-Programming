#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
const int Maxn = 2*int(1e5) + 5;
vector<int> g[Maxn];
int d[Maxn];
int n;
// graph 
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    memset(d,-1,sizeof(d));


    queue<int> q;

    for (int i = 1; i <= n; i++){
        int pre = i - a[i];
        int next = i + a[i];
        if (pre >= 1){
            g[pre].emplace_back(i);
            if ((a[i] + a[pre]) & 1){
                d[i] = 1;
                q.push(i);
            }            
        }
        if (next <= n){
            g[next].emplace_back(i);
            if ((a[i] + a[next]) & 1){
                d[i] = 1;
                q.push(i);
            }       
        }
    }

    while (!q.empty()){
        int u = q.front();
        //int type = q.front().first;
        q.pop();
        for (int v: g[u])
            if (d[v] == -1) {
                d[v] = d[u] + 1;
                q.push(v);
            }
    }

    for (int i = 1; i <= n; i++) cout << d[i] << ' ';
    return 0;
}