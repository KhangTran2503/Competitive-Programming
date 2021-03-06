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
int n;

// dp[i][j] la do dai day dai nhat co phan tu cuoi la i, va j 
// do dai day ko qua (j - i - 1)

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    vector<int> a(n);
    for (int &i: a) cin >> i;
    vector<vector<int>> dp(n, vector<int> (n));

    int ans = 0;
    for (int i = 1; i < n; i++)
        for (int j = i + 2; j < n; j++){
            if (a[i] - a[i - 1] == a[j] - a[j - 1]){
                dp[i][j] = min(dp[i - 1][j - 1] + 1,j - i - 1);
                ans = max(ans,dp[i][j]);
            }
        }
    ans++;
    if (ans >= 5) cout << ans;
    else cout << 0;
    return 0;
}