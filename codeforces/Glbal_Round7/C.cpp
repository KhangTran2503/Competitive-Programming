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
const ll Mod = (ll)(998244353); 
int n, k;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    vector<ii> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i].fir;
        a[i].sec = i;
    }
    sort(rall(a));
    ll sum = 0;
    for (int i = 0; i < k; i++) sum += (ll)a[i].fir;
    sort(a.begin(),a.begin() + k,[](ii u,ii v){return u.sec < v.sec;});
    ll cnt = 1;
    for (int i = 1; i < k; i++)
        cnt = (cnt*(ll)(a[i].sec - a[i - 1].sec)) % Mod;
    cout << sum << ' ' << cnt;
    return 0;
}