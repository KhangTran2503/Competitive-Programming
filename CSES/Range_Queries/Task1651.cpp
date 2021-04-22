#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, q;

struct SegTree{
    private:
        int size;
        vector<ll> tree;
        vector<ll> lazy;
        vector<int> lo;
        vector<int> hi;
        vector<ll> data;
        void __build(int l,int r,int id = 1){
            this->lo[id] = l;
            this->hi[id] = r;
            if (l == r){
                this->tree[id] = this->data[l - 1];
                return;
            }
            int mid = (l + r) >> 1;
            this->__build(l,mid,id << 1);
            this->__build(mid + 1,r, (id << 1) + 1);
            this->tree[id] = this->tree[id << 1] + this->tree[(id << 1)|1];
        }

        void __down(int id){
            if (lazy[id] == 0) return;
            tree[id] += (ll)lazy[id]*(hi[id] - lo[id] + 1);
            if (lo[id] != hi[id]){
                lazy[id << 1] += lazy[id];
                lazy[(id << 1)|1] += lazy[id];
            }
            lazy[id] = 0;
        }
        
        void __update(int u,int v,int val,int id){
            this->__down(id);
            if (v < lo[id] || u > hi[id]) return;
            if (u <= lo[id] && hi[id] <= v){
                lazy[id] += val;
                this->__down(id);
                return;
            }
            this->__update(u,v,val,id << 1);
            this->__update(u,v,val,(id << 1)|1);
            this->tree[id] = this->tree[id << 1] + this->tree[(id << 1)|1];
        }

        ll __get(int u,int v,int id){
            this->__down(id);
            if (v < lo[id] || u > hi[id]) return 0;
            if (u <= lo[id] && hi[id] <= v) return this->tree[id];
            return this->__get(u,v,id << 1) + this->__get(u,v,(id << 1)|1);
        }
    public:
        SegTree(vector<ll> x){
            this->size = x.size();
            this->data = static_cast<vector<ll>>(x);
            (this->tree).resize(4*this->size + 10);
            (this->lo).resize(4*this->size + 10);
            (this->hi).resize(4*this->size + 10);
            (this->lazy).assign(4*this->size + 10,0LL);
            this->__build(1,n);
        }
        void update(int u,int v,int val){
            this->__update(u,v,val,1);
        }
        
        ll get(int u,int v){
            return this->__get(u,v,1);
        }

        ll get(int u){
            return this->__get(u,u,1);
        }

};




int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    
    vector<ll> a(n);
    for (ll &x: a) cin >> x;

    SegTree ST(a);
    while (q--){
        int type;
        cin >> type;
        if (type == 2){
            int k;
            cin >> k;
            cout << ST.get(k) << '\n';
        }
        else {
            int u, v , val;
            cin >> u >> v >> val;
            ST.update(u,v,val);
        }
    }
    return 0;
}
