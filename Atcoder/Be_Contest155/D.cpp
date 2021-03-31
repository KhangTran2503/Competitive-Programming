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
const ll INF = (ll)(1e18);
int n;
ll K;
vector<ll> pos, neg;
ll numzero = 0;

ll Round(ll x,ll y){
    if (x > 0) return (x - 1LL)/y;
    x = -x;
    x++;
    return (x/y) + (x % y != 0);
    
}


ll f(ll x){
    //f(x) count number < x
    ll ans = 0;
    if (x == 0){
        ans = (ll)(pos.size())*(ll)(neg.size());
        return ans;
    }

    if (x > 0){ // find 
        ans = (ll)(pos.size() + neg.size())*(ll)numzero + numzero*(numzero - 1)/2 + (ll)(pos.size())*(ll)(neg.size());
        for (int i = 0; i < pos.size(); i++){
            ll q = Round(x,pos[i]);
            int cntpair = upper_bound(pos.begin() + i + 1,pos.end(),q)- (pos.begin() + i + 1);
            ans += (ll)cntpair;
        }

        for (int i = 0; i < neg.size(); i++){
            ll q = Round(x,neg[i]);
            int cntpair = upper_bound(neg.begin() + i + 1,neg.end(),q) - (neg.begin() + i + 1);
            ans += (ll)cntpair;
        }
        return ans;
    }
    // if x < 0
    for (int i = 0; i < pos.size(); i++){
        ll q = Round(x,pos[i]);
        int cntpair = neg.end() - lower_bound(all(neg),q);
        ans += (ll)cntpair;
    }
    return ans;


}


int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> K;
    for (int i = 0; i < n; i++){
        ll x;
        cin >> x;
        if (x > 0) pos.eb(x);
        if (x == 0) numzero++;
        if (x < 0) neg.eb(-x);
    }

    sort(all(pos));
    sort(all(neg));

    ll lef  = -INF, rig = INF;
    ll ans = -INF;
    while (lef <= rig){
        ll mid = (lef + rig) >> 1;
        ll cnt = f(mid);
        if (cnt < K){ // cnt < K // find min ans such that f(ans) < K
            ans = mid;
            lef = mid + 1;
        }
        else rig = mid - 1;
    }

    cout << ans << '\n';
    //for (int i = -20; i <= 25; i++) cout << f(i) << ' ';
    return 0;
}