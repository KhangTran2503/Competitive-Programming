//Use queue
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
int n, D, A;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> D >> A;
    vector<ll> delta(n + 1);
    vector<ii> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].fir >> a[i].sec;
    sort(all(a));
    ll ans = 0;
    int rig = 0;
    D *= 2;
    for (int i = 0; i < n; i++){
        while (rig < n && a[rig].fir <= a[i].fir + D) rig++;
        //cout << i << ' ' << rig << ' ';
        if (i) delta[i] += delta[i - 1];
        ll h = a[i].sec - delta[i];
        //cout << sum << '\n';
        if (h <= 0) continue;
        ll need = (h + A - 1)/A;
        ans += need;
        delta[i] += need*(ll)(A);
        delta[rig] -= need*(ll)(A);
    }

    cout << ans;
    return 0;
}