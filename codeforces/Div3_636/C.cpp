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

void solve(){
    int n;
    cin >> n;
    vector<ll> a(n);
    for (ll &x: a) cin >> x;
    int lef1 = 0;
    
    while (lef1 < n && a[lef1] < 0) lef1++;
    int len1 = 0;
    ll sum1 = 0;
    int sign = 1;
    while (lef1 < n){
        int rig1 = lef1;
        ll tmp = -INF;
        while (rig1 < n && a[rig1]*sign > 0){
            tmp = max(tmp,a[rig1]);
            rig1++;
        }
        len1++;
        sum1 += (ll)(tmp);
        sign = -sign;
        lef1 = rig1;
    }

    int lef2 = 0;
    while (lef2 < n && a[lef2] > 0) lef2++;
    int len2 = 0;
    ll sum2 = 0;
    sign = -1;
    while (lef2 < n){
        int rig2 = lef2;
        ll tmp = -INF;
        while (rig2 < n && a[rig2]*sign > 0){
            tmp = max(tmp,a[rig2]);
            rig2++;
        }
        len2++;
        sum2 += (ll)(tmp);
        sign = -sign;
        lef2 = rig2;
    }

    if (len1 > len2) cout << sum1 << '\n';
    else if (len1 < len2) cout << sum2 << '\n';
    else cout << max(sum1,sum2) << '\n';

}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}