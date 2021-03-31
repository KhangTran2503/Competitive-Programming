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
vector<int> a,zip;
int n, k, m;

struct Fenwick {
    int n;
    vector<int> f;
    Fenwick(int n): n(n), f(n+1, 0) {}
    void set(int x, int i) {
        for (; i<=n; i += i&(-i)) f[i] = max(f[i], x);
    }
    int get(int i) const {
        int r = 0;
        for (; i>=1; i -= i&(-i)) r = max(r, f[i]);
        return r;
    }
};


bool check(int x){
    Fenwick bit(m);
    int maxlen = 0;
    for (int i = 1; i <= n; i++){
        if (a[i] > x) continue;
        int w = upper_bound(all(zip),x - a[i]) - zip.begin() - 1;
        int id = lower_bound(all(zip),a[i]) - zip.begin();
        
        if (a[i] + zip[w] > x) continue;
        int len = bit.get(w) + 1;
        maxlen = max(maxlen,len);
        bit.set(len,id);
    }
    return (maxlen >= k);
    
}


int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    
    zip = a;
    sort(all(zip));
    uni(zip);

    m = zip.size();

    rotate(a.begin() + 1,min_element(a.begin() + 1,a.end()),a.end());

    ll lef = 1, rig = (ll)(2*INF);
    ll ans = INF;
    while (lef <= rig){
        ll mid = (lef + rig) >> 1;
        if (check(mid)){
            ans = mid;
            rig = mid - 1;
        }
        else lef = mid + 1;
    }
    cout << ans;
    return 0;
}