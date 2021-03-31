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
int H, n;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> H >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

    int maxA = *max_element(all(a));
    vector<int> dp(H + maxA + 1,INF);

    dp[0] = 0;
    for (int i = 0; i < n; i++)
        for (int j = a[i]; j <= H + maxA; j++)
            dp[j] = min(dp[j],dp[j - a[i]] + b[i]);
    
    int ans = INF;
    for (int i = H; i <= H + maxA; i++)
        ans = min(ans,dp[i]);
    cout << ans;
    return 0;
}