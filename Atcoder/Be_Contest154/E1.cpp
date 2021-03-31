// dp bottom up
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
string s;
int K;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> s;
    cin >> K;

    vector<vector<ll>> dp(K + 1,vector<ll> (2));
    dp[0][0] = 1;
    for (int i = 0; i < s.size(); i++){
        vector<vector<ll>> newdp(K + 1,vector<ll> (2));
        for (int nonzero = 0; nonzero <= K; nonzero++)
            for (bool low : {false,true})
                for (int dg = 0; dg < 10; dg++){
                    int newnonzero = nonzero + (dg != 0);
                    if ((dg > s[i] - '0' && !low)) break;
                    if (newnonzero > K) continue;
                    newdp[newnonzero][low || (dg < s[i] - '0')] += dp[nonzero][low];
                }
        dp = newdp;
    }

    ll ans = dp[K][0] + dp[K][1];
    cout << ans;
    return 0;
}