#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<ll,int,int> tup;
vector<tup> edge;
vector<int> par;
vector<ll> Size;
int n, m;
ll ans = 0;
int findset(int p){ return (par[p] == p) ? p : par[p] = findset(par[p]);}

void Union(int u,int v,ll cost){
    int U = findset(u);
    int V = findset(v);
    if (U == V) return;
    ans += cost*(ll)Size[U]*(ll)Size[V];
    Size[U] += Size[V];
    par[V] = U;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    edge.resize(m);
    for (int i = 0; i < m; i++){
        int u, v; 
        cin >> u >> v;
        u--, v--;
        edge.emplace_back(make_tuple(min(a[u],a[v]),u,v));
    }
    sort(edge.rbegin(),edge.rend());
    par.resize(n);
    Size.resize(n);
    for (int i = 0; i < n; i++) par[i] = i, Size[i] = 1;
    for (int i = 0; i < m; i++){
        ll w;
        int u, v;
        tie(w,u,v) = edge[i];
        Union(u,v,w); 
    }
    
    ans *= 2LL;
    cout << ans;
    return 0;
}