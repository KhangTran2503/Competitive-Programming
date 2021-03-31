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
const ll Mod = 998244353;
int N, S;

// dp[i][s] la so luong subset ket thuc tai i va tong la s
// dp[i][s] = sum dp[j][s - ai] (j < i)
// dat sumdp[i][j] = dp[i][j] + sumdp[i - 1][j]
// => dp[i][s] = sumdp[i - 1][s - a[i]]
//  voi dp[i][s] => thi dp[i][s] nam trong (N - i + 1) day


// https://atcoder.jp/contests/abc159/tasks/abc159_f
// Model dynamic programing 

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> S;
    vector<int> a(N + 1);
    for (int i = 1; i <= N; i++) cin >> a[i];

    vector<vector<ll>> dp(N + 1,vector<ll> (S + 1));
    vector<vector<ll>> sumdp(N + 1,vector<ll> (S + 1));
    for (int i = 0; i <= N; i++) dp[i][0] = 1;

    sumdp[0][0] = 1;
    for (int i = 1; i <= N; i++){
        for (int j = 0; j <= S; j++){
            if (j >= a[i]) dp[i][j] = sumdp[i - 1][j - a[i]];
            sumdp[i][j] = (sumdp[i - 1][j] + dp[i][j]) % Mod;
        }
    }

    ll ans = 0;
    for (int i = 1; i <= N; i++) ans = (ans + (ll)(N - i + 1)*dp[i][S])  % Mod;
    cout << ans;
    return 0;
}