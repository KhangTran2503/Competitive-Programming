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

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    vector<vector<pair<ll,ll>>> dp(n,vector<pair<ll,ll>> (n,{-INF,-INF}));
    vi a(n);
    for (int &ai: a) cin >> ai;

    for (int L = n - 1; L >= 0; L--)
        for (int R = L; R < n; R++)
            if (L == R) dp[L][R] = {a[L],0};
            else {
                if (dp[L + 1][R].sec + a[L] > dp[L][R].fir) dp[L][R] = {dp[L + 1][R].sec + a[L],dp[L + 1][R].fir};
                if (dp[L][R - 1].sec + a[R] > dp[L][R].fir) dp[L][R] = {dp[L][R - 1].sec + a[R],dp[L][R - 1].fir};
            } 
    cout << dp[0][n - 1].fir;
    return 0;
}