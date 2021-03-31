// O(nlogn) use IT +  binary search
//
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<int> c, numchild, ans;
vector<int> segtree;
int root, n;


void build(int id = 1,int l = 1,int r = n){
    if (l == r){
        segtree[id]++;
        return;
    }
    int mid = (l + r) >> 1;
    build(2*id,l,mid);
    build(2*id + 1,mid + 1,r);
    segtree[id] = segtree[2*id] + segtree[2*id + 1];
}

int get(int val,int id = 1,int l = 1,int r = n){
    if (l == r){
        segtree[id] = 0;
        return l;
    }
    int mid = (l + r) >> 1;
    int pos;
    if (val <= segtree[2*id]) pos = get(val,2*id,l,mid);
    else pos = get(val - segtree[2*id],2*id + 1,mid + 1,r);
    segtree[id] = segtree[2*id] + segtree[2*id + 1];
    return pos;
}

void dfs(int u){
    numchild[u] = 1;
    ans[u] = get(c[u] + 1);
    for (int v: g[u]){
        dfs(v);
        numchild[u] += numchild[v];
    }
    if (c[u] >= numchild[u]){
        cout << "NO";
        exit(0);
    }
}


int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    g.resize(n + 1);
    c.resize(n + 1);
    segtree.resize(4*n + 5);
    numchild.resize(n + 1);
    ans.resize(n + 1);

    for (int i = 1; i <= n; i++){
        int p;
        cin >> p >> c[i];
        if (!p) root = i;
        else g[p].emplace_back(i);
    }
    
    build();
    dfs(root);
    cout << "YES\n";
    for (int i = 1; i < ans.size(); i++) cout << ans[i] << ' ';
    return 0;
}