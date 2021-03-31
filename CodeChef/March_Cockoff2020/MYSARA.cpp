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
const ll Mod = int(1e9) + 7;

ll calc(int x,int y){
    ll ans = 1;
    for (int i = 0; i < 30; i++)
        if (getbit(x,i) == 1){
            if (getbit(y,i) == 1) ans = (ans*2) % Mod;
        }
        else {
            if (getbit(y,i) == 1) return 0;
        }
    return ans;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> b(n);
        for (int &x: b) cin >> x;
        ll ans = 1;
        for (int i = 1; i < n; i++)
            ans = (ans*calc(b[i],b[i - 1])) % Mod;
        cout << ans << '\n';
    }
    return 0;
}