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

// d(i,j) = min | (xj - xi) + t(vj - vi)|
// => d(i,j) = |xi - xj| if xi <= xj and vi <= vj
//           = 0 else other 
// Use fenwickTree 


struct FenwickTree{
    vector<ll> bit;
    FenwickTree(int n){
        bit.resize(n + 1);
    }

    void update(int id,ll val = 1){
        int sz = bit.size();
        for (; id < sz; id += (id & -id)) bit[id] += val;
    }

    ll get(int id){
        ll res = 0;
        for (; id > 0; id -= (id & -id)) res += bit[id];
        return res;
    }
};


int n;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    vector<pair<ll,ll>> a(n);
    vector<ll> b;
    for (int i = 0; i < n; i++){
        cin >> a[i].sec;
        b.eb(a[i].sec);
    }

    for (int i = 0; i < n; i++) cin >> a[i].fir;
    sort(all(b));
    uni(b);
    FenwickTree Sum(b.size()), cnt(b.size());

    sort(all(a));

    ll ans = 0;
    for (int i = 0; i < n; i++){
        int idx = upper_bound(all(b),a[i].sec) - b.begin();  //all value distinct
        //int idx = i + 1;
        ll presum = Sum.get(idx - 1);
        ll precnt = cnt.get(idx - 1);
       // cout << presum << ' ' << precnt << '\n';
        ans += (precnt*a[i].sec - presum);
        Sum.update(idx,a[i].sec);
        cnt.update(idx);
    }
    cout << ans;






    return 0;
}