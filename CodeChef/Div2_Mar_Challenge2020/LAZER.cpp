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

// use sweepline algorithm

struct Fenwick{
    vector<int> bit;
    int szbit;
    Fenwick(int n){
        szbit = n;
        bit.resize(szbit + 1);
    }
    
    ll get(int id){
        ll ans = 0;
        for (; id > 0; id -= (id & -id))
            ans += (ll)bit[id];
        return ans;
    }

    void update(int id,int val = 1){
        for (; id <= szbit; id += (id & -id)) bit[id] += val;
    }

    ~Fenwick(){}

};

struct  event{
    int time, id, point;
    event(){}
    event(int _point,int _time,int _id): point(_point), time(_time), id(_id) {}

    bool operator<(const event& other) const {
        return make_pair(point,time) < make_pair(other.point,other.time);
    }
    ~event(){}
};

struct query{
    int l,r, id;
    query(){}
    query(int _l,int _r,int _id): l(_l), r(_r), id(_id){}
    ~query(){}
};


void solve(){
    int n,q ;
    cin >> n >> q;

    vector<int> a(n);
    vector<event> e;
    

    for (int &ai: a) cin >> ai;

    // push event
    for (int i = 1; i < n; i++){
        e.pb(event(min(a[i],a[i - 1]),-1,i));
        e.pb(event(max(a[i],a[i - 1]),1,i));
    }

    vector<query> Query(q);
    for (int i = 0; i < q; i++){
        int l, r, y;
        cin >> l >> r >> y;
        l--, r--;
        Query[i] = query(l,r,i);
        e.pb(event(y,0,i));
    }   

    sort(all(e));
    Fenwick fen(n);

    vector<int> ans(q);
    for (int i = 0; i < sz(e); i++){
        int id = e[i].id;
        if (e[i].time == -1) fen.update(id);
        else if (e[i].time == 1) fen.update(id,-1);
        else ans[id] = fen.get(Query[id].r) - fen.get(Query[id].l);
            
    }

    for (int x: ans) cout << x << '\n';

}


int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}