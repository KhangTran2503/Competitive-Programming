#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
using namespace std;
const int Maxn = int(1e6);

struct UnionFind{
    private:
        vector<int> par, rank;
        int size;
    public:
        UnionFind(int n_size){
            this->size = n_size;
            (this->par).assign(this->size,0);
            (this->rank).assign(this->size,0);
            iota(all(this->par),0);
        }

        int findSet(int u){
            return (par[u] == u) ? u: (par[u] = findSet(par[u]));
        }
        
        int isSamSet(int u,int v){
            return (findSet(u) == findSet(v)) ? 1: 0;
        }

        void unionSet(int u,int v){
            if (isSamSet(u,v) == 1) return;
            int U = findSet(u);
            int V = findSet(v);
            if (rank[U] > rank[V]) par[V] = U;
            else {
                par[U] = V;
                if (rank[U] == rank[V]) rank[V]++;
            }
        }

};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    UnionFind UniSet(Maxn);
    int T;
    cin >> T;
    while (T--){
        int x, y, z;
        cin >> x >> y >> z;
        x--; y--;
        if (z == 2) cout << UniSet.isSamSet(x,y) << '\n';
        else UniSet.unionSet(x,y);
    }


    return 0;
}
