#include <bits/stdc++.h>
using namespace std;
vector<int> segtree;
int n, x1, x2;

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

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> x1 >> x2;
    segtree.resize(4*n + 5);
    build();
    cout << get(x1) << ' ' << get(x2);
    return 0;
}