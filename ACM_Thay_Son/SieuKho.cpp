/*    ####################  */
/*   # I_LOVE_THUY_LINH #  */
/*  ####################  */
#include <bits/stdc++.h>
#define ll long long
#define db double
#define ld long double
#define ii pair<int,int>
#define pb push_back
#define vi vector<int>
#define vii vector<ii>
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
#define oo (ll)(1e17)
#define N int(1e5)+5
using namespace std;
const db Pi = acos(-1);
ll a[N] = {0};
typedef pair<ii,int> iii;
int n,m;
iii query[N];
struct Node{
    ll Max,lazy;
    Node(){};
    Node(ll Ma,ll lz): Max(Ma),lazy(lz){}
};
Node ST[4*N];

void build(int id,int l,int r){
    if (l == r){
        ST[id].Max = a[l];
        return;
    }
    int mid = (l+r) >> 1;
    build(2*id,l,mid);
    build(2*id + 1,mid+1,r);
    ST[id].Max = max(ST[2*id].Max,ST[2*id+1].Max);
}

void down(int id,int l,int r){
    if (ST[id].lazy != 0){
        ST[id].Max += ST[id].lazy;
        if (l != r){
            ST[2*id].lazy += ST[id].lazy;
            ST[2*id+1].lazy += ST[id].lazy;
        }
        ST[id].lazy = 0;
    }
}

void update(int id,int l,int r,int u,int v,int val){
    down(id,l,r);
    if (l > r || r < u || l > v) return;
    if (u <= l && r <= v){
        ST[id].lazy = val;
        down(id,l,r);
        return;
    }
    int mid = (l+r) >> 1;
    update(2*id,l,mid,u,v,val);
    update(2*id+1,mid+1,r,u,v,val);
    ST[id].Max = max(ST[2*id].Max,ST[2*id+1].Max);
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        ll l, r , d;
        cin >> l >> r >> d;
        a[l] += (ll)d;
        a[r+1] -= (ll)d;
        query[i].fir.fir = l;
        query[i].fir.sec = r;
        query[i].sec = d;
    }
    for (int i = 1; i <= n; i++) a[i] += a[i-1];
    build(1,1,n);
    ll res = oo;
    for (int i = 1; i <= m; i++){
        update(1,1,n,query[i].fir.fir,query[i].fir.sec,-query[i].sec);
        res = min (res,ST[1].Max);
        update(1,1,n,query[i].fir.fir,query[i].fir.sec,query[i].sec);
    }
    cout << res;
    return 0;
}
