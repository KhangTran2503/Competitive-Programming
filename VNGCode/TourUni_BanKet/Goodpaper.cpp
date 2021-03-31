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
const int Maxn = int(1e5);
vector<int> Tree(4*Maxn,-1);

void update(int id,int l,int r,int pos,int val){
    if (pos < l || pos > r) return;
    if (l == r){
        Tree[id] = max(Tree[id],val);
        return;
    }
    int mid = (l + r) >> 1;
    update(2*id,l,mid,pos,val);
    update(2*id + 1,mid + 1,r,pos,val);
    Tree[id] = max(Tree[2*id],Tree[2*id + 1]);
}

int get(int id,int l,int r,int u,int v){
    if (l > v || r < u) return -1;
    if (u <= l && r <= v) return Tree[id];
    int mid = (l + r) >> 1;
    return max(get(2*id,l,mid,u,v),get(2*id + 1,mid + 1,r,u,v));
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, K;
    cin >> n >> K;
    vector<ll> f(n + 1);
    vector<ll> zip; zip.eb(0);
    for (int i = 1; i <= n; i++){
        ll x;
        cin >> x;
        f[i] = f[i - 1] + x;
        zip.eb(f[i]);
    }
    
    sort(all(zip));
    uni(zip);
    int id = upper_bound(all(zip),0) - zip.begin();
    int m = sz(zip);
    update(1,1,m,id,0);
    
    int len = INF;
    for (int i = 1; i <= n; i++){
        //if (f[i] - K < zip[0]) continue;
        int id = upper_bound(all(zip),f[i] - K) - zip.begin();
        int id1 = upper_bound(all(zip),f[i]) - zip.begin();
        if (id > 0){
            int pos = get(1,1,m,1,id);
            if (pos != -1) len = min(len,i - pos);
        }    
        update(1,1,m,id1,i);
    }
    if (len != INF) cout << len;
    else cout << -1;
    return 0;
}