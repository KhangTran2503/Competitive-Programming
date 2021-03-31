/*    ####################  */
/*   # I_LOVE_THUY_LINH #  */
/*  ####################  */
#include <bits/stdc++.h>
#define ll long long
#define db double
#define ld long double
#define ii pair<int,int>
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define vii vector<ii>
#define matrix vector<vector<ll>>
#define fir first
#define sec second
#define all(s) s.begin(),s.end()
#define rall(s) s.rbegin(),s.rend()
#define uni(a) (a).erase(unique(all(a)),(a).end())
#define sz(a) int((a).size())
#define ms(s,val) memset(s,val,sizeof(s))
#define bitcount(n) __builtin_popcountll(n)
#define getbit(s,k) ((s >> k)&1)
#define turnbit(s,k) (s | (1<<k))
#define offbit(s,k) (s & ~(1<<k))
#define flipbit(s,k) (s ^ (1<<k))
#define prec(n) fixed<<setprecision(n)
#define sqr(x) (ll)(x)*(ll)(x)
#define lcm(a,b) ((ll)a/__gcd((ll)a,(ll)b)*(ll)(b))
#define gcd(a,b) __gcd(a,b)
using namespace std;
const int INF = int(1e9);
int n, q;
vector<int> seg;

void update(int id,int l,int r,int pos,int val){
    if (pos < l || pos > r ) return;
    if (l == r){
        seg[id] = val;
        return;
    }
    int mid = (l + r) >> 1;
    update((id << 1), l, mid, pos, val);
    update((id << 1) | 1,mid + 1,r,pos,val);
    seg[id] = gcd(seg[id << 1],seg[(id << 1)|1]);
}

int get(int id,int l,int r,int u,int v,int x){
    if (r < u || l > v) return 0;
    if (u <= l && r <= v){
        if (seg[id] % x == 0) return 0;
        else {
            if (l == r) return 1;
            else {
                if (seg[id << 1] % x != 0 && seg[(id << 1) | 1] % x != 0) return 2;
                int mid = (l + r) >> 1;
                if (seg[id << 1] % x != 0) return get(id << 1,l,mid,u,v,x);
                else return get((id << 1) | 1,mid + 1,r,u,v,x);
            }
        }
    }
    int mid = (l + r) >> 1;
    int lef = get(id << 1,l, mid,u,v,x);
    if (lef >= 2) return 2;
    int rig = get((id << 1)| 1,mid + 1,r,u,v,x);
    if (rig >= 2) return 2;
    return lef + rig;

}


int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    seg.resize(4*n + 5);
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        update(1,1,n,i + 1,x);
    }

    cin >> q;
    while (q--){
        int c;
        cin >> c;
        if (c == 1){
            int l,r, x;
            cin >> l >> r >> x;
            int ans = get(1,1,n,l,r,x);
            if (ans >= 2) cout << "NO\n";
            else cout << "YES\n";
        }
        else {
            int i, y;
            cin >> i >> y;
            update(1,1,n,i,y);
        }
    }

    return 0;
}