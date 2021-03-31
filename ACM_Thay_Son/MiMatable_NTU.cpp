// Cai cach 1 , 4 nut

/*    ####################  */
/*   # I_LOVE_THUY_LINH #  */
/*  ####################  */
#include <bits/stdc++.h>
#define ll long long
#define db double
#define ii pair<int,int>
#define pb push_back
#define vi vector<int>
#define fir first
#define sec second
#define all(s) s.begin(),s.end()
#define uni(a) (a).erase(unique(all(a)),(a).end())
#define sz(a) int((a).size())
#define ms(s,val) memset(s,val,sizeof(s))
#define bitcount(n) __builtin_popcountll(n)
#define prec(n) fixed<<setprecision(n)
#define sqr(x) (ll)(x)*(ll)(x)
#define lcm(a,b) ((ll)a/__gcd((ll)a,(ll)b)*(ll)(b))
#define gcd(a,b) __gcd(a,b)
#define oo (ll)(2e9)
#define N 1111
using namespace std;
struct Node{
    ll Min;
    ll Max;
    Node(){}
    Node(ll Mi,ll Ma ):Min(Mi),Max(Ma){}
} ST[4*N*N];
ll a[N][N];
int n , q;

inline void build(int id,int lx ,int rx , int ly,int ry){
    if ( lx > rx || ly > ry) return;
    if ( lx == rx && ly == ry){
        ST[id].Max = ST[id].Min = a[lx][ly];
        return;
    }
    int mx = (lx+rx) >> 1;
    int my = (ly+ry) >> 1;
    build(4*id-2,lx,mx,ly,my);
    build(4*id-1,mx+1,rx,ly,my);
    build(4*id,lx,mx,my+1,ry);
    build(4*id+1,mx+1,rx,my+1,ry);
    //ST[id] = Node(oo,-oo);
    ST[id].Min = min(min(ST[4*id-2].Min, ST[4*id-1].Min), min(ST[4*id].Min,ST[4*id+1].Min));
    ST[id].Max = max(max(ST[4*id-2].Max, ST[4*id-1].Max), max(ST[4*id].Max,ST[4*id+1].Max));
}

inline void update(int id ,int lx,int rx,int ly,int ry,int x, int y,ll val){
    if (x < lx || x > rx || y < ly || y > ry || lx > rx || ly > ry) return;
    if ( lx == x && rx == x && ly == y && ry == y){
        ST[id].Max = ST[id].Min = val;
        return;
    }

    int mx = (lx+rx) >> 1;
    int my = (ly+ry) >> 1;
    update(4*id-2,lx,mx,ly,my,x,y,val);
    update(4*id-1,mx+1,rx,ly,my,x,y,val);
    update(4*id,lx,mx,my+1,ry,x,y,val);
    update(4*id+1,mx+1,rx,my+1,ry,x,y,val);
    ST[id].Min = min(min(ST[4*id-2].Min, ST[4*id-1].Min), min(ST[4*id].Min,ST[4*id+1].Min));
    ST[id].Max = max(max(ST[4*id-2].Max, ST[4*id-1].Max), max(ST[4*id].Max,ST[4*id+1].Max));
}

inline Node Get(int id,int lx,int rx,int ly,int ry,int u1,int v1,int u2,int v2){
    if (u1 > rx || u2 < lx || v1 > ry || v2 < ly || lx > rx || ly > ry) return Node(oo,-oo);
    if (lx >= u1 && rx <= u2 && ly >= v1 && ry <= v2) return ST[id];
    int mx = (lx+rx) >> 1;
    int my = (ly+ry) >> 1;
    Node res1 = Get(4*id-2,lx,mx,ly,my,u1,v1,u2,v2);
    Node res2 = Get(4*id-1,mx+1,rx,ly,my,u1,v1,u2,v2);
    Node res3 = Get(4*id,lx,mx,my+1,ry,u1,v1,u2,v2);
    Node res4 = Get(4*id+1,mx+1,rx,my+1,ry,u1,v1,u2,v2);
    ll tmp1 = min(min(res1.Min,res2.Min),min(res3.Min,res4.Min));
    ll tmp2 = max(max(res1.Max,res2.Max),max(res3.Max,res4.Max));
    return Node(tmp1,tmp2);
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) cin >> a[i][j];

    for (int i = 1; i < 4*N*N; i++) ST[i] = Node(oo,-oo);
    build(1,1,n,1,n);
    cin >> q;
    while (q--){
        char c;
        cin >> c;
        if (c == 'c'){
            int x,y;
            ll val;
            cin >> x >> y >> val;
            update(1,1,n,1,n,x,y,val);
        }
        else {
            int u1,v1,u2,v2;
            cin >> u1 >> v1 >> u2 >> v2;
            Node ans = Get(1,1,n,1,n,u1,v1,u2,v2);
            cout << ans.Max <<' ' << ans.Min << '\n';
        }
    }


    return 0;
}
