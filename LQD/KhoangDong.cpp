#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
int n;

struct FenwickTree{
    private:
        int size_tree;
        vector<int> tree;

    public:    
        FenwickTree(int size){
            size_tree = size;
            tree.resize(size_tree + 1);
        };

        int get(int id){
            int sum = 0;
            for (; id > 0; id -= (id & -id)) sum += tree[id];
            return sum;
        };

        void update(int id,int delta){
            for (; id <= size_tree; id += (id & -id)) tree[id] += delta;
        }; 
};



int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    
    vector<ii> seg(n);
    vector<int> zip;
    for (int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        seg[i] = {y,x};
        zip.emplace_back(x);
        zip.emplace_back(y);
    }

    // compress array
    sort(all(zip));
    uni(zip);

    sort(all(seg));
    ll ans = 0;

    FenwickTree bit(2*n + 10);
    for (int i = 0; i < n; i++){
        int l = upper_bound(all(zip),seg[i].second) - zip.begin();
        int r = upper_bound(all(zip),seg[i].first) - zip.begin();
        ans += (ll)bit.get(l - 1);
        bit.update(r,1);
    }

    cout << ans;
    return 0;
}
